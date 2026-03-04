#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#include <vector>
#include "Particle.h"

class ParticleEngine {
   public:
    void push(Particle& particle);

   private:
    std::vector<Particle> particles;
};

#endif
