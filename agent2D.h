#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "target.h"
#include "Vector.h"
#include "AngularVector.h"

class agent2D {
public:

	float size = 5;
	float alpha = 0.80;

	Vector pos;
	AngularVector viewPoint;


	Target* target;

	agent2D(Vector pos, Target* target) {

		this->pos = pos;
		this->target = target;
		float viewPoint_x = (float(rand()) / float((RAND_MAX)) * 60.0) - 30.0;
		float viewPoint_y = (float(rand()) / float((RAND_MAX)) * 60.0) - 30.0;
		this->viewPoint = AngularVector(viewPoint_x, viewPoint_y);
	};

	Vector perceive() {
		return target->getPos() - this->pos;
	}

	int move(Vector vector) {

		if ((vector.getX() + this->pos.getX() <= 100.0) && (vector.getY() + this->pos.getY() <= 200.0)) {
			
			this->pos.increaseX(vector.getX());
			this->pos.increaseY(vector.getY());
			std::cout << "X: " << this->pos.getX() << ", Y: " << this->pos.getY() << std::endl;
		}
		std::cout << "X: " << this->pos.getX() << ", Y: " << this->pos.getY() << std::endl;
		std::cout << "X: " << (vector.getX() + this->pos.getX()) << ", Y: " << (vector.getY() + this->pos.getY()) << std::endl;
		return 0;
	}

	int decide() {

		if (perceive().getLength() < 1) {
			std::cout << "Hedefe ulaşıldı!" << std::endl;
			return 0;
		}

		Vector distance = perceive();
		Vector v1 = distance.unitVector();

		//Vector v2 =

		if (!move(Vector(1, -1))) return 0;

		return 1;
	}




};