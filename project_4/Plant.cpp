/*****************************************************************
* File:		Plant.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the Plant.cpp
*	The file contains the class deff plant
*****************************************************************/
#include"Plant.h"

//-------------------------------------------------
// Name: Plant
// PreCondition: None
// PostCondition: Makes a plant object
//-------------------------------------------------
Plant::Plant() {
	m_size = 0;
	m_isDiseased = false;
	m_isAlive = true;
	srand(time(NULL)); //Make a seed Note to self, the seed needs to be declaed once or the same number will be called
}

//-------------------------------------------------
// Name: ~Plant
// PreCondition: None
// PostCondition: Removes obj
//-------------------------------------------------
Plant::~Plant() { //Virtual

}

//-------------------------------------------------
// Name: GetIsDiseased
// PreCondition: None
// PostCondition: Get Diseased status
//-------------------------------------------------
bool Plant::GetIsDiseased() {
	return m_isDiseased;
}

//-------------------------------------------------
// Name: GetIsAlive
// PreCondition: None
// PostCondition: Returns alive status
//-------------------------------------------------
bool Plant::GetIsAlive() {
	return m_isAlive;
}

//-------------------------------------------------
// Name: GetSize
// PreCondition: None
// PostCondition: Return size of plant
//-------------------------------------------------
int Plant::GetSize() {
	return m_size;
}

//-------------------------------------------------
// Name: SetSize
// PreCondition: int to set for size
// PostCondition: Sets size
//-------------------------------------------------
void Plant::SetSize(int size) {
	m_size = size;
}

//-------------------------------------------------
// Name: SetIsAlive
// PreCondition: bool to set for alive
// PostCondition: Set alive status
//-------------------------------------------------
void Plant::SetIsAlive(bool isAlive) {
	m_isAlive = isAlive;
}

//-------------------------------------------------
// Name: SetIsDiseased 
// PreCondition: bool to set for diseased
// PostCondition: Updates diseased status
//-------------------------------------------------
void Plant::SetIsDiseased(bool isDiseased) {
	m_isDiseased = isDiseased;
}
