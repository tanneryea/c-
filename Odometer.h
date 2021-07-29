#pragma once

#define ODOMETER_H

#include <iostream>
#include "FuelGauge.h"

using namespace std;

class Odometer;
class FuelGauge; 

class Odometer {
private:
    int odometer;
    int driven;
    FuelGauge* fuel;

public:

    //sets odometer and creates a fuel gauge
    Odometer(int o = 0, FuelGauge* fuelgauge = new FuelGauge) {
        if (o < 0) {
            cout << "Mileage can not be less than 0! Setting mileage to 0!" << endl;
            odometer = 0;
            driven = 0;
            fuel = fuelgauge;
        }
        else if (o > 999999) {
            cout << "Mileage can not be greater than 999,999! Setting mileage to 999,999!" << endl;
            odometer = 999999;
            driven = 0;
            fuel = fuelgauge;
        }
        else {
            odometer = o;
            driven = 0;
            fuel = fuelgauge;
        }
    }

    //Returns mileage
    int getMileage() const {
        return odometer;
    }


    //increments odometer and spends fuel
    Odometer operator++(int) {
        if (odometer == 999999) {
            driven++;
            odometer = 0;
            decrease(driven);
        }

        else {
            driven++;
            odometer++;
            decrease(driven);
        }

        return *this;
    }

    //Decreases fuel from fuel gauge
    void decrease(int d) {
        if (d % 24 == 0) {
            cout << "You drove 24 miles and spent 1 gallon of gas!" << endl;
            (*fuel)--;
        }
    }

};
