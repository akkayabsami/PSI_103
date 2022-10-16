#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
}

Vector::Vector(float x, float y) {
    this->x = x;
    this->y = y;
}

float Vector::getX() {
    return this->x;
}
float Vector::getY() {
    return this->y;
}

float Vector::getLength() {
    return sqrt(pow(getX(), 2) + pow(getY(), 2));
}

void Vector::setX(float x) {
    this->x = x;
}
void Vector::setY(float y) {
    this->y = y;
}

void Vector::increaseX(float inc) {
    this->x = this->x + inc;
}

void Vector::increaseY(float inc) {
    this->y = this->y + inc;
}

Vector Vector::unitVector() {
    return Vector(getX() / getLength(), getY() / getLength());
}

Vector operator+(Vector const& vec1, Vector const& vec2) {
    return Vector(vec1.x + vec2.x, vec1.y + vec2.y);
}

Vector operator-(Vector const& vec1, Vector const& vec2) {
    return Vector(vec1.x - vec2.x, vec1.y - vec2.y);
}

Vector operator*(Vector const& vec1, float const& scaler) {
    return Vector(vec1.x * scaler, vec1.y * scaler);
}

Vector operator/(Vector const& vec1, float const& scaler) {
    return Vector(vec1.x / scaler, vec1.y / scaler);
}