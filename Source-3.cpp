#include "Inventory.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Default constructor
Inventory::Inventory()
{
	itemNumber = 0;
	quantity = 0;
	cost = 0.0;
	totalCost = 0.0;
}

//Default overload constructor
Inventory::Inventory(int i, double c, int q)
{
	itemNumber = i;
	cost = c;
	quantity = q;
	setTotalCost();
}

//Sets item number and has input validation loop
void Inventory::setItemNumber(int i)
{
	while (i < 0) {
		cout << "This number can not accept negative values. Please enter a new value: ";
		cin >> i;
	}
	itemNumber = i;

}

//Sets item quantity and has input validation loop
void Inventory::setQuantity(int q)
{
	while (q < 0) {
		cout << "This number can not accept negative values. Please enter a new value: ";
		cin >> q;
	}
	quantity = q;

}

//Sets item cost and has input validation loop
void Inventory::setCost(double c)
{
	while (c < 0) {
		cout << "This number can not accept negative values. Please enter a new value: ";
		cin >> c;
	}
	cost = c;
}

//Calculates total cost
void Inventory::setTotalCost() 
{
	totalCost = quantity * cost;
}

