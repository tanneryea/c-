#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
	int width;
	int length;

public:
	//Default constructor
	Rectangle() {
		width = 0;
		length = 0;
	}

	//Overload constructor
	Rectangle(int leng, int widt) {
		width = widt;
		length = leng;
	}

	//Returns rectangle width
	int getWidth() {
		return width;
	}

	//Returns rectangle length
	int getLength() {
		return length;
	}

	//Overload function
	virtual double calcArea();

	//Overload function
	virtual void inputDimensions();
};

#endif