#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "BasicShape.h"

class Triangle : public BasicShape
{
private:
	int base;
	int height;

public:
	//Default constructor
	Triangle() {
		base = 0;
		height = 0;
	}

	//Overloaded constructor
	Triangle(int b, int h) {
		base = b;
		height = h;
	}

	//Returns base of triangle
	int getBase() {
		return base;
	}

	//Returns height of triangle
	int getHeight() {
		return height;
	}

	//Overload function
	virtual double calcArea();

	//Overload function
	virtual void inputDimensions();
};







#endif
