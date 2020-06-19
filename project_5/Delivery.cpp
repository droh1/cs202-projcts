/*
	Loading the truck takes 10 mins
*/

#include "Delivery.h"

Delivery::Delivery() { //Default constructor
	m_name = "Bob";
	m_numItem = 0;
	m_rtMinute = 0;
}

Delivery::Delivery(string name, int numItem, int rtMin) { //Overloaded contructor
	m_name = name;
	m_numItem = numItem;
	m_rtMinute = rtMin;
}

string Delivery::GetName() const{
	return m_name;
}

int Delivery::GetNumItem() const{
	return m_numItem;
}

int Delivery::GetRTMinute() const {
	return m_rtMinute;
}
