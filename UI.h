
//////// Rental UI class to manage everything with a main menu

#ifndef UI_H
#define UI_H


#include "car.h"
#include "user.h"
#include "renter.h"


class RentalUI {
private:
	vector<ElectricCar*> electricCars;	// vector of electric cars
	vector<Truck*> trucks;			// vector of trucks
	vector<SportCar*> sportCars;		// vector of sportCars
	Manager manager;			// an instance of owner list with their cars
	CarList carList;			// list of cars that being rented
	
public:
	RentalUI();		//initialize the list
	~RentalUI();		//destroy the list
	void mainMenu();	//display main menu options

	pair<const char*, const char*>  addElectricCar();	//add an electric car to the list
	pair<const char*, const char*>  addTruck();	//add a truck
	pair<const char*, const char*>  addSportCar();	//add a sport car

	void removeCarByVin(string vin);

	pair<const char*, const char*>  rentElectricCars();	// display all electric cars for rent return vin and renter to add to carList
	pair<const char*, const char*>  rentTruck();		// display all trucks for rent return vin and renter to add to carList
	pair<const char*, const char*>  rentSportCar();		// display all sport cars for rent return vin and renter to add to carList

	void displayElectricCars() const;	//display available electric cars
	void displayTruck() const;		//display available trucks
	void displaySportCars() const;		//display available sport cars;

	void searchByMileRange() const;		//search electric car by mile range
	void searchByLoadCapacity() const;	//search trucks by load capacity
	void searchByMaxSpeed() const;		//search sport cars by max speed
	
};









#endif
