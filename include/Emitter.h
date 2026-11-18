#include "Vec3.h"
#include "Particle.h"
#include <vector>

class Emitter {
    private:
        std::vector<Particle> m_particles;
        Vec3 m_position;
        float m_spread;
        Vec3 m_emitDir;

    public:


        Emitter(Vec3 _pos, size_t _numParticles);
        Emitter();

        void update(float _dt);
        void saveFrame(const std::string & _fname);
        void resetParticle(Particle &p);
        void draw(const std::string &_fileName) const;
};