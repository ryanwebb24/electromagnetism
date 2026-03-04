#include "ParticleEngine.h"
#include "Particle.h"

void ParticleEngine::pushToQuad(Particle& particle, Quadrant quad) {
    particle.setQuad(quad);
    switch (quad) {
        case Quadrant::BL:
            particleQuadBL.push_back(particle);
            break;
        case Quadrant::TL:
            particleQuadTL.push_back(particle);
            break;
        case Quadrant::BR:
            particleQuadBR.push_back(particle);
            break;
        case Quadrant::TR:
            particleQuadTR.push_back(particle);
            break;

        default:
            break;
    }
}
