/*
main.cpp
*/

#include "LinkedList.h"

using namespace std;

int main(){

	// create a new node
	node* newNode = new node; 
	newNode -> drugName = "LSD";
	newNode -> schedule = 1; 


	// create an empty linked list
	LinkedList drugSchedule; 

//	drugSchedule.tailInsert(newNode); 
/*
	drugSchedule.print(); 
*/

	return 0;
}
