#include <iostream>
#include "Rectangle.h"
using namespace std;

//Calculates area via override virtual function
double Rectangle::calcArea() {
	double area;

	area = length * width;
	return area;
}

//Prompts user to enter values into private members of class
void Rectangle::inputDimensions() {
	cout << "Enter the length of the rectangle: ";
	cin >> length;
	cout << endl;

	cout << "Enter the width of the rectangle: ";
	cin >> width;
	cout << endl;

}