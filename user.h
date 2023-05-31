
// Class to manage cars being rented with the name of person who rented each car


#ifndef USER_H
#define USER_H

#include "car.h"
#include <iostream>
#include <cstring>


using namespace std;


class RentedCar {
	private:
		char vin[MAX_CHAR];     // car vin number
                char name[MAX_CHAR];    // renter name
		RentedCar* next;
	public:
		RentedCar();
		RentedCar(char vin[MAX_CHAR], char name[MAX_CHAR]);

		friend class CarList;
};


class CarList {
	private:
		RentedCar* head;
	public:
		CarList();
		void insertHelper(RentedCar* current,char vin[MAX_CHAR], char name[MAX_CHAR]);
		void insertCar(char vin[MAX_CHAR],char name[MAX_CHAR]);
		void removeHelper(RentedCar* current, RentedCar* prev, char vin[MAX_CHAR]);
		void removeCar(char vin[MAX_CHAR]);
		RentedCar* lastCar(RentedCar* current);

		void displayHelper(RentedCar* current);
		void displayCar();
};



#endif

