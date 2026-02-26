#include "PhysicsVector.h"
PhysicsVector::PhysicsVector(double in_x, double in_y) : x(in_x), y(in_y) {}

PhysicsVector PhysicsVector::operator+(const PhysicsVector& other) const {
    return PhysicsVector(x + other.x, y + other.y);
}

PhysicsVector PhysicsVector::operator-(const PhysicsVector& other) const {
    return PhysicsVector(x - other.x, y - other.y);
}

PhysicsVector PhysicsVector::operator*(double scalar) const {
    return PhysicsVector(x * scalar, y * scalar);
}

PhysicsVector& PhysicsVector::operator+=(const PhysicsVector& other) {
    x += other.x;
    y += other.y;
    return *this;
}

double PhysicsVector::getX() const {
    return x;
}
double PhysicsVector::getY() const {
    return y;
}
void PhysicsVector::setX(double newX) {
    x = newX;
}
void PhysicsVector::setY(double newY) {
    y = newY;
}
