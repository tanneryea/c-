#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Creates soda structure
struct Soda
{
	string sodaType;
	double sodaPrice;
	int sodaStock;
};

//Populates soda structure with array
Soda sodaList[5] = {
	{"Cola", 0.75, 20},
	{"Root Beer", 0.75, 20},
	{"Lemon-Lime", 0.75, 20},
	{"Grape Soda", 0.80, 20},
	{"Cream Soda", 0.80, 20}
};

//Global variable for accumulation
double profit;

//Function prototypes
void vend(double, int &, double);
double acceptCash(string, double);

//Function returns change and deducts from stock on successful purchase
void vend(double price, int &stock, double cash) {

	profit += price;
	double change = cash - price;
	cout << "Your change is $" << fixed << showpoint << setprecision(2) << change << endl;
	stock--;
	cout << "The current stock left is " << stock << endl << endl;

};

//Function accepts cash and verifies correct amount is entered
double acceptCash(string soda, double price) {

	double cash;
	double moreCash;
	cout << "You chose " << soda << ". The price is $" << fixed << showpoint << setprecision(2) << price << endl;
	cout << "Insert cash: $";
	cin >> cash;

	while (cash < 0 || cash > 1) {
		cout << "You can not enter a negative amount or a value greater than $1.00. Please enter a new amount: $";
		cin >> cash;
	}

	//Prompts customer to insert more money if price isn't reached
	while (price > cash) {
		cout << "You did not insert enough money. You still owe $" << fixed << showpoint << setprecision(2) << price - cash << ". Please insert cash: $";
		cin >> moreCash;
		while (moreCash < 0 || moreCash > 1) {
			cout << "You can not enter a negative amount or a value greater than $1.00. Please enter a new amount: $";
			cin >> moreCash;
		}
		cash += moreCash;
	}

	return cash;
}

int main() {

	//Local variables
	int choice;
	double cash;

	//Constant variables for choice menu
	const int COLA = 1,
		ROOT_BEER = 2,
		LEMON_LIME = 3,
		GRAPE_SODA = 4,
		CREAM_SODA = 5;


	do {
		
		//Menu and choice loop
		cout << "\t\tWelcome to Thoisty Boi Vending!\n\n"
			<< "1. Cola\n"
			<< "2. Root Beer\n"
			<< "3. Lemon-Lime\n"
			<< "4. Grape Soda\n"
			<< "5. Cream Soda\n"
			<< "6. Exit Program\n"
			<< "Enter your choice: ";
		
		cin >> choice;

		while (choice < 1 || choice > 6) {
			cout << "Invalid entry. Please enter a valid drink choice or enter 0 to exit: ";
			cin >> choice;
		}

		//Switch table. Breaks if soda is out of stock
		switch (choice) {
			case COLA:
				if (sodaList[0].sodaStock == 0) {
					cout << "That selection is currently out of stock." << endl << endl;
					break;
				} else {
				cash = acceptCash(sodaList[0].sodaType, sodaList[0].sodaPrice);
				vend(sodaList[0].sodaPrice, sodaList[0].sodaStock, cash);
				break;
				}
			case ROOT_BEER: 
				if (sodaList[1].sodaStock == 0) {
					cout << "That selection is currently out of stock." << endl << endl;
					break;
				}
				else {
					cash = acceptCash(sodaList[1].sodaType, sodaList[1].sodaPrice);
					vend(sodaList[1].sodaPrice, sodaList[1].sodaStock, cash);
					break;
				}
			case LEMON_LIME:
				if (sodaList[2].sodaStock == 0) {
					cout << "That selection is currently out of stock." << endl << endl;
					break;
				}
				else {
					cash = acceptCash(sodaList[2].sodaType, sodaList[2].sodaPrice);
					vend(sodaList[2].sodaPrice, sodaList[2].sodaStock, cash);
					break;
				}
			case GRAPE_SODA:
				if (sodaList[3].sodaStock == 0) {
					cout << "That selection is currently out of stock." << endl << endl;
					break;
				}
				else {
					cash = acceptCash(sodaList[3].sodaType, sodaList[3].sodaPrice);
					vend(sodaList[3].sodaPrice, sodaList[3].sodaStock, cash);
					break;
				}
			case CREAM_SODA:
				if (sodaList[4].sodaStock == 0) {
					cout << "That selection is currently out of stock." << endl << endl;
					break;
				}
				else {
					cash = acceptCash(sodaList[4].sodaType, sodaList[4].sodaPrice);
					vend(sodaList[4].sodaPrice, sodaList[4].sodaStock, cash);
					break;
				}
		}


	} while (choice != 6); //Exits out of program
	
	//Displays amount spent
	cout << endl;
	cout << "Thank you! You spent $" << profit << endl;
	cout << "Enjoy your drinks!" << endl;
	return 0;
	


}
