#pragma once
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <iostream>
using namespace std;

class SavingsAccount : public BankAccount { //Derived from SavingsAccount class

public:
	bool status = true; //Flag to make account active

	SavingsAccount() : BankAccount() {} //Derived constructor

	SavingsAccount(double bal, double rate) : BankAccount(bal, rate) { //Derived constructor
		balance = bal;
		annualInterest = rate;
	}

	void withdraw(double withdraw) { //Overriden withdrawal function
		if (status == false) { //Prevents withdrawal if account is inactive
			cout << "Your account is currently inactive. Your balance is $" << balance << endl;
			cout << "Please deposit enough funds to raise balance above $25 to reactivate account." << endl;
		}
		else {
			BankAccount::withdraw(withdraw); //Runs derived withdrawal function
			if (balance < 25) { //Sets account to inactive if balance falls below $25
				status = false;
				cout << "Your balance has dropped to " << balance << endl;
				cout << "You may not make withdrawals until your balance exceeds $25" << endl;
			}
		}
	}

	void deposit(double deposit) {
		if (status == false && balance + deposit >= 25) { //Resets account to active if balance exceeds $25 after deposit
			status = true;
			BankAccount::deposit(deposit);
		}
		else { //Accepts deposit even if balance is below $25 but doesn't reactivate account
			BankAccount::deposit(deposit);
		}
	}

	void monthlyProc() {
		if (withdrawalNum > 4) { //Applies charge if withdrawals above 4
			int serviceCharge = withdrawalNum - 4;
			monthlyCharge += serviceCharge;
			if (balance < 25) { //Makes account inactive if amount falls below $25
				status = false;
				cout << "Your balance has dropped to " << balance << endl;
				cout << "You may not make withdrawals until your balance exceeds $25" << endl;
			}
		}
		BankAccount::monthlyProc(); //Runs processing regardless of previous changes
	}

};


#endif