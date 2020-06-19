/*****************************************************************
* File:		Item.cpp
* Project:	CMSC 202 Project 5, Spring 2017
* Author:	Daniel Roh
* Date:		5/11/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is Item.cpp
*	This file makes item objects and has getters for the object
*****************************************************************/

#include "Item.h"

//-------------------------------------------------
// Name: Item
// PreCondition: None
// PostCondition: Make a item object
//-------------------------------------------------
Item::Item() {
	m_name = "Not";
	m_weight = 0;
}

//-------------------------------------------------
// Name: Item
// PreCondition: None
// PostCondition: Makes a item object
//-------------------------------------------------
Item::Item(string iName, float iWeight) {
	m_name = iName;
	m_weight = iWeight;
}

//-------------------------------------------------
// Name: GetName
// PreCondition: A made object
// PostCondition: Returns the name of object
//-------------------------------------------------
string Item::GetName() const {
	return m_name;
}

//-------------------------------------------------
// Name: GetWeight
// PreCondition: A made object
// PostCondition: Returns the weight of object
//-------------------------------------------------
float Item::GetWeight() const {
	return m_weight;
}