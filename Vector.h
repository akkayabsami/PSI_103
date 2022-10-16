#pragma once
#include <cmath>


class Vector {

    friend Vector operator+(Vector const& vec1, Vector const& vec2);

    friend Vector operator-(Vector const& vec1, Vector const& vec2);

    friend Vector operator*(Vector const& vec1, float const& scaler);

    friend Vector operator/(Vector const& vec1, float const& scaler);

private:
    float x;
    float y;

public:

    Vector();

    Vector(float x, float y);

    float getX();
    float getY();

    float getLength();

    void setX(float x);
    void setY(float y);

    void increaseX(float inc);

    void increaseY(float inc);

    Vector unitVector();

};