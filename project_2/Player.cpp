/*****************************************************************
* File:		Player.cpp
* Project:	CMSC 202 Project 2, Spring 2017
* Author:	Daniel Roh
* Date:		3/7/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the player.cpp file needed for project 2.
*	The program has all the class functions needed for player.cpp
*****************************************************************/


#include "Player.h"

//---------------------------------------
// Name: Player
// PreCondition: none
// PostCondition: Makes a player object
//---------------------------------------
 Player::Player(){
 }

 //--------------------------------------------
 // Name: Player
 // PreCondition: A valid string of player name
 // PostCondition: Makes a object
 //--------------------------------------------
Player::Player(string name) {
  m_name = name;
  m_lost = false;
  m_extraTurn = false;
}

//---------------------------------------
// Name: PlayCard
// PreCondition: none
// PostCondition: Return a card
//---------------------------------------
Card Player::PlayCard() {
  int vSize;
  int card;
  int x = 1;
  Card temp;
  vSize = (int)m_hand.size(); //Return vector size

  while (x == 1) { //Protection for invalid card
    cout << "Choose a card to play\n";
    cin >> card;

    if (m_hand[card].GetType() == 0) {
      cout << "Invalid Card choice!!!\n";
      cout << "Please choose a card to play\n";
    }else if (card < vSize || card >= 0) { //if user choice is in the range
      x = 0;
    }
    else {
      cout << "Invalid Card choice!!!\n";
      cout << "Please choose a card to play\n";
    }
  }

  temp = m_hand.at(card); 
  m_hand.erase(m_hand.begin() + card); //Removes card from hand

  return temp;
}

//-------------------------------------------------
// Name: LoseCard
// PreCondition: A valid int of the card location
// PostCondition: Returns the removed card
//--------------------------------------------------
Card Player::LoseCard(int lose) {
  int vSize;
  Card temp;
  vSize = (int)m_hand.size();

  if (lose < 0 || lose > vSize) { //Value checking
    lose = 0; //Sets the card to lose to 0
  }

  temp = m_hand.at(lose); //Stores the card to be removed so it can be returned
  m_hand.erase(m_hand.begin() + lose); //Removes the x item from the hand

  return temp;
}

//---------------------------------------------------------
// Name: HasCard
// PreCondition: none
// PostCondition: Returns a bool of is the player has cards
//---------------------------------------------------------
bool Player::HasCards() {
  int vSize;
  vSize = (int)m_hand.size(); //Looks for the vector size
  
  if (vSize = 0) //Returns false if there are 0 cards
    return false; 
  else if (m_hand[0].GetType() == 0) //Return false if the last card in hand is a bomb card
    return false;
  else
    return true; //Returns true if there are more then 0 cards
}

//-----------------------------------------------------
// Name: HasLost
// PreCondition: none
// PostCondition: Returns a bool if the player has lost
//-----------------------------------------------------
bool Player::HasLost() {
  if (m_lost == true)
    return true; //If the player lost return true
  else
    return false; //If the player did not lose return false
}

//-------------------------------------------------------------
// Name: HasExtraTurn
// PreCondition: none
// PostCondition: Returns a bool if the player has a extra turn
//-------------------------------------------------------------
bool Player::HasExtraTurn() {
  if (m_extraTurn == true)
    return true; //If the player does have a extra turn
  else
    return false; //If the player does not have a turn
}

//-------------------------------------------------
// Name: AddToHand
// PreCondition: A valid card
// PostCondition: Returns a int of the type of card
//-------------------------------------------------
int Player::AddToHand(Card add) {
  m_hand.push_back(add); //Add card to hand
  int x = (int)m_hand.size(); //Gets the new size of m_hand

  return  m_hand[x - 1].GetType(); //Return the type of the card
}

//---------------------------------------
// Name: GetName
// PreCondition: none
// PostCondition: Return player name
//---------------------------------------
string Player::GetName() {
  return m_name;
}

//---------------------------------------
// Name: DisplayHand
// PreCondition: none
// PostCondition: Shows player hand
//---------------------------------------
void Player::DisplayHand() {
  int vSize;
  vSize = (int)m_hand.size(); //Gets the size of the vector
  cout << "\nYour hand has:" << endl;

  for (int x = 0; x < vSize; x++) {
    if (m_hand[x].GetType() == 0) {
      //Do nothing;
    }
    else {
      cout << "   " << x << ". " << m_hand[x].ToString() << endl; //Prints out the hand
    }
  }
}

//----------------------------------------------
// Name: GetNumberOfCards
// PreCondition: none
// PostCondition: Return number of cards in hand
//----------------------------------------------
int Player::GetNumberOfCards() {
  return (int)m_hand.size(); //Returns the size of the vector
}

//---------------------------------------
// Name: ReturnBomb
// PreCondition: none
// PostCondition: Return bomb card
//---------------------------------------
Card Player::ReturnBomb() {
  int vSize;
  Card temp;
  vSize = (int)m_hand.size(); //Sends card to be removed from hand
  
  temp = LoseCard(vSize); 
  
  return temp; //Returns the card
}

//---------------------------------------
// Name: SetLost
// PreCondition: A bool to update
// PostCondition: Updates m_lost
//---------------------------------------
void Player::SetLost(bool lost) {
  m_lost = true;
}

//---------------------------------------
// Name: SetExtraTurn
// PreCondition: A bool to update
// PostCondition: Updates m_extraTurn
//---------------------------------------
void Player::SetExtraTurn(bool turn) {
  m_extraTurn = turn;
}
