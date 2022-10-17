#pragma once
#include <cmath>
#include "Vector.h"

class AngularVector : Vector {

private:

	float angle;

public:

	AngularVector() : Vector(0, 0) {

	}

	AngularVector(float angle) : Vector(0, 0) {
		this->angle = angle;
	}

	Vector toVector() {
		float x = sin(this->angle);
		float y = cos(this->angle);
		return Vector(x, y);
	}


};