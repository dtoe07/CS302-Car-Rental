/////////// This classes to mange renters with an array of linked list of users and their cars being rented

#ifndef RENTER_H
#define RENTER_H

#include "car.h"


///////////this classes to mange renters with an array of linked list of users and their cars being rented


class Node {
	private:
		char vin[MAX_CHAR];     // car vin number
                Node*next;
	public:
		Node();
		Node(char v[MAX_CHAR]);

		friend class Renter;
};

// Renter class to manage LLL of cars for each owner
class Renter {
	private:
		char name[MAX_CHAR];    // owner's name
                Node* carList;  // head of the car list
	public:
		Renter();
		Renter(char name[MAX_CHAR]);
		
		void displayCars(Node* carList);
		void addCar(char vin[MAX_CHAR]);

		void removeHelper(Node* &carList, char vin[MAX_CHAR]);
		void remove(char vin[MAX_CHAR]);

		friend class Manager;
};

// Manager class to manage car owners and the cars they list for rent
class Manager {
	private:
		int renterCount;
		static const int MAX_RENTER = 10;
                Renter* renterArray[MAX_RENTER];
	public:
		Manager();

		void addRenter(char name[MAX_CHAR], char vin[MAX_CHAR]);
		void removeVinByRenter(char vin[MAX_CHAR], char name[MAX_CHAR]);
		const char* renterSearch() const;		// prompt user to enter name, search for that name in the renters list
								// return the renter name if they are in the list

};

#endif
