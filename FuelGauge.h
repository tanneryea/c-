#pragma once
#define FUELGAUGE_H

#include <iostream>
using namespace std;

class FuelGauge;

class FuelGauge {
private:
	int gallons;

public:
	//sets gallons in car
	FuelGauge(int g = 0) {
		if (g < 0) {
			cout << "Negative fuel levels are not allowed! Resetting fuel to 0" << endl;
			gallons = 0;
		}
		else if (g > 15) {
			cout << "The car can only hold 15 gallons! Setting fuel level to 15!" << endl;
			gallons = 15;
		}
		else {
			gallons = g;
		}
	}
	//displays gallons
	int getFuel() const {
		return gallons;
	}

	//Increments for filling up car
	FuelGauge operator++(int) {
		if (gallons == 15) {
			cout << "The tank is full!" << endl;
		}
		else {
			gallons++;
		}
		return *this;
	}

	//Deincrements to burn gas
	FuelGauge operator--(int) {
		if (gallons == 0) {
			cout << "The tank is empty!" << endl;
		}
		else {
			gallons--;
		}
		return *this;
	}

};