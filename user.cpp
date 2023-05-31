// Implementations for user.h file

#include "user.h"


// Constructor for RentedCar class
RentedCar::RentedCar(char vin[MAX_CHAR], char name[MAX_CHAR]) : next(nullptr) {
    	strcpy(this->vin, vin);
    	strcpy(this->name, name);
}

RentedCar::RentedCar(){
	vin[0] = '\0';
	name[0] = '\0';
	next = nullptr;;
}


// Constructor for CarList class
CarList::CarList() : head(nullptr) {}


// Inserting functions-------------------------------------------------------
void CarList::insertHelper(RentedCar* current, char vin[MAX_CHAR], char name[MAX_CHAR]) {
	if(current->next == head) {
		current->next = new RentedCar(vin, name);
		current->next->next = head;
	}
	else {
		insertHelper(current->next, vin, name);
	}
}


void CarList::insertCar(char vin[MAX_CHAR], char name[MAX_CHAR]) {
	if(!head) {
		head = new RentedCar(vin, name);
		head->next = head;
	} else insertHelper(head, vin, name);
}


// Displaying functions ----------------------------------------------------
void CarList::displayHelper(RentedCar* current) {
	if(!head) {
		cout << "no car is being rented" << endl;
		return;
	}

	cout << current->vin << " - rented by: " << current->name << endl;

	if(current->next != head) displayHelper(current->next);
}

void CarList::displayCar() {
	displayHelper(head);
	cout << "-------------------------------------------------------------------" << endl;
}


// Removing functions ------------------------------------------------------
RentedCar* CarList::lastCar(RentedCar* current) {
	if(!head) {
                cout << "no car is being rented" << endl;
                return nullptr;
        }
	if(current == head) return current;
	return lastCar(current->next);
}

// Removing a car from the list
void CarList::removeHelper(RentedCar* current, RentedCar* prev, char vin[MAX_CHAR]) {
	if(strcmp(current->vin, vin) == 0) {
		if(current == head) {
			if(head->next = head) {
				head = nullptr;
			} else{
				RentedCar* last = lastCar(head);
				head = head->next;
				last->next = head;
			}
		}else prev->next = current->next;
		delete current;
		cout << vin << " was deleted" << endl;
		return;
	}
	if(current->next == head) {
		cout << vin << " not found!" <<endl;
		return;
	}
	removeHelper(current-> next, current, vin);

}

void CarList::removeCar(char vin[MAX_CHAR]) {
	if(!head) {
		return;
	}
	removeHelper(head, nullptr, vin);
}












