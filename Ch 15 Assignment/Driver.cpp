#include <iostream>
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main(){

	//Creates instances of each object
	cout << "Creating a triangle, rectangle and circle object..." << endl;
	Triangle tri1;
	Circle cir1;
	Rectangle rec1;
	cout << "Finished!" << endl;

	//Runs virtual input functions for each object
	tri1.inputDimensions();
	cir1.inputDimensions();
	rec1.inputDimensions();

	//Runs virtual area calculation functions for each object
	cout << "The area of the triangle is " << tri1.calcArea() << endl;
	cout << "The area of the circle is " << cir1.calcArea() << endl;
	cout << "The area of the rectangle is " << rec1.calcArea() << endl;

	cout << "Ending program...";

	return 0;

}