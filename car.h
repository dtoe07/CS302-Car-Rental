
//this header file declares classes for Car which is the base class for classes:
//ElectricCar
//Truck
//SportCar



#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX_CHAR = 50;

// Car class declares here:
class Car {
private:
	char* make;	// car manufacture
	char* model;	// car model
	char* vin;	// vin numer
	char* name;	// car owner
	int year;	// year made
	int price;	// price for renting per day
	bool rented;	// is being rented or not

public:
	Car();	// default constructor
	Car(char* _make, char* _model,char* _vin, char* _name, int _year, int _Price);	// constructor with pass in values to make new car
	Car(const Car &);		// copy constructor
	Car &operator=(const Car &);	// assignment operator
	~Car();				// destructor

	static Car* addCar();		// prompt user for each data and then create an object using constructor
	void displayInfo() const;	// display a car
	void rentCar();		   	// set rented to true when the car is rented
	void returnCar();		// set rented to false when the car is returned
	bool isRented() const;		// return if the car is already rented or not
	pair<const char*, const char*> getVinName() const;	// returning owner name and vin for the renter list to manage their cars
};


// ElectricCar class declares here:
class ElectricCar : public Car {

private:
	int mileRange;		// mile range that electric car can run with full charge
	int chargeTime;		// time to charge until full

public:
	ElectricCar();		// constructor
	ElectricCar(Car* car, int _mileRange, int _chargeTime);	// constructor to pass in data to make new obj
	
	void displayInfo() const;			//display an electric car info
	static ElectricCar* addElectricCar();		//add new electric car by calling addCar function from Car
	bool compareMileRange(int mileRange) const;	//compare the user desired mile range
};

// Truck class declares here:
class Truck : public Car {
private:
	int mileage;		// miles per gal
	int loadCapacity;	// loading capacity of the truck

public:
	Truck();		// default constructor
	Truck(Car* car, int _mileage, int _loadCapacity);       // constructor with data passed in
	void displayInfo() const;       			//display a Truck info
        static Truck* addTruck();   				//add new truck by calling addCar function from Car
	bool compareLoadCapacity(int _loadCapacity) const;	//check if load capacity meets the users need

};


// SportCar class declares here
class SportCar : public Car {
private:
        int mileage;			// miles per gal
        int maxSpeed;			// max speed of the car
	char* userInstructions;		// special instructions for luxury race car

public:
	SportCar();			// default constructor
        SportCar(Car* car, int _mileage, int _maxSpeed, char* userInstructions);	//constructor with data passed in
	SportCar(const SportCar &);		//copy constructor
	SportCar &operator=(const SportCar &);	//assignment opperator
	~SportCar();				//destructor

	void displayInfo() const;       	//display a SportCar info
        static SportCar* addSportCar();   	//add new SportCar by calling addCar function from Car

	bool compareMaxSpeed(int _maxSpeed) const;	//compare and return if max speed meets the users need

};



#endif
