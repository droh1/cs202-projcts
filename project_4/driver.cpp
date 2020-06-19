/*****************************************************************
* File:		driver.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is driver.cpp
*	This file starts the program and manages menu output
*****************************************************************/

#include "driver.h"

//-------------------------------------------------
// Name: menu
// PreCondition: None
// PostCondition: Displays menu to user
//-------------------------------------------------
void menu() {
	Garden G1 = Garden(); //Make a garden object

	cout << "Welcome to the jungle... I mean garden" << endl << endl;
	cout << "\t1. Plant single item" << endl
		<< "\t2. Plant many of the same item" << endl
		<< "\t3. Plant a full garden" << endl
		<< "\t4. Exit" << endl;
	
	manageMenu(G1); //Sends to manage menu
}

//------------------------------------------------------------
// Name: Garden
// PreCondition: Garden object
// PostCondition: Sends user to corsponding function selected
//------------------------------------------------------------
void manageMenu(Garden& garden) {
	int command = 0;
	//int plant = 0;
	const int key = 4;

	while (command != key) {
		cout << "What would you like to do? (1-4)" << endl;
		cin >> command;

		switch (command) {
		case 1: //Plant Single item
			singleGarden(garden, 1);
			command = 4; //Ends program
			break;

		case 2: //Plant Many of the same item
			singleGarden(garden, 2); 
			command = 4; //Ends program
			break;

		case 3: //Plant a full garden
			manyGarden(garden); 
			command = 4; //Ends program
			break;

		case 4: //Exit program
			cout << "You have exited the garden, The gnomes are now destroying the garden" << endl;
			exit(0);
			break;

		default: //Invalid input protection
			cout << "Invalid command!!!!!" << endl << endl;
			cout << "\t1. Plant single item" << endl
				 << "\t2. Plant many of the same item" << endl
				 << "\t3. Plant a full garden" << endl
				 << "\t4. Exit" << endl;
			cout << "What would you like to do? (1-4)" << endl;
			cin >> command;
		}

		//Menu output
		cout << endl << "\t1. Plant single item" << endl
			<< "\t2. Plant many of the same item" << endl
			<< "\t3. Plant a full garden" << endl
			<< "\t4. Exit" << endl;
	}

	cout << "You have exited the garden, The gnomes are now destroying the garden" << endl;
}

//--------------------------------------------------------
// Name: singleGarden
// PreCondition: Garden object and int which plant to add
// PostCondition: Makes a Garden object
//--------------------------------------------------------
void singleGarden(Garden& garden, int quantity) {
	int test = 0;
	int plant;
	int pro = 0;
	const int key = 1;

	plantMenu(); //Displays items that can be planted
	cout << "What would you like to plant? (1-3)" << endl;
	cin >> plant;
	if (quantity == key) { //If only one of a plant 
		while (test != key) { //Program protection
			switch (plant) {
			case 1:
				garden.addPlant(1, quantity); //Adds one Flower
				simulateTime(garden); //Goes to ask user time
				test = 1; //Breaks the test case
				break;

			case 2:
				garden.addPlant(2, quantity); //Adds one Vegetable
				simulateTime(garden); //Goes to ask user time
				test = 1; //Breaks the test case
				break;

			case 3:
				garden.addPlant(3, quantity); //Adds one Tree
				simulateTime(garden); //Goes to ask user time
				test = 1; //Breaks the test case
				break;

			default: //Invalid input protection
				cout << "Invalid plant: " << endl;
				plantMenu();
				cin >> plant;
			}
		}
	}
	else { //If many of one plant
		while (test != key) { //Program protection
			switch (plant) {
			case 1:
				while (pro != key) { //Program Protection
					cout << "How many flowers would you like to add? " << endl;
					cin >> quantity;
					if (quantity >= 0) {
						pro = 1;
					}
					else {
						cout << "Invalid amount of flowers!!!!!!" << endl;
					}
				}
				garden.addPlant(1, quantity); //Adds one Flower
				simulateTime(garden); //Goes to ask user time
				test = 1; //Breaks the test case
				break;

			case 2:
				while (pro != key) { //Program Protection
					cout << "How many vegetables would you like to add? " << endl;
					cin >> quantity;
					if (quantity >= 0) {
						pro = 1;
					}
					else {
						cout << "Invalid amount of vegetables!!!!!!" << endl;
					}
				}
				garden.addPlant(2, quantity); //Adds one Vegetable
				simulateTime(garden); //Goes to ask user time
				test = 1; //Breaks the test case
				break;

			case 3:
				while (pro != key) { //Program protection
					cout << "How many trees would you like to add? " << endl;
					cin >> quantity;
					if (quantity >= 0) {
						pro = 1;
					}
					else {
						cout << "Invalid amount of trees!!!!!!" << endl;
					}
				}
				garden.addPlant(3, quantity); //Adds one Tree
				simulateTime(garden); //Goes to ask user time
				test = 1; //Breaks the test case
				break;

			default: //Invalid input protection
				cout << "Invalid plant: " << endl;
				plantMenu();
				cin >> plant;
			}
		}
	}
}

//---------------------------------------------------------------
// Name: manyGarden
// PreCondition: Garden
// PostCondition: Gets a value from user asking amount of plants
//---------------------------------------------------------------
void manyGarden(Garden& garden) {
	int test = 0;
	int quanitiy;
	const int key = 1;

	while (test != key) {
		cout << "How many flowers you like to plant?" << endl;
		cin >> quanitiy;

		if (quanitiy >= 0) { //Test for user input
			test = key;
		}
		else {
			cout << "Invalid amount of flowers!!" << endl;
		}
	}
	garden.addPlant(1, quanitiy); //Adds Flowers
	test = 0; //rest test for next item

	while (test != key) {
		cout << "How many vegetables would you like to plant?" << endl;
		cin >> quanitiy;

		if (quanitiy >= 0) { //Test for user input
			test = key;
		}
		else {
			cout << "Invalid amount of vegetables!!" << endl;
		}
	}
	garden.addPlant(2, quanitiy); //Adds Veget
	test = 0; //rest test for next item

	while (test != key) {
		cout << "How many trees would you like to plant?" << endl;
		cin >> quanitiy;

		if (quanitiy >= 0) { //Test for user input
			test = key;
		}
		else {
			cout << "Invalid amount of trees!!" << endl;
		}
	}
	garden.addPlant(3, quanitiy); //Adds Tree
	simulateTime(garden); //Goes to ask user time
}

//---------------------------------------------------------------
// Name: plantMenu
// PreCondition: None
// PostCondition: Prints out plants
//---------------------------------------------------------------
void plantMenu() {
	cout << endl;
	cout << "\t1. Flower" << endl
		 << "\t2. Vegetable" << endl
		 << "\t3. Tree" << endl;
}

//---------------------------------------------------------------
// Name: simulateTime
// PreCondition: Garden object
// PostCondition: Gets the amount of time to run simulation
//---------------------------------------------------------------
void simulateTime(Garden& garden) {
	int time;
	int test = 0;
	const int key = 1;
	
	while (test != key) {
		cout << "How many months would you like to simulate?" << endl;
		cin >> time;

		if (time > 0) { //Checks if valid input
			test = key;
		}
	}
	garden.tick(time); //Sends the time selected to tick
}


//---------------------------------------------------------------
// Name: main
// PreCondition: None
// PostCondition: Starts program
//---------------------------------------------------------------
int main() { //START PROGRAM HERE
	menu();
	return 0;
}
