/*****************************************************************
* File:		ReadyDelivery.cpp
* Project:	CMSC 202 Project 5, Spring 2017
* Author:	Daniel Roh
* Date:		5/11/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is ReadyDelivery.cpp
*	This file takes in the file names and stores 
*	the data in vectors
*****************************************************************/

#include "ReadyDelivery.h"

//-------------------------------------------------
// Name: ReadyDelivery
// PreCondition: NONE
// PostCondition: None
//-------------------------------------------------
ReadyDelivery::ReadyDelivery() {

}

//---------------------------------------------------------
// Name: ReadyDelivery
// PreCondition: 3 valid file types (truck, delivery, item)
// PostCondition: Sets the file names
//---------------------------------------------------------
ReadyDelivery::ReadyDelivery(string truckFile, string deliveryFile, string ItemFile) {
	m_truckFile = truckFile;
	m_deliveryFile = deliveryFile;
	m_itemFile = ItemFile;

	LoadTruck();
	LoadDelivery();
	LoadItem();

	cout << "Start Time : 0" << endl << endl;
}

//-------------------------------------------------
// Name: LoadTruck
// PreCondition: A loaded file
// PostCondition: Adds the truck to the vector
//-------------------------------------------------
void ReadyDelivery::LoadTruck() {
	int cap;
	string Name;
	
	ifstream inFile;
	ifstream outFile;

	//cout << "Opening the file...." << endl; //DEBUG

	inFile.open(m_truckFile.c_str()); //Load the file name

	if (inFile.is_open()) { //If the file opens
		//cout << "Loading Deliveries....." << endl; //DEBUG

		while (!inFile.eof()) { //Reads in until end of file
			inFile >> Name;
			inFile >> cap;

			if (inFile.eof()) { //Break at eof
				break;
			}

			Truck<Item, MAX_CAPACITY> truck(Name, cap); //Make a truck object
			m_truck.push_back(truck); //Put object into vector
			
			/*  Note to self, memoery does not need to be alocated to truck,
				just the object needs to be placed into the vector */
		}
	}
	else { //If the file is not found
		cout << "Error, unable to open or find file\n\n";
		exit(1); //End program
	}
	cout << "Trucks loaded: " << m_truck.size() << endl;
	inFile.close(); //Close File
}

//-------------------------------------------------
// Name: LoadDelivery
// PreCondition: A loaded file
// PostCondition: Adds the delivey to the vector
//-------------------------------------------------
void ReadyDelivery::LoadDelivery() {
	int items;
	int min;
	string Name;

	ifstream inFile;
	ifstream outFile;

	//cout << "Opening the file...." << endl; //DEBUG

	inFile.open(m_deliveryFile.c_str()); //Load the file name

	if (inFile.is_open()) { //If the file opens
		//cout << "Loading Deliveries....." << endl; //DEBUG

		while (!inFile.eof()) { //Reads in items until end of file
			inFile >> Name;
			inFile >> items;
			inFile >> min;
			
			if (inFile.eof()) { //Break at eof
				break;
			}

			Delivery ndelivery(Name, items, min); //Make a new item object
			m_delivery.push_back(ndelivery); //Adds the pointer to the array
		}
	}
	else { //If the file is not found
		cout << "Error, unable to open or find file\n\n";
		exit(1); //End program
	}
	cout << "Deliveries Loaded: " << m_delivery.size() << endl;
	inFile.close(); //Close File
}

//-------------------------------------------------
// Name: LoadItem
// PreCondition: A loaded file
// PostCondition: Adds the item to the vector
//-------------------------------------------------
void ReadyDelivery::LoadItem() {
	float weight;
	string itemName;

	ifstream inFile;
	ifstream outFile;

	//out << "Opening the file...." << endl; //DEBUG

	inFile.open(m_itemFile.c_str()); //Load the file name

	if (inFile.is_open()) { //If the file opens
		//cout << "Loading Items....." << endl; //DEBUG
		
		while (!inFile.eof()) { //Reads in items until end of file
			inFile >> itemName;
			inFile >> weight;

			if (inFile.eof()) { //Break at eof
				break;
			}

			Item nItems(itemName, weight); //Make a new item object
			m_item.push_back(nItems); //Adds the pointer to the array
		}
	}
	else { //If the file is not found
		cout << "Error, unable to open or find file\n\n";
		exit(1); //End program
	}
	cout << "Items Loaded: " << m_item.size() << endl;
	inFile.close(); //Close File
}

//-------------------------------------------------
// Name: GetTruck
// PreCondition: A made vector of Trucks
// PostCondition: Returns the truck vector
//-------------------------------------------------
vector<Truck<Item, MAX_CAPACITY> >& ReadyDelivery::GetTruck(){
	return m_truck;
}

//-------------------------------------------------
// Name: GetDelivery
// PreCondition: A made vector of delivery
// PostCondition: retruns the delivery vector
//-------------------------------------------------
vector<Delivery> ReadyDelivery::GetDelivery(){
	return m_delivery;
}

//-------------------------------------------------
// Name: GetItem
// PreCondition: A made vector item
// PostCondition: returns the item vector
//-------------------------------------------------
vector<Item> ReadyDelivery::GetItem(){
	return m_item;
}

