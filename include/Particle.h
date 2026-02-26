#ifndef PARTICLE_H
#define PARTICLE_H

#include "ParticleEngine.h"
#include "PhysicsVector.h"

class Particle {
   public:
    Particle(double mass, double charge, const PhysicsVector& pos = PhysicsVector());
    PhysicsVector getPosition();
    PhysicsVector getVelocity();
    void update(double dt, int windowWidth, int windowHeight);
    void applyForce(PhysicsVector newForce);
    double getMass();
    void setQuad(Quadrant quad);
    Quadrant getQuad();

   private:
    PhysicsVector position;
    PhysicsVector velocity;
    PhysicsVector force;
    double charge;
    double mass;
    double bounceFactor = 0.7;
    Quadrant currentQuad;
};

#endif