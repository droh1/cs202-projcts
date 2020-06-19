/*****************************************************************
* File:		Flower.cpp
* Project:	CMSC 202 Project 4, Spring 2017
* Author:	Daniel Roh
* Date:		4/27/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is the Flower.cpp 
*	The file contains the class deff for the flower class
*****************************************************************/

#include "Flower.h"

//-------------------------------------------------
// Name: Flower
// PreCondition: None
// PostCondition: Make a flower object
//-------------------------------------------------
Flower::Flower() {
	m_isFlowering = false;
	m_numPetals = 5;
	m_color = "red";
}

//-------------------------------------------------
// Name: Flower
// PreCondition: Number of petals and Color name
// PostCondition: Makes a flower object
//-------------------------------------------------
Flower::Flower(int num, string color) {
	m_numPetals = num;
	m_color = color;
	m_isFlowering = false;
}

//-------------------------------------------------
// Name: die
// PreCondition: None
// PostCondition: Updates alive status
//-------------------------------------------------
void Flower::die() { //Virtual
	SetIsAlive(false);
}

//-------------------------------------------------
// Name: tick
// PreCondition: None
// PostCondition: Updates objects
//-------------------------------------------------
void Flower::tick() { //Virtual
	int random;
	//int sick;
	const int bloom = 4;
	
	if (GetSize() == bloom) { //If the flower has blommed 
		die();
	}

	SetIsDiseased(false); //Reset diseased status

	random = rand() % 10 + 1; //Makes a random number from 1 to 100
	//cout << "RandTETS: " << random << endl;//DEBUG	

	/*If the number is from 1-2 then the plant is sick.
	(2/10) chance of getting sick */

	if (random == 1 || random == 7) { //If sick is 1 or 7
		SetIsDiseased(true); //Plant becomes diseased 
	}

	if (GetIsDiseased() == true) { //If the plant is sick
		//cout << "Flower is sick, cant grow" << endl; //DEBUG
	}
	else { //If the plant is fine
		SetSize((GetSize() + 1)); //Updates size this fking thing wont work because of some issue in g++
		//cout << "GETSIZE IS : " << GetSize();
	}
}

//-------------------------------------------------
// Name: operator<<
// PreCondition: None
// PostCondition: Prints out the object condition
//-------------------------------------------------
ostream & Flower::operator<<(ostream & output){

	if (GetSize() > 1) { //If size is larger then 1
		if (GetSize() > 2) { //If size is larger then 2
			if (GetSize() > 3) { //If size is larger then 3
				if (GetSize() > 4) { //If size is larger then 4
					if (GetIsDiseased() == false) { //If not Diseased
						if (GetIsAlive() == true) { //If alive
							output << "Flower (Fully Mature : Alive : Flowering : Not Diseased)" << endl;
						}
						else { //If dead
							output << "Flower (Fully Mature: Dead : Flowering : Not Diseased)" << endl;
						}
					}
					else { //If Diseased
						if (GetIsAlive() == true) {
							output << "Flower (Fully Mature : Alive : Flowering : Diseased)" << endl;
						}
						else { //If dead
							output << "Flower (Fully Mature: Dead : Flowering : Diseased)" << endl;
						}
					}
				}
				else { //If 4
					if (GetIsDiseased() == false) { //if not Diseased
						if (GetIsAlive() == true) { //If alive
							output << "Flower drops its petals" << endl;
							output << "Flower (Fully Mature : Alive : Flowering : Not Diseased)" << endl;
						}
						else { //If dead
							output << "Flower drops its petals" << endl;
							output << "Flower (Fully Mature: Dead : Flowering : Not Diseased)" << endl;
						}
					}
					else { //If Diseased
						if (GetIsAlive() == true) {
							output << "Flower drops its petals" << endl;
							output << "Flower (Fully Mature : Alive : Flowering : Diseased)" << endl;
						}
						else { //If dead
							output << "Flower drops its petals" << endl;
							output << "Flower (Fully Mature: Dead : Flowering : Diseased)" << endl;
						}
					}
				}
			}
			else { //If 3
				if (GetIsDiseased() == false) { //If not diseased
					if (GetIsAlive() == true) { //If alive
						output << "Flower (Fully Mature : Alive : Flowering : Not Diseased)" << endl;
					}
					else { //If dead
						output << "Flower (Fully Mature: Dead : Flowering : Not Diseased)" << endl;
					}
				}
				else { //If diseased
					if (GetIsAlive() == true) { //If alive
						output << "Flower (Fully Mature : Alive : Flowering : Diseased)" << endl;
					}
					else { //If dead 
						output << "Flower (Fully Mature: Dead : Flowering : Diseased)" << endl;
					}
				}
			}
		}
		else { //If 2
			if (GetIsDiseased() == false) { //If not diseased
				if (GetIsAlive() == true) { //If alive
					output << "Flower (Medium-Sized : Alive : Not Flowering : Not Diseased)" << endl;
				}
				else { //If dead
					output << "Flower (Medium-Sized : Dead : Not Flowering : Not Diseased)" << endl;
				}
			}
			else { //If diseased
				if (GetIsAlive() == true) { //If alive
					output << "Flower (Medium-Sized : Alive : Not Flowering : Diseased)" << endl;
				}
				else { //If dead
					output << "Flower (Medium-Sized : Dead : Not Flowering : Diseased)" << endl;
				}
			}
		}
	}
	else { //If 1
		if (GetIsDiseased() == false) { //If not diseased
			if (GetIsAlive() == true) { //If alive
				output << "Flower (Seedling : Alive : Not Flowering : Not Diseased)" << endl;
			}
			else { //If dead
				output << "Flower (Seedling : Dead : Not Flowering : Not Diseased)" << endl;
			}
		}
		else { //If diseased
			if (GetIsAlive() == true) { //If alive
				output << "Flower (Seedling : Alive : Not Flowering : Diseased)" << endl;
			}
			else { //If dead
				output << "Flower (Seedling : Dead : Not Flowering : Diseased)" << endl;
			}
		}
	}

	return output;
}

