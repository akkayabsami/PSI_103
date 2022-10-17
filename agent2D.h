#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "target.h"
#include "Vector.h"
#include "AngularVector.h"

class agent2D {
public:

	int step = 1;
	int trial = 0;

	float size = 5.0;
	float alpha = 0.80;

	Vector pos;
	AngularVector viewPoint; // Görüş noktası
	Vector moveDirection; // Hareket yönü

	Target* target;

	std::fstream MyFile;

	agent2D(Vector pos, Target* target, float alpha) {

		std::ostringstream ss;
		ss << alpha;
		MyFile.open("Report_" + ss.str() + ".txt", std::fstream::out);

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
			this->MyFile << step << "\t: " << "Agent is located at X:" << this->pos.getX() << ", Y:" << this->pos.getY() << std::endl;
			step++;
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

	void setPos(Vector vector) {
		std::cout << "Agent is located at X:" << this->pos.getX() << ", Y:" << this->pos.getY() << std::endl;
		this->pos = vector;
	}

	void setTarget(Target* target) {
		delete(this->target);
		this->target = target;
	}

	void openFileAtAppendMode() {
		this->MyFile.open("Report.txt", std::fstream::app);
	}

	void closeFile() {
		this->MyFile.close();
	}

};