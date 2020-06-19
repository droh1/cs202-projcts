/****************************************************************
 * File:    Game.cpp
 * Project: CMSC 202 Project 2, Spring 2017
 * Author:  Daniel Roh
 * Date:    3/7/17
 * Section: 1066
 * E-mail:  droh1@umbc.edu
 *
 *	This file is the game.cpp file needed for project 2.
 *	The program has all the class functions needed for game.cpp
 ***************************************************************/


#include<stdlib.h>
#include<time.h>
#include "Game.h"

//---------------------------------------
// Name: Game
// PreCondition: none
// PostCondition: Sets game inital values
//---------------------------------------
Game::Game() {
  m_numPlayers = 0;
  m_deck;
  m_discard;
  PlayGame();
}

//---------------------------------------
// Name: SetNumPlayers
// PreCondition: A int value of players
// PostCondition: Sets x players
//---------------------------------------
void Game::SetNumPlayers(int players){
  int f;
  string name;

  if (players < 2 || players > 4) { //Program protection
    m_numPlayers = 2; //Default
  }
  else { 
    m_numPlayers = players;
  }

  cout << "Creating " << m_numPlayers << " players\n"; //DEBUG

  for (int x = 0; x < m_numPlayers; x++) {
    name = "Player "; //Resets the string
    stringstream convert; //for converting string
    f = x + 1;
    convert << f; //Converts the int to a string
    name += convert.str(); //Puts the converted string in to the player name

    Player p = name; //Creates a new player
    m_players[x] = p; //Puts player into array
  }
}

//---------------------------------------
// Name: Shuffle
// PreCondition: A deck with cards
// PostCondition: Returns a shuffled deck
//---------------------------------------
void Game::Shuffle() {
  int ran;
  int vSize = (int)m_deck.size(); //Gets the size of the deck
  int ySize; //For size of temp
  vector<Card> temp;

  //cout << "Shuffling the cards....." << endl;//DEBUG
  if (vSize == 0) { //If there are no cards in the deck
    cout << "There are no cards in the deck!!" << endl;
  }

  srand(time(NULL)); //Make a random seed

  for (int x = vSize - 1; x >= 0; x--) { //Shuffle
    ran = rand() % vSize; //Random number from 0 to vSize

    temp.push_back(m_deck.at(ran)); //Sets the value in to a temp vector

    //cout << "M_DECK CARDS: " << m_deck.at(x).GetType() << endl;//DEBUG
		
    while (ran < (vSize - 1)) {
      m_deck.at(ran) = m_deck.at(ran + 1); //Move all vector past ran over to fill the moved space
      ran++;
    }
    m_deck.pop_back(); //Remove the last value
    vSize = (int)m_deck.size(); //Update new size
  }

  ySize = (int)temp.size();
  for (int x = 0; x < ySize; x++) { //Sets the temp vector to the m_deck vector
    m_deck.push_back(temp.at(x)); //Putting cards back into the m_deck
    //cout << "CARD AT " << x << " " << temp.at(x).GetType() << endl;//DEBUG
  }
}

//----------------------------------------------
// Name: Peek
// PreCondition: A deck with cards
// PostCondition: Shows players the next x cards
//----------------------------------------------
void Game::Peek() {
  const int CARDS = 3; //Max amount of cards shown
  int vSize = (int)m_deck.size(); //Get Size of vector

  if (vSize == 2) { //If the deck only has 2 cards left
    cout << "The next two cards are: " << endl;
    for (int x = 0; x < vSize; x++) {
      cout << "\t" << m_deck[x].ToString() << endl;
    }
  }
  else if (vSize == 1) { //If the deck only has 1 card left
    cout << "The next card is: " << endl;
    for (int x = 0; x < vSize; x++) {
      cout << "\t" << m_deck[x].ToString() << endl;
    }
  }
  else if (vSize == 0) { //If the deck has no cards left
    cout << "!!!!There are no more cards in the deck\n!!!!";
  }
  else { //If the deck has 3 or more cards
    cout << "The next three cards are: " << endl;
    for (int x = 0; x < CARDS; x++) {
      cout << "\t" << m_deck[x].ToString() << endl;
    }
  }
}

//----------------------------------------------
// Name: DrawCard
// PreCondition: A deck with cards
// PostCondition: Gives a card to a players hand
//----------------------------------------------
Card Game::DrawCard() {
  int vSize = (int)m_deck.size();
  Card xCard;

  if (vSize == 0) {
    cout << "There are no more cards in the deck!!" << endl;
  }
  else {
    xCard = m_deck.at(vSize - 1); 
    m_deck.pop_back(); //Remove the card from the deck
  }
  return xCard;
}

int Game::HandleCard(int card) {
  switch (card) {
  case 0:
    cout << endl << "EXPLODING KITTEN!!!!!!!!" << endl;
    return 0; //Exp kitten
  case 1:
    cout << "You defused the kitten... for now." << endl;
    return 1; //Defuse
    break;
  case 2:
    return 2; //attack
  case 3:
    return 3; //skip
  case 4:
    return 4; //Peek
  case 5:
    Shuffle(); //Shuffle
    return 5;
  default:
    return 6; //normal card
  }
  return 6;
}

//---------------------------------------
// Name: PlayGame
// PreCondition: none
// PostCondition: Ends the game
//---------------------------------------
void Game::PlayGame() {
  const int CARDS = 4;
  const int C = 3;
  int t = 1, players, losers = 0, command;
  int temp, ok, choice, choice1;
  int numCards, l, action, fut;
  bool end, endGame = false;
  Card tempCard, cardPlayed, pastCard(0, "bomb");

  cout << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW" << endl;
  cout << "Welcome to EXPLODING KITTENS" << endl;
  cout << "A Game by Elan Lee, Shane Small, and Matthew Inman" << endl;
  cout << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW" << endl << endl;
  cout << "How many players are playing?" << endl;
  cout << "Choose from 2 to 4 players:" << endl;
  cin >> players;

  SetNumPlayers(players);
  LoadDeck("deck.txt");
  Shuffle();

  for (int x = 0; x < m_numPlayers; x++) { //Goes tho the players 
    for (int y = 0; y < CARDS; y++) { //Draws 4 cards
      tempCard = DrawCard();
      m_players[x].AddToHand(tempCard);
    }
  }
  AddBombCards("bomb.txt");
  Shuffle();
  cout << "Shuffling the cards....." << endl;
  cout << "\n\n\n"; //Formatting
  
  while (endGame == false) { //Control for looping commands in game
    for (int x = 0; x < players; x++) { //If the player has already lost
      if (m_players[x].HasLost() == true) {
	end = true;
	t = 0;
      }
      else { //If the player is still alive
	end = false; //Sets turn
	t = 1;//Reset while loop
      }
     
      if(m_numPlayers - 2 < losers){ //If one player is left and the game needs to finish
	endGame = true;
	end = true;
      }

      while (end == false) {
	cout << endl << m_players[x].GetName() << " What would you like to do?\n";
	
	while (t == 1) { //Program protection
	  cout << "1 - View Cards\n" << "2 - Play Card\n" << "3 - Draw Card\n";
	  cin >> command;
	  
	  if (command > 3 || 1 > command) { //If input is not 1 to 3
	    cout << "INVALID COMMAND\n\n";
	  }
	  else {
	    t = 0;
	  }
	}
	
	switch (command) {
	case 1:
	  m_players[x].DisplayHand();
	  t = 1; //Resets command;
	  break;
	  
	  //CASE 2
	case 2:
	  if (m_players[x].GetNumberOfCards() == 0) { //Checks if there any cards possble to play
	    cout << "You have no cards in your hand" << endl;
	  }
	  else {
	    m_players[x].DisplayHand(); //Display cards
	    cardPlayed = m_players[x].PlayCard(); //Get the most recent card played
	    action = HandleCard(cardPlayed.GetType()); //Gets the card type and sends to handle card
	    
	    switch (action) { //Show user what card was played
	    case 0:
	      cout << "\nEXPLODING KITTEN!!!\n";
	      break;
	    case 1:
	      cout << "You have defused the exploding kitten(whew) For now...\n";
	      break;
	    case 2:
	      cout << "You attacked add more here!!!!\n";
	      break;
	    case 3:
	      cout << "You skipped you turn\n";
	      end = true; //Sets the turn for player to true to skip
	      break;
	    case 4:
	      cout << "You peek into the future (ohhh)\n";
	      Peek();
	      break;
	    case 5:
	      cout << "You Shuffled the deck\n";
	      Shuffle();
	      break;
	    default:
	      cout << "You played a normal card\n";
	    }
	    
	    if ((cardPlayed.GetType() == pastCard.GetType()) || (cardPlayed.GetType() > 5 && pastCard.GetType() > 5)) { //If the last card played matches the card recently played or if last card and the played card are normal cards
	      int l = 1;
	      while (l == 1) {
		cout << endl << "You played a pair!!!\n Which player do you wish to steal a card from?\n";
		for (int y = 0; y < m_numPlayers; y++) {
		  if (m_players[y].HasLost() == true) { //If the player lost
		    //Do nothing
		  }
		  else if (m_players[x].GetName() == m_players[y].GetName()) { //To avoid stealing from self <--- STRING COMPAIRE
		    //Do nothing
		  }
		  else {
		    cout << m_players[y].GetName() << endl;
		  }
		}
		cin >> choice;
		
		if ((choice <= m_numPlayers + 1) && choice > 0) { //If input is from 1-4
		  if (choice != (x + 1)) { //If input is not themself
		    // for (int y = 0; y < m_numPlayers; y++) {
		      if (m_players[choice - 1].HasLost() == false) { //If the player has not lost
			l = 0; //Break
		      }
		      else{
			cout << "Invalid choice: This player has lost" << endl;
		      }
		  }
		  else
		    cout << "Invalid Choice: You cant steal a card from yourself" << endl;
		}
		else
		  cout << "Invalid choice"; //Tell user that the choice is incorrect
	      }
	      numCards = m_players[choice - 1].GetNumberOfCards(); //Get number of card selected player has
	      
	      for (int x = 0; x < numCards; x++) { //Print out cards the player choosen
		cout << "Card " << x << endl;
	      }
	      l = 1; //Resets conditional
	      while (l == 1) {
		cout << "Which Card do you wish to take from " << m_players[choice - 1].GetName() << "?\n";
		cin >> choice1;
		
		if (choice1 > numCards || choice1 < 1) { //Input protection
		  cout << "Invalid Card\n";
		}
		else {
		  l = 0;
		}
	      }
	      m_players[x].AddToHand(m_players[choice - 1].LoseCard(choice1)); //Takes the card from chosen player and put in players hand
	    }
	    
	    pastCard = cardPlayed; //Updates the past card with the most recent card
	    m_discard.push_back(cardPlayed); //Removes the card from player and adds it to the discard pile
	    temp = (int)m_discard.size(); //Get the location of the last item in discard
	    
	    int sizeTemp;
	    sizeTemp = m_discard.size(); //Get size of discard pile
	    m_discard[sizeTemp - 1].GetType(); //Set card Type to ok
	  }
	  t = 1; //Resets comand;
	  break;
	  
	  //DEFAULT SWITCH CASE HERE 
	default:
	  cout << "You drawed a card\n";
	  ok = HandleCard(m_players[x].AddToHand(DrawCard()));
	  
	  if (ok == 0) { //If a exploding kitten is drawn
	    Card defuse;
	    
	    if (m_players[x].HasCards() == false) { //If the player has no cards
	      cout << m_players[x].GetName() << " has no cards and has been blown up" << endl;
	      m_players[x].SetLost(true); //Player x lost
	    }
	    else {
	      cout << "\nPlay a card or LOSE!!!\n";
	      m_players[x].DisplayHand(); //Print out player hand
	      cout << "Choose your fate Muhaha Uhhh I mean..." << endl;
	      
	      defuse = m_players[x].PlayCard();
	      
	      int da = HandleCard(defuse.GetType()); //Get the card type 
	      if (da == 1) { //If the defuse card is played
		end = true; //End player turn
		
		int tempV = m_players[x].GetNumberOfCards(); //Get location of the last card
		Card putCard = m_players[x].LoseCard(tempV - 1); //Remove the last card
		m_deck.push_back(putCard); //Place the card back in the deck
		Shuffle(); //Shuffle the deck to move the bomb
	      }
	      else {
		cout << "Boom, the kitten exploded. " << m_players[x].GetName() << " is out of the game\n" << endl;
		m_players[x].SetLost(true); //Player lost
		losers = losers + 1; //Couter for losers
		end = true; //End player turn
	      }
	    }
	  }
	  
	  if (m_players[x].HasExtraTurn() == true) {
	    end = false;
	    m_players[x].SetExtraTurn(false); //Removes the extra turn
	  }
	  else {
	    end = true;
	  }
	}
      }
      cout << "There are " << (int)m_deck.size() << " in the deck left" << endl; //Update amount of cards left
      
      if ((m_numPlayers - 2) < losers) { //Checks if there is one player left
	endGame = true; //Ends game
      }
    }
  }
  //Game has now ended
  for (int x = 0; x < players; x++) { //Going tho the players
    if (m_players[x].HasLost() == false) { //If x player has not lost
      cout << endl << m_players[x].GetName() << " Wins the game!!!!!" << endl;
    }
    
  }
  cout << "\nThe game is now over, Closing game\n";
}

//---------------------------------------
// Name: LoadDeck
// PreCondition: A valid file name
// PostCondition: Return size of deck
//---------------------------------------
int Game::LoadDeck(string deck) {
  // const int SIZE = 27;//CHECK THIS VALUE TO MAKE SURE ITS THIS VALUE
  int sizeDeck;
  int value;
  string disc;

  ifstream inFile;
  ofstream outFile;
  
  inFile.open(deck.c_str()); //Opens file deck
  
  cout << "Loading deck....." << endl; //DEBUG
  if(inFile.is_open()){ //If the file opened
    while(inFile){ //While the file has values
      inFile >> value; //Read in ints
      inFile.ignore(2);//Needs avoid two chars for some reason
      //inFile.ignore('\n'); //Ignore spaces
      getline(inFile, disc); //Read in string
      Card c(value, disc); //Makes a card object with int and string
      m_deck.push_back(c); //Adds Card to vector
      // cout << "VALUE: " << value << "\tDisc:" << disc << endl;//DEBUG
    }
  
  inFile.close(); //Close File
  }
  else{
    cout << "Unable to open File\n";
  }
  
  cout << "The size of the deck is: " << (int)m_deck.size() << endl;//DEBUG
  sizeDeck = (int)m_deck.size() - 1; //Get the size of the deck

  return sizeDeck;//return size of deck
}

//---------------------------------------
// Name: AddBombCards
// PreCondition: A valid file name
// PostCondition: Returns size of deck
//---------------------------------------
int Game::AddBombCards(string bomb) {
  const int SIZE = 3;
  int value;
  string disc;
  
  ifstream inFile;
  ofstream outFile;
  
  inFile.open(bomb.c_str()); //Opens file deck
  
  cout << "Loading bombs......." << endl; //DEBUG
  
  while (inFile) {
    inFile >> value; //Read in ints
    inFile.ignore(2);
    getline(inFile, disc); //Read in strings
    Card c(value, disc); //Makes a card object
    m_deck.push_back(c); //Adds C to vector
    // cout << "VALUE: " << value << "\tDisc" << disc << endl; //DEBUG
  }

  inFile.close(); //Close File
  return SIZE; 
}


