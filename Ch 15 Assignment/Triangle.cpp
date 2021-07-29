#include <iostream>
#include "Triangle.h"
using namespace std;

const double half = 0.5;

//Calculates area via override virtual function
double Triangle::calcArea() {
	double area;

	area = half * base * height;
	return area;
}

//Prompts user to enter values into private members of class
void Triangle::inputDimensions() {
	cout << "Enter the base length of the triangle: ";
	cin >> base;
	cout << endl;

	cout << "Enter the height length of the triangle: ";
	cin >> height;
	cout << endl;

}