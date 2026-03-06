#ifndef PARTICLE_H
#define PARTICLE_H

#include "PhysicsVector.h"
#include "Quadrant.h"

class Particle {
   public:
    Particle(const PhysicsVector& pos = PhysicsVector(), double mass = 1.0, double charge = 1.0);
    PhysicsVector getPosition();
    PhysicsVector getVelocity();
    void update(double dt, int windowWidth, int windowHeight);
    void applyForce(PhysicsVector newForce);
    double getMass();

   private:
    PhysicsVector position;
    PhysicsVector velocity;
    PhysicsVector force;
    double charge;
    double mass;
    double bounceFactor = 0.7;
};

#endif
