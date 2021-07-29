#include "Inventory.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//void setAmounts(Inventory);

//Sets amount in object via reference
void setAmounts(Inventory &x) {
	int num;
	double quantity;
	int cost;

	cout << "Enter the item number: ";
	cin >> num;
	x.setItemNumber(num);
	cout << endl;

	cout << "Enter the item quantity: ";
	cin >> quantity;
	x.setQuantity(quantity);
	cout << endl;

	cout << "Enter the item cost: ";
	cin >> cost;
	x.setCost(cost);
	cout << endl;

	x.setTotalCost();
};

//Displays amounts entered for object
void getAmounts(Inventory x) {

	cout << "The item number is " << x.getItemNumber() << endl;
	cout << "The item quantity is " << x.getQuantity() << endl;
	cout << "The item cost is $" << fixed << showpoint << setprecision(2) << x.getCost() << endl;
	cout << "The total cost of the item is $" << fixed << showpoint << setprecision(2) << x.getTotalCost() << endl;


}

//Creates objects
int main() {
	 
	//First object with overloaded function
	Inventory inv_1(10, 20.00, 10);
	cout << "Created an inventory object with predetermined amounts" << endl;
	getAmounts(inv_1);

	//Second object that prompts user to enter info
	Inventory inv_2;
	cout << "Created a second inventory object" << endl;
	setAmounts(inv_2);
	getAmounts(inv_2);


	return 0;
}