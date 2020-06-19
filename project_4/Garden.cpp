/*****************************************************************
* File:		Garden.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is Garden.cpp
*	This file works on the the child classes
*****************************************************************/
#include "Garden.h"

//-------------------------------------------------
// Name: Garden
// PreCondition: None
// PostCondition: Makes a Garden object
//-------------------------------------------------
Garden::Garden() {
  	m_garden;
	m_gardenSize = 0;
	m_month = 0;
}

//-------------------------------------------------
// Name: ~Garden
// PreCondition: None
// PostCondition: Removes objects from memory
//-------------------------------------------------
Garden::~Garden() {
	for (int x = 0; x < m_garden.size(); x++) {
		delete m_garden.at(x);
	}
}

//---------------------------------------------------------------
// Name: addPlant
// PreCondition: Int with type of plant and amount of that plant
// PostCondition: Makes a DNA object
//---------------------------------------------------------------
void Garden::addPlant(int type, int quantity) {
	switch (type) {
	case 1:
		//cout << "Flower" << endl;//debug
		m_gardenSize = quantity;

		for (int x = 0; x < quantity; x++) { 
			//cout << "Test: " << m_garden.size() + 1 << "Plant added" << endl; //DEBUG

			Plant *plant1 = new Flower(); //Make a new plant flower
			m_garden.push_back(plant1); //Add plant to vector
		}
		break;

	case 2:
		//cout << "Veg" << endl;//debug
		m_gardenSize = quantity;

		for (int x = 0; x < quantity; x++) {
			//cout << "Test: " << m_garden.size() + 1 << "Plant added" << endl; //DEBUG

			Plant *plant2 = new Vegetable(); //Make a new plant Vege
			m_garden.push_back(plant2); //Add plant to vector
		}
		break;

	case 3:
		//cout << "Tree" << endl;//debug
		m_gardenSize = quantity;

		for (int x = 0; x < quantity; x++) {
			//cout << "Test: " << m_garden.size() + 1 << "Plant added" << endl; //DEBUG

			Plant *plant3 = new Tree(); //Make a new plant Tree
			m_garden.push_back(plant3); //Add plant to vector
		}
		break;

	default:
		cout << "Invalid type: Plant set to default Flower" << endl;
		m_gardenSize = quantity;

		Plant *plant1 = new Flower(); //Make a new plant flower
		m_garden.push_back(plant1); //Add plant to vector
	}
}

//-------------------------------------------------
// Name: tick
// PreCondition: int of months
// PostCondition: Updates objects
//-------------------------------------------------
void Garden::tick(int t) {
	while (getMonths() != t) {
		cout << "Month: " << getMonths() + 1 << endl; //Shows the current month

		for (int x = 0; x < m_garden.size(); x++) {
			m_garden.at(x)->tick(); //Updates object
			//*m_garden[x] << cout;
		}
		tick(); //Call print out tick
		m_month = m_month + 1; //Adds a month
	}
	cout << endl << "Simulation time reached" << endl;//DEBUG
}

//-------------------------------------------------
// Name: tick
// PreCondition: none
// PostCondition: Prints out objects
//-------------------------------------------------
void Garden::tick() {
	for (int x = 0; x < m_garden.size(); x++) {
	  cout << " " << x + 1 << ": "; //Formmating
	  *m_garden.at(x) << cout; //print out items in the m_garden vector via -> month: type (Age : alive : special : diseased)
	}	
}

//-------------------------------------------------
// Name: getSize
// PreCondition: None
// PostCondition: Return vector size
//-------------------------------------------------
int Garden::getSize() {
	return m_gardenSize;
}

//-------------------------------------------------
// Name: getMonths
// PreCondition: None
// PostCondition: Return months
//-------------------------------------------------
int Garden::getMonths() {
	return m_month;
}

