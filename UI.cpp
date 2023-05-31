// Implementations for UI.h file


#include "UI.h"


/////////////// RentalUI Class Implementations -------------------------------------------

RentalUI::RentalUI () : carList(), manager(){
	// initialize the car vectors
    	electricCars = vector<ElectricCar*>();
    	trucks = vector<Truck*>();
    	sportCars = vector<SportCar*>();
}


RentalUI::~RentalUI() {
    	// destroy the car vectors
    	for (ElectricCar* car : electricCars) {
        	delete car;
    	}
    	for (Truck* truck : trucks) {
        	delete truck;
    	}
    	for (SportCar* sportCar : sportCars) {
        	delete sportCar;
    	}
}

pair<const char*, const char*>  RentalUI::addElectricCar() {
    	ElectricCar* car = ElectricCar::addElectricCar();
	
	car->displayInfo();	

	if (car != nullptr) {
        	electricCars.push_back(car);
        	cout << "Electric car added successfully." << endl;
		cout << "----------------------------------------------" << endl;
    	} else {
        	cout << "Electric car not added." << endl;
		cout << "----------------------------------------------" << endl;
    	}
	return car->getVinName();
}

pair<const char*, const char*> RentalUI::addTruck() {
    	Truck* truck = Truck::addTruck();

    	if (truck != nullptr) {
        	trucks.push_back(truck);
        	cout << "Truck added successfully." << endl;
		cout << "----------------------------------------------" << endl;
    	} else {
    	    	cout << "Truck not added." << endl;
		cout << "----------------------------------------------" << endl;
    	}
	return truck->getVinName();
}

pair<const char*, const char*>  RentalUI::addSportCar() {
    	SportCar* car = SportCar::addSportCar();

    	if (car != nullptr) {
        	sportCars.push_back(car);
        	cout << "Sport car added successfully." << endl;
		cout << "----------------------------------------------" << endl;
    	} else {
        	cout << "Sport car not added." << endl;
		cout << "----------------------------------------------" << endl;
    	}
	return car->getVinName();
}

//Removing a car by vin number search
void RentalUI::removeCarByVin(string vin) {
	for (auto it = electricCars.begin(); it != electricCars.end(); ++it) {
		if((*it)->getVinName().first == vin) {
			electricCars.erase(it);
			cout << " Successfully Removed" << endl;
			cout << "----------------------------------------------" << endl;
			return;
		}
	}

	for (auto it = trucks.begin(); it != trucks.end(); ++it) {
                if((*it)->getVinName().first == vin) {
                        trucks.erase(it);
                        cout << " Successfully Removed" << endl;
			cout << "----------------------------------------------" << endl;
                        return;
                }
        }

	for (auto it = sportCars.begin(); it != sportCars.end(); ++it) {
                if((*it)->getVinName().first == vin) {
                        sportCars.erase(it);
                        cout << " Successfully Removed" << endl;
			cout << "----------------------------------------------" << endl;
                        return;
                }
        }
}

//Renting a car functions-----------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////
//
pair<const char*, const char*>  RentalUI::rentElectricCars() {
    	// Display all available electric cars
    	cout << "----------------------------------------------" << endl;
	cout << "Available electric cars for rent:" << endl;
    	int index = 0;
	int count = 0;
    	for (ElectricCar* car : electricCars) {
        	if (!car->isRented()) {
            		cout << "[" << index << "] ";
            		car->displayInfo();
            		count++;
        		}
		index++;
    	}
    	if (count == 0) {
        	cout << "No electric cars available for rent." << endl;
		cout << "----------------------------------------------" << endl;
        	return make_pair("", "");
    	}

    	// Prompt the user to select which car to rent
    	int selection;
	char renter[MAX_CHAR];
    	do {
        	cout << "Enter the index of the car you would like to rent: ";
        	cin >> selection;
		cin.ignore();
		cout << "Enter your name or q to quit: ";
		cin.getline(renter, MAX_CHAR);
		if(strcmp(renter, "q") == 0) return make_pair("", "");

    	} while (selection < 0 || selection >= index);


    	// Rent the selected car
    	ElectricCar* selectedCar = electricCars.at(selection);
    	selectedCar->rentCar();
	auto vinName = selectedCar->getVinName();
	char vin[MAX_CHAR];
	strcpy(vin, vinName.first);

    	cout << "You have rented the following electric car:" << endl;
    	selectedCar->displayInfo();
	cout << "----------------------------------------------" << endl;

	return make_pair(vin, renter);
}

pair<const char*, const char*>  RentalUI::rentTruck() {
        // Display all the available trucks
	cout << "----------------------------------------------" << endl;
        cout << "Available trucks for rent:" << endl;
        int index = 0;
        for (Truck* truck : trucks) {
        	if (!truck->isRented()) {
            		cout << "[" << index << "] ";
                	truck->displayInfo();
                	index++;
            }
        }
        if (index == 0) {
        	cout << "No trucks available for rent." << endl;
		cout << "----------------------------------------------" << endl;
        	return make_pair("", "");
        }

        // Prompt the user to select which truck to rent
        int selection;
	char renter[MAX_CHAR];
        do {
            	cout << "Enter the index of the truck you would like to rent: ";
            	cin >> selection;

		cin.ignore();
		cout << "Enter your name or q to quit: ";
                cin.getline(renter, MAX_CHAR);
		if(strcmp(renter, "q") == 0) return make_pair("", "");
        } while (selection < 0 || selection >= index);

        // Rent the selected truck
        Truck* selectedTruck = trucks.at(selection);
        selectedTruck->rentCar();
	auto vinName = selectedTruck->getVinName();
	char vin[MAX_CHAR];
        strcpy(vin, vinName.first);

        cout << "You have rented the following truck:" << endl;
        selectedTruck->displayInfo();
	cout << "----------------------------------------------" << endl;
	
	return make_pair(vin, renter);
}

pair<const char*, const char*>  RentalUI::rentSportCar() {
        // Display all the available sport cars
	cout << "----------------------------------------------" << endl;
        cout << "Available sport cars for rent:" << endl;
        int index = 0;
        for (SportCar* car : sportCars) {
            	if (!car->isRented()) {
                	cout << "[" << index << "] ";
                	car->displayInfo();
                	index++;
            	}
        }
        if (index == 0) {
            	cout << "No sport cars available for rent." << endl;
		cout << "----------------------------------------------" << endl;
            	return make_pair("", "");
        }

        // Prompt the user to select which sport car to rent
        int selection;
	char renter[MAX_CHAR];
        do {
            	cout << "Enter the index of the sport car you would like to rent: ";
            	cin >> selection;

		cin.ignore();
		cout << "Enter your name or q to quit: ";
                cin.getline(renter, MAX_CHAR);
		if(strcmp(renter, "q") == 0) return make_pair("", "");
        } while (selection < 0 || selection >= index);

        // Rent the selected sport car
        SportCar* selectedCar = sportCars.at(selection);
        selectedCar->rentCar();
	auto vinName = selectedCar->getVinName();
        char vin[MAX_CHAR];
        strcpy(vin, vinName.first);

        cout << "You have rented the following sport car:" << endl;
        selectedCar->displayInfo();
	cout << "----------------------------------------------" << endl;

	return make_pair(vin, renter);
}

// funtions to search by specific spec
//

void RentalUI::searchByMaxSpeed() const{
	int _maxSpeed;
	int count = 0;
	cout << "Enter minimum max speed: ";
	cin >> _maxSpeed;
	for (SportCar* car : sportCars) {
		if(car->compareMaxSpeed(_maxSpeed)) {
			car->displayInfo();
			count++;
		}
	}
	if(count == 0){
		cout << "no sport car that meets your desired max speed available for rent" << endl;
		cout << "----------------------------------------------" << endl;
	}
}

void RentalUI::searchByMileRange() const{
        int _mileRange;
        int count = 0;
        cout << "Enter your desired minimum mile range of an electric car: ";
        cin >> _mileRange;
        for (ElectricCar* car : electricCars) {
                if(car->compareMileRange(_mileRange)) {
                        car->displayInfo();
                        count++;
                }
        }
        if(count == 0){
                cout << "no electric car that meets your desired mile range available for rent" << endl;
                cout << "----------------------------------------------" << endl;
        }
}

void RentalUI::searchByLoadCapacity() const{
        int _loadCapacity;
        int count = 0;
        cout << "Enter minimum desired load capacity: ";
        cin >> _loadCapacity;
        for (Truck* car : trucks) {
                if(car->compareLoadCapacity(_loadCapacity)) {
                        car->displayInfo();
                        count++;
                }
        }
        if(count == 0){
                cout << "no truck that meets your desired load capacity available for rent" << endl;
                cout << "----------------------------------------------" << endl;
        }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------- Main Menu ----------------------------------------------------------------
void RentalUI::mainMenu() {
	char choice;
        do {
        	std::cout << "Car Rental Service\n"
                      	<< "1. Add a car for rent\n"
                      	<< "2. Remove a car from rent list\n"
                      	<< "3. Search for a car to rent by category\n"
                      	<< "4. Search by max speed\n"
                      	<< "5. Search by mile range\n"
                      	<< "6. Search by max Load\n"
			<< "7. Display all rented cars\n"
                      	<< "q. Exit\n"
                      	<< "Please enter your choice: ";
			std::cin >> choice;
			cin.ignore();

		switch(choice) {
			case '1': {
         	   		char subChoice;
				cout << "----------------------------------------------" << endl;
            			cout << "Choose a car category:\n"
                		<< "a. Electric Car\n"
                		<< "b. Truck\n"
                		<< "c. Sport Car\n"
                		<< "Enter your choice: ";
            			cin >> subChoice;
            			cin.ignore();

            			switch (subChoice) {
            				case 'a': {
                				auto electric = addElectricCar();
						char e_vin[MAX_CHAR];
						char e_name[MAX_CHAR];
						strcpy(e_vin, electric.first);
						strcpy(e_name, electric.second);
						manager.addRenter(e_name, e_vin);
                				break;
					}
            				case 'b':{
                				auto truck = addTruck();
						char t_vin[MAX_CHAR];
                                                char t_name[MAX_CHAR];
                                                strcpy(t_vin, truck.first);
                                                strcpy(t_name, truck.second);
						manager.addRenter(t_name, t_vin);
                				break;
					}
            				case 'c':{
                				auto sport = addSportCar();
						char s_vin[MAX_CHAR];
                                                char s_name[MAX_CHAR];
                                                strcpy(s_vin, sport.first);
                                                strcpy(s_name, sport.second);
						manager.addRenter(s_name, s_vin);
                				break;
					}
            				default:
                				cout << "Invalid choice!\n";
            			}//end sub choices for case1
            			break;
        			}//end case1

			case '2':{
				char name[MAX_CHAR];
				strcpy(name, manager.renterSearch());		// prompt user to enter name, if found return the name
				if(strcmp(name, "not found") != 0){		// if user name was found, procceed
					char vin[MAX_CHAR];
					cout << "Enter vin number for deletion: ";
					cin.getline(vin, MAX_CHAR);

					manager.removeVinByRenter(vin, name);
					carList.removeCar(vin);
					removeCarByVin(vin);
				} else cout << endl << "no renter found with the name entered!" << endl << endl;
				cout << "----------------------------------------------" << endl << endl;;
				
				break;
			}//end case2

			
			case '3': {
            			char subChoice;
				cout << "----------------------------------------------" << endl;
            			cout << "Choose a car category:\n"
                		<< "a. Electric Car\n"
                		<< "b. Truck\n"
                		<< "c. Sport Car\n"
                		<< "Enter your choice: ";
            			cin >> subChoice;
            			cin.ignore();

            			switch (subChoice) {
            				case 'a': {
						auto electric = rentElectricCars();
						char e_vin[MAX_CHAR];
                                                char e_name[MAX_CHAR];
                                                strcpy(e_vin, electric.first);
                                                strcpy(e_name, electric.second);

						if(strcmp(e_name, "") != 0){
							carList.insertCar(e_vin, e_name);
						}
                				break;
					}
            				case 'b': {
                				auto truck = rentTruck();
						char t_vin[MAX_CHAR];
                                                char t_name[MAX_CHAR];
                                                strcpy(t_vin, truck.first);
                                                strcpy(t_name, truck.second);

                                                if(strcmp(t_name, "") != 0){
							carList.insertCar(t_vin, t_name);
						}
                				break;
					}
            				case 'c': {
                				auto sport = rentSportCar();
						char s_vin[MAX_CHAR];
                                                char s_name[MAX_CHAR];
                                                strcpy(s_vin, sport.first);
                                                strcpy(s_name, sport.second);
                                                
						if(strcmp(s_name, "") != 0){
							carList.insertCar(s_vin, s_name);
						}
                				break;
					}
            				default:
                				cout << "Invalid choice!\n";
            			}
            			break;
        		}// end case3

			case '4': 
				searchByMaxSpeed();
				break;
			case '5':
				searchByMileRange();
				break;
			case '6':
				searchByLoadCapacity();
				break;
			case '7':
				carList.displayCar();
				break;
		}//end main switch choice

	} while (choice != 'q');
}



