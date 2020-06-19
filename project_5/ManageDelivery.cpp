/*****************************************************************
* File:		ManageDelivery.cpp
* Project:	CMSC 202 Project 5, Spring 2017
* Author:	Daniel Roh
* Date:		5/11/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is ManageDelivery.cpp
*	This file works distrbutes the deliverys to the trucks
*****************************************************************/

#include "ManageDelivery.h"
vector<int>sizes;//Global var

//------------------------------------------------------
// Name: ManageDelivery
// PreCondition: A made vector for Truck, Delivery, Item
// PostCondition: Loads delivery into trucks
//------------------------------------------------------
ManageDelivery::ManageDelivery(vector<Truck<Item, MAX_CAPACITY> > truck, vector<Delivery> delivery, vector<Item> item) {
	//int i = 0;
	int u = 0; //Counter
	//int x = 0;
	int y = 0; //Variable for a later loop
	int test = 0; //Value to compaire values
	int value = 0; //Value to store total
	int theTruck = 0; //Truck counter
	m_truck = truck;
	m_delivery = delivery;
	m_item = item;

	//Splitting orders into groups of sizes
	for (int y = 0; y < m_delivery.size(); y++) { //For items
		value = value + m_delivery.at(y).GetNumItem(); //Add up the number of items

		if (value >= m_truck.at(0).GetCapacity()) { //If the items are more then the cap
			value = value - m_delivery.at(y).GetNumItem(); //Remove that last item
			sizes.push_back(value); //Place number into vector
			value = m_delivery.at(y).GetNumItem(); //reset value
		}
	}
	if (value != 0) { //If there is a remaining order
		sizes.push_back(value);
	}
	value = 0;

	//Past here should have all items neede to be delivered placed into sizes for values
	for (int x = 0; x < m_delivery.size(); x++) { //In vector of delivery
		value = value + m_delivery.at(x).GetNumItem(); //Add up the delivery values

		if (value == sizes.at(u)) { //If the value equals the item calculated earlier 
			for (y; y <= x; y++) {
					m_truck.at(test).AddDelivery(m_delivery.at(y)); //Add delivery items to m_truck
				}
			if (test == m_truck.size() - 1) { //Reset truck to 1 again if another truck is needed
				test = 0;//Reset test
			}
			else {
				test = test + 1; //Move to next truck
			}
		u = u + 1; //move the sizes vector by one
		value = 0; //Reset value
		}
	}
	StartDelivery();
}

//-------------------------------------------------
// Name: StartDelivery
// PreCondition: A loaded truck
// PostCondition: Loads the truck with items
//-------------------------------------------------
void ManageDelivery::StartDelivery() {
	int counter = 1;
	int loadingTime = 10;
	bool fCase = false;
	vector< Delivery> temp;
	vector<int> sizesCpy = sizes;
	for (int x = 0; x < m_truck.size(); x++) { //For Truck
		temp = m_truck.at(x).GetDelivery(); //Get the delivery for truck and place into temp

		cout << endl << "---------- Loading Truck " << x + 1 << " ----------" << endl;//DEBUG
		m_truck.at(x).SetTime(m_truck.at(x).GetTime() + loadingTime); //Update time

		for (int t = 0; t < sizes.at(x); t++) { //Load the amount of items in sizes
			m_truck.at(x).AddItem(m_item.at(0)); //Add the first item into truck
			cout << t + 1 << " item: " << m_item.at(0).GetName() << " Loaded on Truck " << x + 1 << endl;
			m_item.erase(m_item.begin()); //Delete the first item

			if (m_item.size() == 0) {//If items run out
				break;
			}
		}
		sizesCpy.erase(sizesCpy.begin()); //Removes the first item in sizesCpy

		if (sizesCpy.size() == 0) { //If the sizesCpy = 0
			break;
		}
		if (m_item.size() == 0) {//If items run out??
			break;
		}
	}

	DeliverItem(m_delivery.size()); //Start delivery

	if (m_delivery.size() != 0) { //If there are still more deliverys to do
		StartDelivery(); //Restart 
	}
	else { //Show whats left then end
		DisplayItemLeft();
		cout << "END OF PROGRAM" << endl;
	}
}

//-------------------------------------------------
// Name: DeliverItem
// PreCondition: A truck with loaded items
// PostCondition: Delivers the items 
//-------------------------------------------------
void ManageDelivery::DeliverItem(int j) {
	int timeUpdate;
	int counterSize = 0;

	
	for (int x = 0; x < m_truck.size(); x++) { //For Trucks 
		cout << endl << "++++++++++ Delivery Truck " << x + 1 << "++++++++++" << endl;

		for (int i = 0; i <= j; i++) { //For deliveries (Note to self, there can be more then truck deliverys!! (derp me(T.T))
			counterSize = counterSize + m_delivery.at(0).GetNumItem(); //Update counter
			timeUpdate = m_truck.at(x).GetTime() + m_delivery.at(0).GetRTMinute(); //Get new time
			m_truck.at(x).SetTime(timeUpdate); //Update time

			cout << "------- Order " << i + 1 << " -------" << endl;
			cout << "Delivery Time: " << m_truck.at(x).GetTime() << endl;
			cout << "Delivery for: " << m_delivery.at(0).GetName() << endl;
			cout << "Items Delivered: " << m_delivery.at(0).GetNumItem() << endl;
			m_delivery.erase(m_delivery.begin()); //Remove completed delivery

			if (counterSize == sizes.at(0)) { //If the number added equals one calculated before
				counterSize = 0; //Reset counter
				sizes.erase(sizes.begin()); //Remove the number the calculated values
				break; //Break to avoid adding more to same truck
			}
			
			if (m_delivery.size() == 0) {//If there is no more deliverys left but somehow there is still a value in sizes
				break; 
			}
		}
		if (sizes.size() == 0) { //If there is nothing for truck the next truck to print out
			break;
		}
	}
}

//-------------------------------------------------
// Name: DisplayItemLeft
// PreCondition: A item vector
// PostCondition: Shows if there are items left
//-------------------------------------------------
void ManageDelivery::DisplayItemLeft() {
	cout << endl << "All Deliveries have been finished" << endl; //DEBUG
	cout << "====== Items Left After Deliveries ======" << endl;
	//Show items left if any
	if (m_item.size() != 0) { //If there is anything left
		for (int x = 0; x < m_item.size(); x++) { 
			cout << "Item " << x + 1 << ": " << m_item.at(x).GetName() << " - Weight: " << m_item.at(x).GetWeight() << endl;
		}
	}
	else { //If there is nothing left
		cout << "No items left" << endl;
	}
	cout << endl << endl; //Formatting
}