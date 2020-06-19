/*****************************************************************
* File:		Player.cpp
* Project:	CMSC 202 Project 3, Spring 2017
* Author:	Daniel Roh
* Date:		3/23/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the DNA.cpp file needed for project 3.
*	The file prosseses the data given to it via Sequencer.cpp
*****************************************************************/

#include "DNA.h"

//-------------------------------------------------
// Name: DNA
// PreCondition: None
// PostCondition: Makes a DNA object
//-------------------------------------------------
DNA::DNA() {
  m_head = NULL; //Start of list
  m_tail = NULL; //End of list
  m_size = 0;
}

//-------------------------------------------------
// Name: ~DNA
// PreCondition: None
// PostCondition: Removes the link list from memory
//-------------------------------------------------
DNA::~DNA() {
  Clear();
}

//-------------------------------------------------
// Name: InsertEnd
// PreCondition: A char
// PostCondition: Makes a linked list of chars
//-------------------------------------------------
void DNA::InsertEnd(char payload) {
  Nucleotide *newPayload = new Nucleotide; //Make new node
  newPayload->m_payload = payload; //Set the item into the linklist data space
  
  if (m_head != NULL) { //If this is not the first item
    m_tail->m_next = newPayload; //Set the tail to the m_next for payload
    newPayload->m_next = NULL; //Set newpayloads m_next to null
    m_tail = newPayload; //Set new tail
  }
  else { //If this is the first item
    newPayload->m_next = m_tail; //Makes m_next the tail
    m_tail = newPayload; //Set tail
    m_head = newPayload; //Set head	
  }
}


//--------------------------------------------------------------
// Name: Display
// PreCondition: A int of which type of prossessing
// PostCondition: Displays the nucleotides via pairs or singles
//--------------------------------------------------------------
void DNA::Display(int numStrand) {
  int cond = 0;
  Nucleotide *tempLocation = m_head;
  
  SizeOf(); //Call size to update size of list
  while(cond == 0){ //Condiaional for wrong input (Tho since the input is hard coded, this while loop is techneclly not needed!!)
    switch (numStrand) {
    case 1: //If the user just wants to see the nucleotides
      for (int x = 0; x < m_size; x++){
	cout << tempLocation->m_payload << endl;
	tempLocation = tempLocation->m_next; //Set the next location
      }
      cout << "END" << endl; //To tell user that this is the end of the sequence
      cout << m_size << " Nucleotides listed" << endl;
      cout << (m_size / 3) << " Trinucleotides listed" << endl;
      cond = 1; //Break while loop
      break;
      
      
    case 2: //If the user wanst to see the nucleotides and components
      for (int x = 0; x < m_size; x++) {
	if (tempLocation->m_payload == 'A') { //If the DNA is a A-T set
	  cout << tempLocation->m_payload << "-T" << endl;
	}
	else if (tempLocation->m_payload == 'G') { //If the DNA is a G-C set
	  cout << tempLocation->m_payload << "-C" << endl;
	}
	else if (tempLocation->m_payload == 'C') { //If the DNA is a C-G set
	  cout << tempLocation->m_payload << "-G" << endl;
	}
	else { //If the DNA is a T-A set
	  cout << tempLocation->m_payload << "-A" << endl;
	}
	
	tempLocation = tempLocation->m_next;
      }
      cout << "END" << endl; //To tell user that this is the end of the sequence
      cout << m_size << " Nucleotide pairs listed" << endl;
      cout << (m_size / 3) << " Trinucleotides listed" << endl;
      cond = 1; //Break while loop
      break;
      
    default: //If the user does not enter in a correct value
      cout << "Invalid option!!! Must be strange to meet this message o.0" << endl;
      cin >> numStrand;
    }
  }
}

//-------------------------------------------------------------------
// Name: NumAmino
// PreCondition: A valid string name and trinucleotide
// PostCondition: Counts the amount of each trinucleotide in the file
//-------------------------------------------------------------------
void DNA::NumAmino(string name, string trinucleotide) {
  const int LENGTH = 3;
  int count = 0;
  string tri;
  char *concat = new char[LENGTH]; //Char array
  Nucleotide *tempLocation = m_head;
  
  SizeOf(); //Update list size if not already done
  
  for (int y = 0; y < (m_size / 3); y++){
    for (int x = 0; x < LENGTH; x++) {
      concat[x] = tempLocation->m_payload; //Put the char in the array
      tempLocation = tempLocation->m_next; //Move to next item in list
    }
    string test(concat, LENGTH); //Concadinate char into string (cstring, numberofchars)
    tri = Translate(test); //Translate 
    
    if (tri == name) { //If the translated is the one we are looking for 
      count++;
    }	
  }
  
  cout << "\t"<< name << ": \t" << count << " identified" << endl; //Printing out the result
  
  delete[] concat; //Remove char array
  concat = NULL; //Clean up
}

//-----------------------------------------------------------------
// Name: Sequence
// PreCondition: None
// PostCondition: Displays the types of Trinucleotides in the file
//-----------------------------------------------------------------
void DNA::Sequence() {
  const int LENGTH = 3; //Number if Nucleotides in a Trinucleotide
  int count = 0;
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0 , h = 0,
    i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0,
    q = 0, r = 0, s = 0, t = 0;
  char *concat = new char[LENGTH]; //Char array
  string tri;
  Nucleotide *tempLocation = m_head; //Start the list at the head
  
  SizeOf(); //Update list size if not already done
  
  for (int y = 0; y < (m_size / 3); y++){
    for (int x = 0; x < LENGTH; x++) {
      concat[x] = tempLocation->m_payload; //Put the char in the array
      tempLocation = tempLocation->m_next; //Move to next item in list
    }
    
    string test(concat, LENGTH); //Concadinate char into string (cstring, numberofchars)
    tri = Translate(test); //Translate 
    
    //Checks if the returned string matches one of the 20 trinucleotides
    if (tri == "Isoleucine") {
      a++;
    }
    else if (tri == "Leucine") {
      b++;
    }
    else if (tri == "Valine") {
      c++;
    }
    else if (tri == "Phenylalanine") {
      d++;
    }
    else if (tri == "Methionine") {
      e++;
    }
    else if (tri == "Cysteine") {
      f++;
    }
    else if (tri == "Alanine") {
      g++;
    }
    else if (tri == "Glycine") {
      h++;
    }
    else if (tri == "Proline") {
      i++;
    }
    else if (tri == "Threonine") {
      j++;
    }
    else if (tri == "Serine") {
      k++;
    }
    else if (tri == "Tyrosine") {
      l++;
    }
    else if (tri == "Tryptophan") {
      m++;
    }
    else if (tri == "Glutamine") {
      n++;
    }
    else if (tri == "Asparagine") {
      o++;
    }
    else if (tri == "Histidine") {
      p++;
    }
    else if (tri == "Glutamic acid") {
      q++;
    }
    else if (tri == "Aspartic acid") {
      r++;
    }
    else if (tri == "Lysine") {
      s++;
    }
    else if (tri == "Arginine") {
      t++;
    }
    else {
      //cout << "ERROR unknown item" << endl; //DEBUG
    }
  }
  
  //Checks if there is a value in any of the Amino acids and prints out the appropiate string
  if (a != 0) {
    cout << "\tIsoleucine" << endl;
    count++;
  }
  if (b != 0) {
    cout << "\tLeucine" << endl;
    count++;
  }
  if (c != 0) {
    cout << "\tValine" << endl;
    count++;
  }
  if (d != 0) {
    cout << "\tPhenylalanine" << endl;
    count++;
  }
  if (e != 0) {
    cout << "\tMethionine" << endl;
    count++;
  }
  if (f != 0) {
    cout << "\tCysteine" << endl;
    count++;
  }
  if (g != 0) {
    cout << "\tAlanine" << endl;
    count++;
  }
  if (h != 0) {
    cout << "\tGlycine" << endl;
    count++;
  }
  if (i != 0) {
    cout << "\tProline" << endl;
    count++;
  }
  if (j != 0) {
    cout << "\tThreonine" << endl;
    count++;
  }
  if (k != 0) {
    cout << "\tSerine" << endl;
    count++;
  }
  if (l != 0) {
    cout << "\tTyrosine" << endl;
    count++;
  }
  if (m != 0) {
    cout << "\tTryptophan" << endl;
    count++;
  }
  if (n != 0) {
    cout << "\tGlutamine" << endl;
    count++;
  }
  if (o != 0) {
    cout << "\tAsparagine" << endl;
    count++;
  }
  if (p != 0) {
    cout << "\tHistidine" << endl;
    count++;
  }
  if (q != 0) {
    cout << "\tGlutamic Acid" << endl;
    count++;
  }
  if (r != 0) {
    cout << "\tAspartic Acid" << endl;
    count++;
  }
  if (s != 0) {
    cout << "\tLysine" << endl;
    count++;
  }
  if (t != 0) {
    cout << "\tArginine" << endl;
    count++;
  }
  cout << "Total Amino Acids Identified: " << count << endl << endl;
  delete[] concat; //Delete char array
  concat = NULL; //Clean up
}

//-----------------------------------------------------------
// Name: Translate
// PreCondition: A string of a trinucleotide
// PostCondition: Returns a string of the trinucleotide name
//-----------------------------------------------------------
string DNA::Translate(const string trinucleotide) {
	if ((trinucleotide == "ATT") || (trinucleotide == "ATC") || (trinucleotide == "ATA"))
	  return ("Isoleucine");
	else if ((trinucleotide == "CTT") || (trinucleotide == "CTC") || (trinucleotide == "CTA") ||
		 (trinucleotide == "CTG") || (trinucleotide == "TTA") || (trinucleotide == "TTG"))
	  return ("Leucine");
	else if ((trinucleotide == "GTT") || (trinucleotide == "GTC") ||
		 (trinucleotide == "GTA") || (trinucleotide == "GTG"))
	  return ("Valine");
	else if ((trinucleotide == "TTT") || (trinucleotide == "TTC"))
	  return ("Phenylalanine");
	else if ((trinucleotide == "ATG"))
	  return ("Methionine");
	else if ((trinucleotide == "TGT") || (trinucleotide == "TGC"))
	  return ("Cysteine");
	else if ((trinucleotide == "GCT") || (trinucleotide == "GCC") ||
		 (trinucleotide == "GCA") || (trinucleotide == "GCG"))
	  return ("Alanine");
	else if ((trinucleotide == "GGT") || (trinucleotide == "GGC") ||
		 (trinucleotide == "GGA") || (trinucleotide == "GGG"))
	  return ("Glycine");
	else if ((trinucleotide == "CCT") || (trinucleotide == "CCC") ||
		 (trinucleotide == "CCA") || (trinucleotide == "CCG"))
	  return ("Proline");
	else if ((trinucleotide == "ACT") || (trinucleotide == "ACC") ||
		 (trinucleotide == "ACA") || (trinucleotide == "ACG"))
	  return ("Threonine");
	else if ((trinucleotide == "TCT") || (trinucleotide == "TCC") ||
		 (trinucleotide == "TCA") || (trinucleotide == "TCG") ||
		 (trinucleotide == "AGT") || (trinucleotide == "AGC"))
	  return ("Serine");
	else if ((trinucleotide == "TAT") || (trinucleotide == "TAC"))
	  return ("Tyrosine");
	else if ((trinucleotide == "TGG"))
	  return ("Tryptophan");
	else if ((trinucleotide == "CAA") || (trinucleotide == "CAG"))
	  return ("Glutamine");
	else if ((trinucleotide == "AAT") || (trinucleotide == "AAC"))
	  return ("Asparagine");
	else if ((trinucleotide == "CAT") || (trinucleotide == "CAC"))
	  return ("Histidine");
	else if ((trinucleotide == "GAA") || (trinucleotide == "GAG"))
	  return ("Glutamic acid");
	else if ((trinucleotide == "GAT") || (trinucleotide == "GAC"))
	  return ("Aspartic acid");
	else if ((trinucleotide == "AAA") || (trinucleotide == "AAG"))
	  return ("Lysine");
	else if ((trinucleotide == "CGT") || (trinucleotide == "CGC") || (trinucleotide == "CGA") ||
		 (trinucleotide == "CGG") || (trinucleotide == "AGA") || (trinucleotide == "AGG"))
	  return ("Arginine");
	else if ((trinucleotide == "TAA") || (trinucleotide == "TAG") || (trinucleotide == "TGA"))
	  return ("Stop");
	else
	  cout << "returning unknown" << endl;
	return ("Unknown");
}


//----------------------------------------------------------
// Name: IsEmpty
// PreCondition: None
// PostCondition: A bool value of if there are still items
//----------------------------------------------------------
bool DNA::IsEmpty() {
  if (m_head == NULL) //If the first element is pointing to null
    return true;
  else //If the first element is pointing to another node
    return false;
}


//-------------------------------------------------
// Name: SizeOf
// PreCondition: None
// PostCondition: Updates the SizeOf 
//-------------------------------------------------
void DNA::SizeOf() {
  Nucleotide *tempLocation = m_head;
  m_size = 0; //Reset size to avoid adding to previous value
  
  while(tempLocation != NULL ){ //Goes though the list to see the size
    m_size = m_size + 1;
    tempLocation = tempLocation->m_next;
  }
  
  m_size = m_size - 1; //Show true size
}

//-------------------------------------------------
// Name: Clear
// PreCondition: None
// PostCondition: Removes all dynamic memory items
//-------------------------------------------------
void DNA::Clear() {
  Nucleotide *del = m_head; //Sets current node to the head of list
  Nucleotide *tempLocation;
  
  while (del != NULL) {
    tempLocation = del->m_next; //Sets temp to the next item in list
    delete del; //Deletes the current item
    del = NULL; //Clean up
    del = tempLocation; //Sets the next item as current item
    m_head = del; //Update head (Note to self, you need to update head so that the while loop will know when to end)  
  }
}

