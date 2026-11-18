#include "Vec3.h"

class Particle {    
    public:
        // question - is it bad for these to be public? idrk
        Vec3 pos;
        Vec3 dir;
        Vec3 color;
        int life;
        int maxLife;
        float size;
        float scale;

        Particle();
        // Particle(Vec3 pos, Vec3 dir, Vec3 color, int life, float size);
};