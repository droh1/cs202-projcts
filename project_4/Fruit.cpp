/*****************************************************************
* File:		Fruit.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the Fruit.cpp
*	The file contains the class deff for fruit
*****************************************************************/
#include "Fruit.h"

//-------------------------------------------------
// Name: Fruit
// PreCondition: None
// PostCondition: Makes a fruit object
//-------------------------------------------------
Fruit::Fruit() {
	m_color = "Green";
}

//-------------------------------------------------
// Name: GetColor
// PreCondition: None
// PostCondition: Returns color
//-------------------------------------------------
string Fruit::GetColor() {
	return m_color;
}

