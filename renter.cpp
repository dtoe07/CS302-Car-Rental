// Implementations for renter.h file


#include "renter.h"


Node::Node(char v[MAX_CHAR]) : next(nullptr) { 
        strcpy(vin, v); 
    }

Node::Node() : next(nullptr) {
    	strcpy(vin, "");
}

// Renter class defines here--------------------------------------
Renter::Renter() : carList(nullptr) {
    	strcpy(name, "");
}

Renter::Renter(char name[MAX_CHAR]): carList(nullptr) {
    strcpy(this->name, name);
}

void Renter::displayCars(Node* carList){
	if(!carList) return;

	cout << carList->vin << endl;
	displayCars(carList->next);
}

void Renter::addCar(char vin[MAX_CHAR]){
	if(!carList){
		carList = new Node(vin);
	}else{
		Node* temp = new Node(vin);
		temp->next = carList;
		carList = temp;
	}
}
void Renter::removeHelper(Node* &carList, char vin[MAX_CHAR]){
	if(!carList) return;
	
	if(strcmp(carList->vin, vin) == 0){
		Node* temp = carList;
		carList = carList->next;
		delete temp;
		return;
	}
	removeHelper(carList->next, vin);

}


void Renter::remove(char vin[MAX_CHAR]){
	removeHelper(carList, vin);
}



///////////// Manager Class ---------------------------------------
//

Manager::Manager() : renterCount(0) {
    	for (int i = 0; i < MAX_RENTER; i++) {
        	renterArray[i] = nullptr;
    	}
}

void Manager::addRenter(char name[MAX_CHAR], char vin[MAX_CHAR]){
	//search the renters list if name already exist then add the new vin to that renter
	for(int i = 0; i < renterCount; i++){
		if(strcmp(renterArray[i]->name, name) == 0){
			renterArray[i]->addCar(vin);
			cout<<"added new car for the same owner"<<endl<<endl;
			return;
		}
		cout<<"renter in list: "<<renterArray[i]->name<<endl;
	}
	
	//if the list is not full, add new renter to the list and add new vin to that renter
	if(renterCount < MAX_RENTER) {
		Renter* newRenter = new Renter(name);
		newRenter->addCar(vin);
		renterArray[renterCount++] = newRenter;
		cout<<"added new car for new owner"<<name<<endl<<endl;
	} else cout << " error adding new car" <<endl;
	
}


//asking for user name and display their cars being posted for rent
const char* Manager::renterSearch()const{
	cout<< "Please enter your user name to display your cars: ";
	char name[MAX_CHAR];
	cin.getline(name, MAX_CHAR);

	for(int i = 0; i < renterCount; i++){
		if(strcmp(renterArray[i]->name, name) == 0){
			cout << "cars for renter " << renterArray[i]->name << " :"  <<endl;
			renterArray[i]->displayCars(renterArray[i]->carList);
			cout << endl << endl;
			return renterArray[i]->name;
		}
	} 
	return "not found";
}

void Manager::removeVinByRenter(char vin[MAX_CHAR], char name[MAX_CHAR]) {
        for (int i = 0; i < renterCount; i++) {
        	if (strcmp(renterArray[i]->name, name) == 0) {
			renterArray[i]->remove(vin);
			
			if(!renterArray[i]->carList){
				delete renterArray[i];
                		for (int j = i; j < renterCount - 1; j++) {
                			renterArray[j] = renterArray[j+1];
                		}
                		renterCount--;
                		cout << "Renter " << name << " removed" << endl;
			}
		}else cout << " vin is not found" << endl;
	}
}



