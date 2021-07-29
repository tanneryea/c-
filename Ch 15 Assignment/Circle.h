#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

//Constant value of pi for easy use
const double PI = 3.14159;

class Circle : public BasicShape
{
private:
	int centerX;
	int centerY;
	double radius;

public:
	//Default constructor
	Circle() {
		centerX = 0;
		centerY = 0;
		radius = 0;
	}

	//Overloaded constructor
	Circle(int center1, int center2, double rad) {
		centerX = center1;
		centerY = center2;
		radius = rad;
	}

	//Returns the x coordinate of the circle
	int getCenterX() {
		return centerX;
	}

	//Returns the y coordinate of the circle
	int getCenterY(){
		return centerY;
	}

	//Returns the radius of the circle
	double getRadius() {
		return radius;
	}

	//Override function
	virtual double calcArea();

	//Override function
	virtual void inputDimensions();
};

#endif