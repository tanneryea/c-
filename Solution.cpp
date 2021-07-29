#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;


void Calculations(int, int, double);

void Calculations(int SpoolsOrdered, int SpoolsStock, double HandlingCharge = 10.00) {
	//Variables for function	
	int totalOrder = SpoolsStock - SpoolsOrdered;
	int ReadyToShip;
	int backorder;
	ofstream ReceiptFile("spoolreceipt.txt");

	//If-else statement to determine if there is backorder
	if (totalOrder < 0) {
		ReadyToShip = SpoolsStock;
		backorder = totalOrder * -1;
	} else {
		ReadyToShip = SpoolsOrdered;
		backorder = 0;
	}

	//Calculations
	double subtotal = ReadyToShip * 100.00;
	double shippingCost = ReadyToShip * HandlingCharge;
	double finalTotal = subtotal + shippingCost;

	//Output of calculation results
	cout << "Order Summary" << endl;
	cout << "=====================" << endl << endl;

	cout << "Items ordered: " << SpoolsOrdered << endl;
	cout << "Ready to ship: " << ReadyToShip << endl;
	cout << "On backorder: " << backorder << endl << endl;

	cout << "Subtotal: $" << subtotal << ".00" << endl;
	cout << "Shipping: $" << shippingCost << ".00" << endl;
	cout << "Total Due: $" << finalTotal << ".00" << endl;

	//Writes to file
	ReceiptFile << "Order Summary" << endl;
	ReceiptFile << "=====================" << endl << endl;

	ReceiptFile << "Items ordered: " << SpoolsOrdered << endl;
	ReceiptFile << "Ready to ship: " << ReadyToShip << endl;
	ReceiptFile << "On backorder: " << backorder << endl << endl;

	ReceiptFile << "Subtotal: $" << subtotal << ".00" << endl;
	ReceiptFile << "Shipping: $" << shippingCost << ".00" << endl;
	ReceiptFile << "Total Due: $" << finalTotal << ".00" << endl;

	ReceiptFile.close();
}



int main() {
	//Variables for function
	int SpoolsOrdered;
	int SpoolsStock;
	double HandlingCharge = 10;
	char confirm;

	//Inputs to pass to Calculation function, including validation loops
	cout << "How many spools are you ordering? ";
	cin >> SpoolsOrdered;
	while (SpoolsOrdered < 1) {
		cout << "You must order at least one spool. Enter a valid amount: ";
		cin >> SpoolsOrdered;
	}

	cout << "How many spools are in stock? ";
	cin >> SpoolsStock;
	while (SpoolsStock < 0) {
		cout << "You must have at least 0 spools in stock. Enter a valid amount: ";
		cin >> SpoolsStock;
	}

	//If-Statement for updating handling charge if necessary
	cout << "Is there a special handling charge? Y/N ";
	cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {
		cout << "Enter the special handling charge: ";
		cin >> HandlingCharge;
		while (HandlingCharge < 0) {
			cout << "The handling charge must be at least $0.00. Enter a valid amount: ";
			cin >> HandlingCharge;
		}
	}
	
	cout << endl;

	//Calculation function is called
	Calculations(SpoolsOrdered, SpoolsStock, HandlingCharge);

	return 0;
}