#include "Emitter.h"
#include "Random.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

Emitter::Emitter(Vec3 _pos, size_t _numParticles) : m_position(_pos) {
    for(int i = 0; i < _numParticles; i++) {
        Particle p = Particle();
        p.pos = m_position;
        p.dir = (m_emitDir * (Random::randomPositiveFloat())) + ((Random::randomVectorOnSphere() * m_spread));
        p.dir.cy = std::abs(p.dir.cy);
        p.color =  Random::randomPositiveVec3();
        p.maxLife =  Random::randomPositiveFloat(5000)+500;
        p.life = 0;
        p.scale= 0.01f;

        m_particles.push_back(p);
    }
}

void Emitter::update(float _dt) {
    Vec3 gravity = Vec3(0.0f, -9.81f, 0.0f);
    for(Particle &p : m_particles) {
        p.dir = p.dir + (gravity * _dt * 0.5f);
        p.pos = p.pos + (p.dir * _dt);
        p.scale += Random::randomPositiveFloat(0.05);
        p.life += 1;
        if(p.life >= p.maxLife) { // TODO: is this correct for "or hit ground plane"
            std::cout << "reset\n";
            resetParticle(p);
        }
    }
}

void Emitter::resetParticle(Particle &_p)
{
    _p.pos = m_position;
    _p.dir = (m_emitDir * (Random::randomPositiveFloat())) + ((Random::randomVectorOnSphere() * m_spread));
    _p.scale= 0.01f;
    _p.life = 0;
    _p.maxLife =  Random::randomPositiveFloat(5000)+500;
}

void Emitter::draw(const std::string &_fileName) const
{
    std::ofstream file(_fileName);
    if(!file.is_open())
    {
        std::cerr << "could not open " << _fileName << '\n';
        return;
    }

    const size_t n = m_particles.size();

    file << "PGEOMETRY V5\n";
    file << "NPoints " << n << " NPrims 1\n";
    file << "NPointGroups 0 NPrimGroups 0\n";
    file << "NPointAttrib 2 NVertexAttrib 0 NPrimAttrib 1 NAttrib 0\n";
    file << "PointAttrib\n";
    file << "Cd 3 float 1 1 1\n";
    file << "pscale 1 float 1\n";

    for(const Particle &p : m_particles)
    {
        file << p.pos.cx << ' ' << p.pos.cy << ' ' << p.pos.cz << " 1 ("
             << p.color.cx << ' ' << p.color.cy << ' ' << p.color.cz << ' '
             << p.scale << ")\n";
    }

    file << "PrimitiveAttrib\n";
    file << "generator 1 index 1 papi\n";
    file << "Part " << n;
    for(size_t i = 0; i < n; ++i)
    {
        file << ' ' << i;
    }
    file << " [0]\n";

    file << "beginExtra\n";
    file << "endExtra\n";
}