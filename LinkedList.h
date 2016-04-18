/*
LinkedList.h

*/

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <string>
using namespace std;



//Node struct to represent drug name, and schedule drug is in

struct node{
	string drugName; 
	int schedule;
	node* next; 
}; 

class LinkedList{
	private:
    	// Linked list head 
		node* head; 

		// Linked list tail
		node* tail; 

		// Length of linked list
		int listLength;
    
	public:
		// Default constructor
		// Sets head to NULL
		LinkedList();
/*
		// Insert a node at given position 
		void insertNode(node* nodeToInsert, int positionToInsert);

		// Insert a node at the head of the list
		void headInsert(node* nodeToInsert); 
*/
		// Insert a node at the tail of the list
		void tailInsert(node* nodeToInsert); 
		// Print list
		void print(); 
};

#endif
