/*****************************************************************
* File:		Player.cpp
* Project:	CMSC 202 Project 3, Spring 2017
* Author:	Daniel Roh
* Date:		3/23/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the Sequencer.cpp file needed for project 3.
*	The File has the main menu and calls functions in DNA.cpp
*****************************************************************/

#include "Sequencer.h"

//---------------------------------------
// Name: Sequencer
// PreCondition: A valid file name
// PostCondition: Sets file name
//---------------------------------------
Sequencer::Sequencer(string fileName) {
  m_fileName = fileName; //Set File name
  readFile(); //Go to ReadFile to read in data
  mainMenu(); //Go to main menu
}

//-------------------------------------------------
// Name: ~Sequencer
// PreCondition: None
// PostCondition: Removes all dynamic memory items
//-------------------------------------------------
Sequencer::~Sequencer() {
  m_dna.~DNA();
}

//-------------------------------------------------
// Name: readFile
// PreCondition: A valid file name
// PostCondition: A of chars linked list
//-------------------------------------------------
void Sequencer::readFile() {
  char letter;
  string fileName; 
  ifstream inFile;
  ifstream outFile;
  //NOTE: Driver.cpp gives the file name to Sequence constructor so no need to ask use for file name

  cout << "Opening the file...." << endl; //DEBUG
  
  inFile.open(m_fileName.c_str()); //Load the file name
  
  if (inFile.is_open()) { //If the file opens
    cout << "Sucess opening file" << endl; //DEBUG
    cout << "Loading File....." << endl; //DEBUG
    DNA();//Calls DNA constructor
    
    while (!inFile.eof()) {
      inFile >> letter;
      m_dna.InsertEnd(letter); //Sends char to get inserted to the list
    }
  }
  else { //If the file is not found
    cout << "Error, unable to open or find file\n\n";
    exit(1); //End program
  }
}

//-------------------------------------------------
// Name: mainMenu
// PreCondition: None
// PostCondition: None
//-------------------------------------------------
void Sequencer::mainMenu() {
  int command = 1;
  int x;
  string dnaName, codeLetter;
  cout << endl << "Welcome to the DNA Sequencer application" << endl;
  
  while(command != 5) {
    cout << "What would you like to do?(1-5)" << endl;
    cout << "\t1. Display Sequencer (Leading Strand)" << endl;
    cout << "\t2. Display Sequencer (Base Pairs)" << endl;
    cout << "\t3. Inventory Basic Amino Acids" << endl;
    cout << "\t4. Sequence Entire DNA Strand" << endl;
    cout << "\t5. Exit" << endl;
    cout << "Input: ";
    
    cin >> command; //Get user command
    cout << endl; //Formatting
    
    switch (command) {
    case 1: //Display leading strands of DNA
      cout << "Displaying Leading strands" << endl;
      x = 1;
      m_dna.Display(x); //Calls Display and sends 1 to tell display to show leading strands
      break;
      
    case 2: //Display Base Pairs of DNA
      cout << "Displaying Base Pairs...." << endl;
      x = 2;
      m_dna.Display(x); //Calls Display and sends 2 to tell display to show base pairs
      break;
      
    case 3: //Display the Inventory of 20 Basic Amino Acids
      cout << "Inventory Basic Amino Acids" << endl;
      dnaName = "Isoleucine";
      codeLetter = "ATT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Leucine";
      codeLetter = "CTT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Valine";
      codeLetter = "GTT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Phenylalanine";
      codeLetter = "TTT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Methionine";
      codeLetter = "ATG";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Cysteine";
      codeLetter = "TGT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Alanine";
      codeLetter = "GCT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Glycine";
      codeLetter = "GGT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Proline";
      codeLetter = "CCT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Threonine";
      codeLetter = "ACT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Serine";
      codeLetter = "TCT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Tyrosine";
      codeLetter = "TAT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Tryptophan";
      codeLetter = "TGG";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Glutamine";
      codeLetter = "CAA";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Asparagine";
      codeLetter = "AAT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Histidine";
      codeLetter = "CAT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Glutamic acid";
      codeLetter = "GAA";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Aspartic acid";
      codeLetter = "GAT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Lysine";
      codeLetter = "AAA";
      m_dna.NumAmino(dnaName, codeLetter);
      
      dnaName = "Arginine";
      codeLetter = "CGT";
      m_dna.NumAmino(dnaName, codeLetter);
      
      cout << endl; //Formatting
      break;
      
    case 4: //Display the sequence of DNA strand
      cout << "Identifing DNA Sequences" << endl;
      m_dna.Sequence();
      break;
      
    case 5: //Exit program
      cout << "Ending program" << endl;
      //Destructor runs after the main has finished
      break;
      
    default: //If the user enters in a invalid value
      cout << endl << "Invalid Command!!!!!" << endl; //Debug Case
      command = 1;
    }
    
  }

}
