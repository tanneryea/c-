#include <iostream>
#include <iomanip>
#include "FuelGauge.h"
#include "Odometer.h"

using namespace std;

//Refuels car
void Refuel(FuelGauge *fgauge) {
    int refuelAmount;
    cout << "Enter amount of fuel to place in car in gallons: ";
    cin >> refuelAmount;
    while (refuelAmount < 0 || refuelAmount > 15) {
        cout << "The fuel tank can not hold less than 0 gallons or more than 15 gallons. Enter a new amount: ";
        cin >> refuelAmount;
    }
    for (int x = 0; x < refuelAmount; x++) {
        (*fgauge)++;
    }
    
    cout << "Car refeuled!\n";
    cout << "Amount of fuel left: " << fgauge->getFuel() << " gallons" << endl;
}

//Drives the car and increments the odometer. Prints out mileage every 24 miles
void Drive(Odometer ometer, FuelGauge *fgauge) {
    cout << "Now driving until car runs out of gas...." << endl;

    while (fgauge->getFuel() > 0) {
        ometer++;
        if (ometer.getMileage() % 24 == 0) {
            cout << "Odometer :" << setw(7) << ometer.getMileage();
            cout << " miles.";
            cout << "\tFuel left: " << setw(3) << fgauge->getFuel();
            cout << endl;
        }
    }
}


//Create objects in dynamic memory
int main()
{
    //create FuelGauge and Odometer objects
    cout << "Creating a fuel gauge and an odometer...\n";
    FuelGauge* fgauge = new FuelGauge;
    Odometer ometer(0, fgauge);
    cout << "Done!\n\n";

    Refuel(fgauge);
    Drive(ometer, fgauge);

    delete fgauge;
    fgauge = NULL;

    return 0;
}