#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount { //mostly virtual class to represent any type of account

public: //Variables to use throughout functions
	double balance;
	int depositNum = 0;
	int withdrawalNum = 0;
	double annualInterest;
	double monthlyCharge = 0;

	BankAccount() { //Constructor
		balance = 0.0;
		annualInterest = 0.0;
	}

	BankAccount(double bal, double rate) { //Overloaded constructor
		balance = bal;
		annualInterest = rate;
	}

	virtual void deposit(double deposit) { //Basic deposit function
		balance += deposit;
		depositNum++;
	}

	virtual void withdraw(double withdraw) { //Basic withdrawal function
		balance -= withdraw;
		withdrawalNum++;
	}

	virtual void calcInt() { //Calculates interest
		double monthlyRate = annualInterest / 12;
		double monthlyInterest = balance * monthlyRate;
		balance = balance + monthlyInterest;
	}

	virtual void monthlyProc() { //Describes accounts parameters, removes monthly charges, calculates interest and resets variables
		cout << "Your balance before processing is: $" << setprecision(2) << fixed << balance << endl;
		cout << "Your monthly charges are: $" << setprecision(2) << fixed << monthlyCharge << endl;
		cout << "Your amount of deposits is: " << depositNum << endl;
		cout << "Your amount of withdrawals is: " << withdrawalNum << endl;
		balance -= monthlyCharge;
		calcInt();
		withdrawalNum = 0;
		depositNum = 0; 
		monthlyCharge = 0;
	}
};

#endif
