#include "ParticleEngine.h"

#include "Particle.h"

void ParticleEngine::push(Particle& particle) {
    particles.push_back(particle);
}

void ParticleEngine::updateAll(double dt, int windowWidth, int windowHeight) {
    for (Particle& particle : particles) {
        particle.update(dt, windowWidth, windowHeight);
    }
}

void ParticleEngine::draw(SDL_Renderer* renderer) {
    for (Particle& particle : particles) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_FRect rect;
        rect.x = static_cast<int>(particle.getPosition().getX());
        rect.y = static_cast<int>(particle.getPosition().getY());
        rect.w = 5;
        rect.h = 5;
        SDL_RenderFillRect(renderer, &rect);
    }
}
