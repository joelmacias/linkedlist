/*
LinkedList.cpp
*/

#include "LinkedList.h" 

// Default constructor
// Assigns NULL to head 
LinkedList::LinkedList(){
	
	// set head's next pointer to NULL 
	head -> next = NULL; 
	// set tail's next pointer to NULL
	tail -> next = NULL; 
	
	// Head node contains no data
//	head -> drugName = "";
//	head -> schedule = -1;
	// initial length of list is 0  

//	tail -> drugName = "";
//	tail -> schedule = -1; 
//	listLength = 0; 
}

/*
void LinkedList::insertNode(node* nodeToInsert, int positionToInsert){
	


}
*/
void LinkedList::tailInsert(node* nodeToInsert){

	// If the list is empty, head and tail will both point to same node
	if(listLength == 0){
		// head points to newly inserted node
		head -> next = nodeToInsert; 	
	
		// tail points to newly inserted node
		tail -> next = nodeToInsert; 

		// increment list length
		listLength++; 	
		
		return; 	
	}

	// last node now points to nodeToInsert which is now the last node
	(tail -> next) -> next = nodeToInsert; 
	listLength++; 

	// tail now points to nodeToInsert
	tail -> next = nodeToInsert; 
}

void LinkedList::print(){
	
	if(listLength == 0){
		cout << "The list is empty" << endl;
		return;	
	}

	node* temp = head; 

		while(temp){
			cout << "Schedule: " << (temp -> next) -> schedule;
			cout << "\nDrug: " << (temp -> next) -> drugName << "\n";
			
			temp =  (temp -> next) -> next; 
		}
}	
