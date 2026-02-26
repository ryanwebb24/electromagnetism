#ifndef PHYSICS_VECTOR_H
#define PHYSICS_VECTOR_H

#include <iostream>

class PhysicsVector {
   public:
    PhysicsVector(double in_x = 0, double in_y = 0);
    // Operator declarations
    PhysicsVector operator+(const PhysicsVector& other) const;
    PhysicsVector operator-(const PhysicsVector& other) const;
    PhysicsVector operator*(double scalar) const;
    PhysicsVector& operator+=(const PhysicsVector& other);

    PhysicsVector xComponent() {
        return PhysicsVector(x, 0);
    }
    PhysicsVector yComponent() {
        return PhysicsVector(0, y);
    }

    double getX() const;
    double getY() const;
    void setY(double newY);
    void setX(double newX);

   private:
    double x;
    double y;

    friend std::ostream& operator<<(std::ostream& os, const PhysicsVector& vector) {
        return os << "(" << vector.getX() << "," << vector.getY() << ")";
    }
};

#endif