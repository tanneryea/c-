#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"
#include <iostream>
using namespace std;

class CheckingAccount : public BankAccount {

public:
	CheckingAccount() : BankAccount(){} //Dervied constructor

	CheckingAccount(double bal, double rate) : BankAccount(bal, rate) { //Second derived constructor
		balance = bal;
		annualInterest = rate;
	}

	void withdraw(double withdraw) {
		if (balance - withdraw < 0) { //Creates penalty if account is overdrawn and prevents withdrawal
			balance -= 15;
			if (balance < 0) {
				cout << "You did not have enough to cover the withdrawal cost\n"
					"Your account is now $" << balance << ". You owe the bank the remainder." << endl;
			}
		}
		else {
			BankAccount::withdraw(withdraw);
		}
	}

	void monthlyProc() {
		double monthlyfee = 5 + (0.1 * withdrawalNum); //Processes withdrawal fee and runs dervied function
		monthlyCharge += monthlyfee;
		BankAccount::monthlyProc();
	}
};






#endif