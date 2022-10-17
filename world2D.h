#pragma once

#include <iostream>
#include "agent2D.h"

class world2D {

private:

	float x_size = 100;
	float y_size = 200;

	agent2D* agent;


public:

	world2D();

	void start();

	void startWithSamePos(float* alphas);

	void start(int trial, float alpha);




};
