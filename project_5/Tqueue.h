/*****************************************************************
* File:		Tqueue.h
* Project:	CMSC 202 Project 5, Spring 2017
* Author:	Daniel Roh
* Date:		5/11/17
* Section:	1066
* E-mail:	droh1@umbc.edu
*
*	This file is Tqueue.h
*	This header file is a templated type. Makes a dynamic array
*	to store items 
*****************************************************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
	//Name: Tqueue - Default Constructor
	//Precondition: None (Must be templated)
	//Postcondition: Creates a queue using dynamic array
	Tqueue(); //Default Constructor
	//Name: Copy Constructor - Not used but required for project 5
	//Precondition: Existing Tqueue
	//Postcondition: Copies an existing Tqueue
	Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
	//Name: Destructor
	//Precondition: Existing Tqueue
	//Postcondition: Destructs existing Tqueue
	~Tqueue(); //Destructor
	//Name: enqueue
	//Precondition: Existing Tqueue
	//Postcondition: Adds item to back of queue
	void enqueue(T data); //Adds item to queue (to back)
	//Name: dequeue
	//Precondition: Existing Tqueue
	//Postcondition: Removes item from front of queue
	void dequeue(T &); //Removes item from queue (from front)
	//Name: queueFront
	//Precondition: Existing Tqueue
	//Postcondition: Retrieve front (does not remove it)
	void queueFront(T &);// Retrieve front (does not remove it)
	//Name: isEmpty
	//Precondition: Existing Tqueue
	//Postcondition: Returns 1 if queue is empty else 0
	int isEmpty(); //Returns 1 if queue is empty else 0
	//Name: isFull
	//Precondition: Existing Tqueue
	//Postcondition: Returns 1 if queue is full else 0
	int isFull(); //Returns 1 if queue is full else 0
	//Name: Overloaded assignment operator - Not used but required for project 5
	//Precondition: Existing Tqueue
	//Postcondition: Sets one Tqueue to same as a second Tqueue using =
	Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue

private:
	T* m_data; //Data of the queue (Must be dynamically allocated array)
	int m_front; //Front of the queue
	int m_back; //Back of the queue
};

//**** Add class definition below ****


//-------------------------------------------------
// Name: Tqueue
// PreCondition: A made vector to store the obkect
// PostCondition: Makes a dynamic array
//-------------------------------------------------
template <class T, int N>
Tqueue<T, N>::Tqueue() {
	m_data = new T[N];
	m_front = 0;
	m_back = 0;
}

//-------------------------------------------------
// Name: Tqueue (copy)
// PreCondition: A Tqueue already made
// PostCondition: Makes a copy of Tqueue
//-------------------------------------------------
template <class T, int N>
Tqueue<T, N>::Tqueue(const Tqueue<T,N>& x) {
	m_data = new T[N]; //Make a new array

	for (int g = 0; g < N; g++) { //For N times (N is 200)
		m_data[g] = x.m_data[g]; //Copy data
	}
	m_front = x.m_front; //Set the front 
	m_back = x.m_back; //Set back
}

//-------------------------------------------------
// Name: ~Tqueue
// PreCondition: None
// PostCondition: Removes dynamic array
//-------------------------------------------------
template <class T, int N>
Tqueue<T, N>::~Tqueue() {
	delete[] m_data;
	m_data = NULL;
}

//-------------------------------------------------
// Name: enqueue
// PreCondition: A Tqueue
// PostCondition: Places a item into the array
//-------------------------------------------------
template <class T, int N>
void Tqueue<T, N>::enqueue(T data) {
	if (isFull() == 0) { //If full is true
		m_data[m_back++] = data; //Place data in array
	}
	else {
		m_back = m_back % N; //Wrap around data
	}
}

//-------------------------------------------------
// Name: dequeue
// PreCondition: A value for front
// PostCondition: removes the item at the front
//-------------------------------------------------
template <class T, int N>
void Tqueue<T, N>::dequeue(T & front) {
		m_front = m_front + 1; //Moves the front up
}

//-------------------------------------------------
// Name: queueFront
// PreCondition: A existing queue
// PostCondition: Returns the front of queue
//-------------------------------------------------
template <class T, int N>
void Tqueue<T, N>::queueFront(T &front) {
	return m_data[m_front];
}


//-------------------------------------------------
// Name: isEmpty
// PreCondition: A existing queue
// PostCondition: Returns a int
//-------------------------------------------------
template <class T, int N>
int Tqueue<T, N>::isEmpty() {
	// If queue is empty                                            
	if (m_front == 0 && m_back == 0){
		return 1;
	}
	else{
		return 0;
	}
}

//-------------------------------------------------
// Name: isFull
// PreCondition: A existing queue
// PostCondition: Returns a int 
//-------------------------------------------------
template <class T, int N>
int Tqueue<T, N>::isFull() {
	if (m_back == 199){
		return 1;
	}
	else{
		return 0;
	}
}

//-------------------------------------------------
// Name: operator=
// PreCondition: A existing queue
// PostCondition: Return a operator=
//-------------------------------------------------
template<class T, int N>
Tqueue<T, N>& Tqueue<T, N>::operator=(Tqueue<T, N> y){

}

#endif