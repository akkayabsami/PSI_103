#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "target.h"
#include "Vector.h"
#include "AngularVector.h"

class agent2D {
public:

	float size = 5.0;
	float alpha = 0.80;

	Vector pos;
	AngularVector viewPoint; // Görüş noktası
	Vector moveDirection; // Hareket yönü


	Target* target;

	agent2D(Vector pos, Target* target) {

		this->pos = pos;
		std::cout << "Agent is on X: " << this->pos.getX() << ", Y: " << this->pos.getY() << std::endl;
		this->target = target;
		float viewPoint_angle = (float(rand()) / float((RAND_MAX)) * 60.0) - 30.0;
		this->viewPoint = AngularVector(viewPoint_angle);
		moveDirection = viewPoint.toVector().unitVector();
	};

	Vector perceive() {
		return target->getPos() - this->pos;
	}

	int move(Vector vector) {

		if ((vector.getX() + this->pos.getX() + this->size/2 < 100.0) && (vector.getX() + this->pos.getX() - this->size/2 > 0) && (vector.getY() + this->pos.getY() + this->size/2 < 200.0) && (vector.getY() + this->pos.getY() - this->size/2 > 0)) {
			
			Vector moveVector = vector.unitVector() * 2.0;
			this->pos.increaseX(moveVector.getX());
			this->pos.increaseY(moveVector.getY());
			std::cout << "X: " << this->pos.getX() << ", Y: " << this->pos.getY() << std::endl;
			return 1;
		}
		return 0;
	}

	int decide() {

		if (perceive().getLength() < 1.0) {
			std::cout << "Hedefe ulaşıldı!" << std::endl;
			return 0;
		}

		Vector distance = perceive();
		Vector v1 = distance.unitVector();
		Vector v2 = moveDirection;

		//V2 = moveDirection
		v1 = v2 * (1 - alpha) + v1 * alpha;

		if (!move(v1)) return 0;

		return 1;
	}




};