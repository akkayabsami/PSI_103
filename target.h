#pragma once
#include <iostream>
#include "Vector.h"

class Target {

private:

	float x = 100;
	float y = 100;

public:

	Target() {
		this->x = 5;
		this->y = (float(rand()) / float((RAND_MAX)) * 30.0) + 35.0;
	}

	float getX() {
		return this->x;
	}

	float getY() {
		return this->y;
	}

	Vector getPos() {
		return Vector(getX(), getY());
	}


};