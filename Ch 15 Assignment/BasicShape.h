#pragma once
#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape 
{
public:
	//Creates virtual functions, class becomes purely abstract
	virtual double calcArea() = 0;
	virtual void inputDimensions() = 0;

};



#endif