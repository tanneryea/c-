#include <iostream>
#include "Circle.h"
using namespace std;

//Calculates area via override virtual function
double Circle::calcArea() {
	double area;
	
	area = PI * radius * radius;
	return area;
}

//Prompts user to enter values into private members of class
void Circle::inputDimensions() {
	cout << "Enter the X coordinate of the circle's center: ";
	cin >> centerX;
	cout << endl;
	
	cout << "Enter the Y coordinate of the circle's center: ";
	cin >> centerY;
	cout << endl;
	
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	cout << endl;
}