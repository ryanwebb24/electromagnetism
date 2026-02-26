#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#include <vector>

#include "Particle.h"

enum class Quadrant {
    TL,
    BL,
    TR,
    BR
};

class ParticleEngine {
   public:
    void pushToQuad(Particle& particle, Quadrant quad);

   private:
    std::vector<Particle> particleQuadTL;
    std::vector<Particle> particleQuadBL;
    std::vector<Particle> particleQuadTR;
    std::vector<Particle> particleQuadBR;
};

#endif