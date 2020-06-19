/*****************************************************************
* File:		Vegetable.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the Vegetable.cpp
*	The file contains class deff for Vegetable
*****************************************************************/

#include "Vegetable.h"

//-------------------------------------------------
// Name: Vegetable
// PreCondition: None
// PostCondition: Makes Vegetabe object
//-------------------------------------------------
Vegetable::Vegetable() {
	m_color = "Green";
}

//-------------------------------------------------
// Name: Vegetable
// PreCondition: String color
// PostCondition: Makes a Vegetable object
//-------------------------------------------------
Vegetable::Vegetable(string color) {
	m_color = color;
}

//-------------------------------------------------
// Name: Vegetable
// PreCondition: None
// PostCondition: Updates objects alive status
//-------------------------------------------------
void Vegetable::die() { //Virtual
	SetIsAlive(false); //Sets the plant to be dead
}

//-------------------------------------------------
// Name: Vegetable
// PreCondition: None
// PostCondition: Harvests vegetables
//-------------------------------------------------
void Vegetable::harvest() {
	int mature = 5;

	if (GetSize() == mature) { //If fully mature
		cout << "Vegetable has been harvested" << endl;//DEBUG
		die(); //Calls die
	}
	else { //If not fully mature
		//cout << "Vege is not mature enough" << endl;//DEBUG
	}
}

//-------------------------------------------------
// Name: tick
// PreCondition: None
// PostCondition: Updates objects
//-------------------------------------------------
void Vegetable::tick(){ //Virtual
	int harvestTime = 4; //Size when vegetable gets harvested
	int random;
	int sick;

	if (GetSize() == harvestTime) {
		harvest();
		SetIsAlive(false);
	}

	SetIsDiseased(false); //Reset sick;

	random = rand() % 10 + 1; //Makes a random number from 1 to 100

	/*If the number is from 1-2 then the plant is sick.
	(2/10) chance of getting sick */

	if (random == 1 || random == 7) { //If sick is 1 or 7
		SetIsDiseased(true); //Plant becomes diseased 
	}

	if (GetIsDiseased() == true) { //If the vegetable is sick
		//cout << "Vegetable is sick, cant grow" << endl; //Does not increase size
	}
	else {
		SetSize(GetSize() + 1); //Updates Size
	}
}

//-------------------------------------------------
// Name: operator<<
// PreCondition: None
// PostCondition: Prints out object status
//-------------------------------------------------
ostream& Vegetable::operator<<(ostream & output){ //Virtual
	int mature = 5;

	if (GetIsAlive() == true) { //If alive
		if (GetSize() != mature) { //If not mature for harvest
			if (GetIsDiseased() == false) { //If not diseased
				output << "Vegetable (Alive : Not Harvestable : Not Diseased)" << endl;
			}
			else { //If diseased
				output << "Vegetable (Alive : Not Harvestable : Diseased)" << endl;
			}
		}
		else { //If mature for harvest
			if (GetIsDiseased() == false) { //If not diseased
				output << "Vegetable (Alive : Harvestable : Not Diseased)" << endl;
			}
			else { //If diseased 
				output << "Vegetable (Alive : Harvestable : Diseased)" << endl;
			}
		}
	}
	else { //If Harvested
		output << "Vegetable (Harvested)" << endl;
	}

	return output;
}