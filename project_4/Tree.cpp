/*****************************************************************
* File:		Tree.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the Tree.cpp
*	The file contains the class deff for Tree
*****************************************************************/
#include "Tree.h"

//-------------------------------------------------
// Name: Tree
// PreCondition: None
// PostCondition: Makes tree object
//-------------------------------------------------
Tree::Tree() {
	m_fruit;
}

//-------------------------------------------------
// Name: ~Tree
// PreCondition: None
// PostCondition: Removes tree object
//-------------------------------------------------
Tree::~Tree(){
	ClearFruit(); //Clear fruit
}

//-------------------------------------------------
// Name: die
// PreCondition: None
// PostCondition: Updates object alive status
//-------------------------------------------------
void Tree::die(){ //Virtual
	SetIsAlive(false); //Sets the plant to be dead
}

//-------------------------------------------------
// Name: ClearFruit
// PreCondition: None
// PostCondition: Removes fruits from memory
//-------------------------------------------------
void Tree::ClearFruit() {
	for (int x = 0; x < m_fruit.size(); x++) {
		delete m_fruit.at(x); //Remove object
	}
	//cout << "Fruit cleared" << endl;//DEBUG
}

//-------------------------------------------------
// Name: tick
// PreCondition: None
// PostCondition: Updates objects
//-------------------------------------------------
void Tree::tick(){ //Virtual
	int random;
	//int sick;
	int lifeSpan = 119;

	if (GetSize() == lifeSpan) { //If the tree is 120months old
		SetIsAlive(false);
	}

	SetIsDiseased(false); //Reset diseased status

	random = rand() % 10 + 1; //Makes a random number from 1 to 100

	/*If the number is from 1-2 then the plant is sick.
	(2/10) chance of getting sick */

	if (random == 1 || random == 7) { //If sick is 1 or 7
		SetIsDiseased(true); //Plant becomes diseased 
	}

	if (GetIsDiseased() == true) { //If the plant is sick
		//cout << "Tree is sick, cant grow" << endl; //Does not increase size
	}
	else { //If the plant is fine
		if (GetSize() >= 36) { //If the tree is older then 36months
			if (GetIsDiseased() == false) { //If the tree is not diseased
				Fruit *Fruit1 = new Fruit; //Make a new fruit
				m_fruit.push_back(Fruit1); //Add Fruit to vector
			}
		}
		SetSize(GetSize() + 1); //Update Size
	}
}

//-------------------------------------------------
// Name: operators<<
// PreCondition: None
// PostCondition: Prints out Tree status
//-------------------------------------------------
ostream& Tree::operator<<(ostream & output){ //Virtual
	int mature = 36;
	int sap = 24;
	int seed = 12;

	if (GetSize() >= seed) {//If not a seed
		if (GetSize() >= sap){ //If not a sapling
			if (GetSize() >= mature) { //If not a pole
				if (GetSize() > mature) { //if mature
					if (GetIsAlive() == true) { //if alive
						if (GetIsDiseased() == false) { //if not sick
							output << "Tree (Mature : Alive : Fruiting : Not Diseased)" << endl;
						}
						else {
							output << "Tree (Mature : Alive : Fruiting : Diseased)" << endl;
						}
					}
					else { //If dead
						output << "Tree (Mature : Dead : Fruiting : Not Diseased)" << endl;
					}
				}
			}
			else { //If a pole
				if (GetIsAlive() == true) { //if alive
					if (GetIsDiseased() == false) { //if not sick
						output << "Tree (Pole : Alive : Not Fruiting : Not Diseased)" << endl;
					}
					else { //if diseased
						output << "Tree (Pole : Alive : Not Fruiting : Diseased)" << endl;
					}
				}
				else {//if dead
					output << "Tree (Pole : Dead : Fruiting : Not Diseased)" << endl;
				}
			}
		}
		else { //if a sapling
			if (GetIsAlive() == true) { //if alive
				if (GetIsDiseased() == false) { //if not sick
					output << "Tree (Sapling : Alive : Not Fruiting : Not Diseased)" << endl;
				}
				else { //if diseased
					output << "Tree (Sapling : Alive : Not Fruiting : Diseased)" << endl;
				}
			}
			else { //if dead
				output << "Tree (Sapling : Dead : Not Fruiting : Not Diseased)" << endl;
			}
		}
	}
	else { //If a seedling
		if (GetIsAlive() == true) { //if alive
			if (GetIsDiseased() == false) { //if not sick
				output << "Tree (Seedling : Alive : Not Fruiting : Not Diseased)" << endl;
			}
			else { //if diseased
				output << "Tree (Seedling : Alive : Not Fruiting : Diseased)" << endl;
			}
		}
		else { //if dead
			output << "Tree (Seedling : Dead : Not Fruiting : Not Diseased)" << endl;
		}
	}

	return output;
}

