#include "Particle.h"

#include <iostream>

Particle::Particle(double m, double q, const PhysicsVector& pos) : mass(m), charge(q), position(pos), velocity(0, 0), force(0, 0) {}

PhysicsVector Particle::getPosition() {
    return position;
}

PhysicsVector Particle::getVelocity() {
    return velocity;
}

double Particle::getMass() {
    return mass;
}

void Particle::applyForce(PhysicsVector newForce) {
    force += newForce;
}

void Particle::update(double dt, int windowWidth, int windowHeight) {
    PhysicsVector acceleration = force * (1.0 / mass);
    velocity += acceleration * dt;
    // make sure the particle doesnt go off the page
    if (position.getX() <= 1 || position.getX() >= windowWidth - 1) {
        velocity.setX(-(velocity.getX() * bounceFactor));
    }
    if (position.getY() <= 1 || position.getY() >= windowHeight - 1) {
        // this makes it bounce off the surface
        velocity.setY(-(velocity.getY() * bounceFactor));
        if (velocity.getX() < 0.04 && velocity.getX() > -0.04) {
            velocity.setX(1);
        }
    }
    position += velocity * dt;
    std::cout << position << std::endl;
    force = PhysicsVector();
}
