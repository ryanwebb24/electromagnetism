#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#include <SDL3/SDL.h>

#include <vector>

#include "Particle.h"

class ParticleEngine {
   public:
    void push(Particle& particle);
    void updateAll(double dt, int windowWidth, int windowHeight);
    void draw(SDL_Renderer* renderer);

   private:
    std::vector<Particle> particles;
};

#endif
