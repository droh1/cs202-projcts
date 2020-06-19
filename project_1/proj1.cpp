/*
*	File:		Project1.cpp
*	Project:	CMSC202 Project 1(Man Hunt), Spring 2017
*	Author:		Daniel Roh
*	Date:		03/10/17
*	Section:	CSSC202 - 6151
*	E-mail:		droh1@umbc.edu
*	
*	This program is a simmulation game of a investgator looking for a targer. 
*	The program starts by asking the user if they wish read a map they already have, make a new map, or exit to program.
*	Depending on which command the user selects, they will be able to load a map and search for a target, 
*	create a new map with custom locations for the target and investgator, or exit the program
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
//#include<stdio> //file test
using namespace std;

const int SIZE = 10; //Size of array to easily control array size

//Prototypes
void fileOpen();
void newMap();
void playGame(char[][SIZE], int, int, int, int);
bool updateMap(char[][SIZE], int, int, int, int);
void printMap(char[][SIZE]);

//------------------------------------------------------------------------------------
//Name: Main
//Pre-Condition: None
//Post-Condition: Returns 0
//------------------------------------------------------------------------------------ 
int main() {
	int input = 0; //User command value
	
	while (input != 3) {
	  cout << "Welcome to Man Hunt!!!\n" << "The ultra realistic game of finding a missing person\n";
	  cout << endl << "1 - Load map from file\n" << "2 - Enter custom map\n" << "3 - Exit\n\n";

	  cout << "What would you like do (Select 1-3): ";
	  cin >> input;

	  switch (input) {
	  case(1) : 
	    fileOpen(); //Opens a new map
	    break;
	  case(2) : newMap(); //Creates a new map
	    break;
	  case(3) : 
	    cout << "\nClosing program\n";  //Close the program
	    break;
	  default: cout << endl << "Invalid input\n\n";
	  }
	}
	return 0;
}


//------------------------------------------------------------------------------------
//Name: fileOpen
//Pre-Condition: None
//Post-Condition: None
//------------------------------------------------------------------------------------
void fileOpen() {
//	const int SIZE = 10; //Size of array
	int xLocationI, yLocationI, xLocationT, yLocationT; //(x,y) positions for Investgator(I) and Target(T)
	char map[SIZE][SIZE]; //Array for map
	string fileName; //String for input file

	ifstream inFile;
      	ofstream outFile;

      	inFile.open("test1.txt");//Open text1.txt
	
	if (inFile){ //Reading in file
	  cout << "Map Loaded\n\n"; //DEBUG

	  for (int x = 0; x < SIZE; x++) {//For Rows
	    for (int y = 0; y < SIZE; y++) {//For Col
	      inFile >> map[x][y]; //Reads in values to array
				
	      if (map[x][y] == 'I') { //When the Investigator is read in
		xLocationI = x;
		yLocationI = y;
	      }
	      if (map[x][y] == 'T') { //When the Target is read in
		xLocationT = x;
		yLocationT = y;
		map[x][y] = '_'; //Hiding the traget in the array
	      }
	    }
	  }

	  cout << endl << endl;

	  //Outputs map to user before game starts
	  for (int x = 0; x < SIZE; x++) { //Rows
	    for (int y = 0; y < SIZE; y++) { //Col
	      cout << map[x][y] << " "; //output values
	    }
	    cout << endl;
	  }
	  
	  playGame(map, xLocationI, yLocationI, xLocationT, yLocationT); //Sends the map and loactions to playGame
	}
	else{//If the files is not found 
	  cout << "Error, unable to find or open file\n\n";
	}

	inFile.close();//Close file
}


//------------------------------------------------------------------------------------
//Name: newMap
//Pre-Condition: None
//Post-Condition: None
//------------------------------------------------------------------------------------
void newMap() {
	int valueInvestX, valueInvestY, valueTargetX, valueTargetY; //Location values for investagor(I) and target(T)
	char mapNew[SIZE][SIZE]; //Array for the new map
	
	cout << "Welcome to the easy Man Hunt map creator\n\n";
	cout << "Please enter the X axis of the Investigator(0-9): ";
	cin >> valueInvestX;

	while (valueInvestX >= 10 || valueInvestX < 0) { //Program protection for invalid values
	  cout << "Invalid number, Please enter in a value from 0 to 9: ";
	  cin >> valueInvestX;
	}

	cout << "Please enter the Y axis of the Investigator(0-9): ";
	cin >> valueInvestY;

	while (valueInvestY >= 10 || valueInvestY < 0) { //Program protection for invalid values
	  cout << "Invalid number, Please enter in a value from 0 to 9: ";
	  cin >> valueInvestY;
	}

	cout << "Please enter the X axis of the Target(0-9): ";
	cin >> valueTargetX;

	while (valueTargetX >= 10 || valueTargetX < 0) { //Program protection for invalid values
	  cout << "Invalid number, Please enter in a value from 0 to 9: ";
	  cin >> valueTargetX;
	}

	cout << "Please enter the Y axis of the Target(0-9): ";
	cin >> valueTargetY;

	while (valueTargetY >= 10 || valueTargetY < 0) { //Program protection for invalid values
	  cout << "Invalid number, Please enter in a value from 0 to 9: ";
	  cin >> valueTargetY;
	}

	//ADD OVERLOADING PROTECTION HERE!!! IF XI = XT and YI = YT

	for (int x = 0; x < SIZE; x++) { //Rows
	  for (int y = 0; y < SIZE; y++) { //Col

	    mapNew[x][y] = '_'; //For blank space

	    if (x == valueInvestX) { //If the array value is where the investigator is
	      if (y == valueInvestY) {
		mapNew[x][y] = 'I';
	      }
	    }
	  }
	}

	cout << endl << endl;

	//Output map before game start
	for (int x = 0; x < SIZE; x++) { //For Rows
	  for (int y = 0; y < SIZE; y++) { //For Col
	    cout << mapNew[x][y] << " "; //Reads in values to array
	  }
	  cout << endl;
	}

	playGame(mapNew, valueInvestX, valueInvestY, valueTargetX, valueTargetY); //Starts the custom made game
}



//------------------------------------------------------------------------------------
//Name: playGame
//Pre-Condition: Needs to have a valid map with the prossesced values for investgator and target
//Post-Condition: None
//------------------------------------------------------------------------------------
void playGame(char map[SIZE][SIZE], int xLocationI, int yLocationI, int xLocationT, int yLocationT) {

	int command = 0; //User Command value
	bool found = false; //Bool for if game is over

	while (command != 6) {
	  cout << "Where would you like to search?\n";
	  cout << "1. Search North" << endl << "2. Search East"
	       << endl << "3. Search South" << endl << "4. Search West"
	       << endl << "5. See map" << endl << "6. Exit" << endl;
	  cin >> command;

	  switch (command) {
	  case 1: //Going North
	    if (xLocationI == 0) {
	      cout << "A wall blocks your path and you cant go any higher\n";
	      break;
	    }
	    map[xLocationI][yLocationI] = '*'; //Updates last positon
	    xLocationI -= 1;
	    found = updateMap(map, xLocationI, yLocationI, xLocationT, yLocationT);
	    if (found == true) {
	      command = 6;
	      break;
	    }
	    printMap(map);
	    break;
	    
	  case 2: //Going East
	    if (yLocationI  == (SIZE - 1)) {
	      cout << "A cliff stops you from walking any farer\n";
	      break;
	    }
	    map[xLocationI][yLocationI] = '*';
	    yLocationI += 1;
	    found = updateMap(map, xLocationI, yLocationI, xLocationT, yLocationT);
	    if (found == true) {
	      command = 6;
	      break;
	    }
	    printMap(map);
	    break;
	    
	  case 3: //Going South
	    if (xLocationI == (SIZE - 1)) {
	      cout << "A river stops you from going lower\n";
	      break;
	    }
	    map[xLocationI][yLocationI] = '*';
	    xLocationI += 1;
	    found = updateMap(map, xLocationI, yLocationI, xLocationT, yLocationT);
	    if (found == true) {
	      command = 6;
	    }
	    printMap(map);
	    break;
	    
	  case 4: //Going west
	    if (yLocationI == 0) {
	      cout << "A desnse forest blocks your path\n";
	      break;
	    }
	    map[xLocationI][yLocationI] = '*';
	    yLocationI -= 1;
	    found = updateMap(map, xLocationI, yLocationI, xLocationT, yLocationT);
	    if (found == true) {
	      command = 6;
	      break;
	    }
	    printMap(map);
	    break;
	    
	  case 5: //Shows map
	    cout << endl;
	    for (int x = 0; x < SIZE; x++) { //For Rows
	      for (int y = 0; y < SIZE; y++) { //For Col
		cout << map[x][y] << " "; //Reads in values to array
	      }
	      cout << endl;
	    }
	    break;
	    
	  case 6: //Invalid input
	    cout << "\nGive up... Exiting map :(\n\n";
	    break;
	    
	  default: cout << "Invalid input!!!\n\n";
	  }	  
	}
}


//------------------------------------------------------------------------------------
//Name: updateMap
//Pre-Condition: Needs a valid map as well as new X,Y values for Investgator
//Post-Condition: Return a bool value for if the target has been found
//------------------------------------------------------------------------------------
bool updateMap(char map[SIZE][SIZE], int xLocationI, int yLocationI, int xLocationT, int yLocationT){

	if (xLocationT == xLocationI) { //Checks if current location is where the target is
	  if (yLocationT == yLocationI) {
	    cout << "\n\n!!!!Target Found!!!!!\n\n\n\n";
	    return true;
	  }
	}
	map[xLocationI][yLocationI] = 'I'; //Shows new position
	return false;
}



//-------------------------------------------------------------------------
//Name: printMap
//Pre-Condition: Needs the char map array
//Post-Condition: None
//-------------------------------------------------------------------------

void printMap(char map[SIZE][SIZE]){
  
  for(int x = 0; x < SIZE; x++){
    for(int y = 0; y < SIZE; y++){
      cout << map[x][y] << " ";
    }
    cout << endl;
  }

}
