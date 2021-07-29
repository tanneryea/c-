#include <iostream>
#include <iomanip>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

//Prototype functions with overloads
int operationMenu(CheckingAccount);
int operationMenu(SavingsAccount);

int operationMenu(SavingsAccount account) {
	int opChoice; //Variable to store menu choice

	do { //Operation menu for account
		cout << "Select an action from the menu below:" << endl;
		cout << "1. Deposit" << endl;
		cout << "2. Withdraw" << endl;
		cout << "3. Check Balance" << endl;
		cout << "4. Monthly Processing" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> opChoice;

		//input validation loop
		while (opChoice > 5 || opChoice < 1) {
			cout << "Please enter a valid choice: ";
			cin >> opChoice;
		}

		if (opChoice != 5) { //Menu that runs appropriate member functions of classes

			switch (opChoice) {
			case 1:
				double dep;
				cout << "Enter how much you want to deposit: $";
				cin >> dep;
				account.deposit(dep);
				break;
			case 2:
				double with;
				cout << "Enter how much you want to withdraw: $";
				cin >> with;
				account.withdraw(with);
				break;
			case 3:
				cout << "Your current balance is: $" << setprecision(2) << fixed << account.balance << endl;
				break;
			case 4:
				cout << "Processing your monthly fees and gaining interest..." << endl;
				account.monthlyProc();
				break;
			}

		}

	} while (opChoice != 5);
	return 0;
}

int operationMenu(CheckingAccount account) {
	int opChoice; //Same as previous function, just tuned to CheckingAccount class

	do {
		cout << "Select an action from the menu below:" << endl;
		cout << "1. Deposit" << endl;
		cout << "2. Withdraw" << endl;
		cout << "3. Check Balance" << endl;
		cout << "4. Monthly Processing" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> opChoice;

		while (opChoice > 5 || opChoice < 1) {
			cout << "Please enter a valid choice: ";
			cin >> opChoice;
		}

		if (opChoice != 5) {

			switch (opChoice) {
			case 1:
				double dep;
				cout << "Enter how much you want to deposit: $";
				cin >> dep;
				account.deposit(dep);
				break;
			case 2:
				double with;
				cout << "Enter how much you want to withdraw: $";
				cin >> with;
				account.withdraw(with);
				break;
			case 3:
				cout << "Your current balance is: $" << setprecision(2) << fixed << account.balance << endl;
				break;
			case 4:
				cout << "Processing your monthly fees and gaining interest..." << endl;
				account.monthlyProc();
				break;
			}

		}

	} while (opChoice != 5);
	return 0;
}

int main() {
	//Variables for menu selection and beginning balance/rate
	int accChoice;
	double bal;
	double rate;

	do {
		cout << "Welcome to I.P. Freely Credit Union. Create a new account from the menu below: " << endl;
		cout << "1. Checking account" << endl;
		cout << "2. Savings account" << endl;
		cout << "3. Exit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> accChoice;
		
		while (accChoice > 3 || accChoice < 1) {
			cout << "Please enter a valid choice: ";
			cin >> accChoice;
		}

		if (accChoice != 3) {
			cout << "Enter the account balance: $";
			cin >> bal;
			cout << "Enter the annual interest rate: ";
			cin >> rate;
			
			switch (accChoice) { //Case creates an object, then runs operationMenu function with it
			case 1:
			{
				CheckingAccount checking(bal, rate);
				operationMenu(checking);
				return 0;
			}
				
			case 2:
			{
				SavingsAccount savings(bal, rate);
				operationMenu(savings);
				return 0;
			}
			}
		}
	
	} while (accChoice != 3);
	return 0;



}