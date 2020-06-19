/****************************************************************
* File:		Card.cpp
* Project:	CMSC 202 Project 2, Spring 2017
* Author:	Daniel Roh
* Date:		3/7/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
* This file is the card.cpp file needed for project 2.
* The program has all the class functions needed for card.cpp
***************************************************************/

#include "Card.h"
//-----------------------------------
// Name: Card
// PreCondition: none
// PostCondition: Returns card object
//-----------------------------------
Card::Card(){
}

//---------------------------------------
// Name: Card
// PreCondition: A valid int and a string
// PostCondition: Returns Card object
//---------------------------------------
Card::Card(int type, string name) {
  m_type = type;
  m_desc = name;
}

//---------------------------------------------
// Name: GetType
// PreCondition: none
// PostCondition: Returns the int value of card
//---------------------------------------------
int Card::GetType() {
  return m_type;
}

//------------------------------------------------------------------
// Name: ToString
// PreCondition: none
// PostCondition: Returns a string of the cards type and discription
//------------------------------------------------------------------
string Card::ToString() {
  //return m_type + " " + m_desc;
  string type;

  switch(GetType()){
  case 1:
    type = "Defuse: ";
    break;
  case 2:
    type = "Attack: ";
    break;
  case 3:
    type = "Skip: ";
    break;
  case 4:
    type = "See into the Future: ";
    break;
  case 5:
    type = "Shuffle: ";
    break;
  default:
    type = "";
  }

  return type + m_desc;
}

