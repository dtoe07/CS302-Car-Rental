// implementations for car.h file

#include "car.h"
#include <iostream>

using namespace std;

//////////// Base class Car Implementations ------------------------------------------------------

Car::Car() : make(nullptr), model(nullptr), vin(nullptr), name(nullptr), year(0), price(0), rented(false){}

Car::Car(char* _make, char* _model, char* _vin, char* _name, int _year, int _price) {
        make = new char[strlen(_make) + 1];
        strcpy(make, _make);
        model = new char[strlen(_model) + 1];
        strcpy(model, _model);

	vin = new char[strlen(_vin) + 1];
        strcpy(vin, _vin);
	name = new char[strlen(_name) + 1];
        strcpy(name, _name);

        year = _year;
        price = _price;
        rented = false; // initialize rented status to false
}

Car::Car(const Car &obj){
	make = new char[strlen(obj.make) + 1];
	strcpy(make, obj.make);
	model = new char[strlen(obj.model) + 1];
	strcpy(model, obj.model);

	vin = new char[strlen(obj.vin) + 1];
        strcpy(vin, obj.vin);
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);

	price = obj.price;
	year = obj.year;
	rented = obj.rented;
}

Car &Car::operator=(const Car &obj){
	if(this != &obj){
		delete[] make;
		make = new char[strlen(obj.make) + 1];
        	strcpy(make, obj.make);
		delete[] model;
        	model = new char[strlen(obj.model) + 1];
        	strcpy(model, obj.model);

		delete[] vin;
		vin = new char[strlen(obj.vin) + 1];
        	strcpy(vin, obj.vin);
		delete[] name;
		name = new char[strlen(obj.name) + 1];
        	strcpy(name, obj.name);

        	price = obj.price;
        	year = obj.year;
        	rented = obj.rented;
	}
return(*this);
}

Car::~Car() {
    	delete[] make;
    	delete[] model;
	delete[] vin;
	delete[] name;
}

void Car::displayInfo() const {
        cout << make << " " << model << ", " << year << ", Rental Price: $" << price << "/day";
        if (rented) {
            cout << " (Rented)";
        }
        cout << endl;
}

void Car::rentCar() {
        rented = true;
}


void Car::returnCar() {
        rented = false;
}

bool Car::isRented() const {
        return rented;
}

Car* Car::addCar() {
	char make[MAX_CHAR], model[MAX_CHAR], vin[MAX_CHAR], name[MAX_CHAR];
	int year, price;

	cout << "Enter the car make: ";
	cin.getline(make, MAX_CHAR);
    	cout << "Enter the car model: ";
   	cin.getline(model, MAX_CHAR);
	
	cout << "Enter renter name: ";
	cin.getline(name, MAX_CHAR);
	cout << "Enter VIN number: ";
	cin.getline(vin, MAX_CHAR);

    	cout << "Enter the car year: ";
    	cin >> year;
    	cout << "Enter the rental price per day: ";
    	cin >> price;
    	cin.ignore();

    	return new Car(make, model, vin, name, year, price);
}

pair<const char*, const char*> Car::getVinName() const {
    return make_pair(vin, name);
}

/////////////// Electric Car Class Implementations ----------------------------------------


ElectricCar::ElectricCar() : Car(), mileRange(0), chargeTime(0){}

ElectricCar::ElectricCar(Car* car, int mileRange, int chargeTime) 
 	: Car(*car), mileRange(mileRange), chargeTime(chargeTime){}

void ElectricCar::displayInfo() const {
        Car::displayInfo();
        cout << "Mile Range: " << mileRange << " miles, Charge Time: " << chargeTime << " minutes" << endl;
 }


ElectricCar* ElectricCar::addElectricCar() {
 	// Call addCar() to get make, model, year, and price
    	Car* car = addCar();
    
 	int mileRange, chargeTime;
 	cout << "Enter the electric car mile range: ";
 	cin >> mileRange;
 	cout << "Enter the electric car charge time: ";
    	cin >> chargeTime;
    	cin.ignore();

    	// Create a new ElectricCar object using the values obtained
	return new ElectricCar(car, mileRange, chargeTime);

}

bool ElectricCar::compareMileRange(int _mileRange) const {
	return mileRange > _mileRange;
}

/////////////// Truck Class Implementations ----------------------------------------------

Truck::Truck(): Car(), mileage(0), loadCapacity(0){}

Truck::Truck(Car* car, int mileage, int loadCapacity)
	: Car(*car), mileage(mileage), loadCapacity(loadCapacity){}

void Truck::displayInfo() const {
        Car::displayInfo();
        cout << "Mile per gal: " << mileage << ", Load capacity: " << loadCapacity << " lb" << endl;
 }


Truck* Truck::addTruck() {
        // Call addCar() to get make, model, year, and price
        Car* car = addCar();

        int mileage, loadCapacity;
        cout << "Enter the truck mile per gal: ";
        cin >> mileage;
        cout << "Enter the truck loading capacity: ";
        cin >> loadCapacity;
        cin.ignore();

    // Create a new ElectricCar object using the values obtained
        return new Truck(car, mileage, loadCapacity);

}

bool Truck::compareLoadCapacity(int _loadCapacity) const {
	return loadCapacity > _loadCapacity;
}

/////////////// Sport Car Class Implementations -----------------------------------------

SportCar::SportCar() : Car(), mileage(mileage), maxSpeed(maxSpeed), userInstructions(nullptr){}

SportCar::SportCar(Car* car, int mileage, int maxSpeed, char* user_instructions)
        : Car(*car), mileage(mileage), maxSpeed(maxSpeed){
		userInstructions = new char[strlen(user_instructions) + 1];
		strcpy(userInstructions, user_instructions);
	}
SportCar::SportCar(const SportCar &obj)
	: Car(obj), mileage(obj.mileage), maxSpeed(obj.maxSpeed){
	userInstructions = new char[strlen(obj.userInstructions) + 1];
	strcpy(userInstructions, obj.userInstructions);
	}

SportCar::~SportCar(){
	delete[] userInstructions;

}

void SportCar::displayInfo() const {
        Car::displayInfo();
        cout << "Mile per gal: " << mileage << ", Max speed: " << maxSpeed << " mph" << endl;
	cout<< "Special instructions: " << userInstructions << endl;
}

SportCar* SportCar::addSportCar() {
        // Call addCar() to get make, model, year, and price
        Car* car = addCar();

        int mileage, maxSpeed;
	char userInstructions[MAX_CHAR];
        cout << "Enter the sport car mile per gal: ";
        cin >> mileage;
        cout << "Enter the sport car max speed: ";
        cin >> maxSpeed;
	cout << "Enter any special instructions for this car: ";
	cin.getline(userInstructions, MAX_CHAR);
	cin.ignore();

    // Create a new ElectricCar object using the values obtained
        return new SportCar(car, mileage, maxSpeed, userInstructions);

}

bool SportCar::compareMaxSpeed(int _maxSpeed) const {
	return maxSpeed > _maxSpeed;
}





