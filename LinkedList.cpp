/*
LinkedList.cpp
*/

#include "LinkedList.h" 


// struct constructor

node::node(std::string name, int sched){
	drugName = name;
	schedule = sched;
}

// Default constructor
LinkedList::LinkedList(){

	head = NULL;
	tail = NULL;
    listLength = 0;
	
}


void LinkedList::headInsert(node* nodeToInsert){
    
    if(listLength == 0){
    	head = nodeToInsert;
		tail = nodeToInsert;
		head -> next = NULL;
		listLength++; 
		return;
    }

	node* temp = head;
	head = nodeToInsert;
	head -> next = temp;
	listLength++; 

}

void LinkedList::tailInsert(node* nodeToInsert){

	// If the list is empty, head and tail will both point to same node
	if(listLength == 0){
		head = nodeToInsert;
		tail = nodeToInsert;
		head->next = NULL;
		listLength++;
		return;
	}

	tail->next = nodeToInsert;
	tail = nodeToInsert;
	tail -> next = NULL; 
	listLength++;
}

void LinkedList::print(){
	
	if(listLength == 0){
		std::cout << "\nThe list is empty\n\n";
		return;	
	}

	std::cout<<"\n-DEA Drug Schedule-\n";
	node* temp = head; 

		while(temp){
            
            std::cout<<"+---------------+\n";
			std::cout << "Schedule: " << temp -> schedule;
			std::cout << "\nDrug: " << temp -> drugName << "\n";
			std::cout<<"+---------------+\n\n";
            
            temp =  temp -> next;
		}

}

void LinkedList::tailRemove(){
    
    if (listLength <= 0) {
        std::cout << "The list is empty! Nothing to remove.\n\n";
        return;
    }
    
    if (listLength == 1) {
        node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        listLength--;
        print(); 
        return;
    }
    
    // assign nodeToRemove with...the node that will be removed
    node* nodeToRemove = tail;
    
    // p points to the first node
    node* p = head;
    
    // c points to the second node
    node* c = p -> next;
    
    // exit loop once c is equal to the node that needs to be removed
    // p will point to the second to last node
    while (c != nodeToRemove) {
        p = p->next;
		c = p -> next;
    }
    
    tail = p;
    tail -> next = NULL;
    listLength--;
    
    delete nodeToRemove;
    
    print();
}


void LinkedList::insertAtIndex(node* newNode, int index){
    
    if (index <= 0) {
        std::cout << "\nIndex to insert cannot be less than 1\n";
		return;
    }
    if(index > listLength+1){
        std::cout << "\nIndex is larger than list size\n";
		return;
    }

	index--; 
    if (index == 0) {
		std::cout << "\nInserting at head\n";
		headInsert(newNode); 
		return; 
    }

	if (index == listLength){
		std::cout << "\nInserting at tail\n";
		tailInsert(newNode);
		return;
	}
    

	node* current = head -> next;
	node* previous = head; 
    for (int i = 1; i <= index; i++) {
        
        if (index == i) {
			newNode->next = current;
			previous->next= newNode; 
			break; 
        }
		
		previous = current;
		current = current -> next;
    }
    listLength++; 
}

LinkedList::~LinkedList(){

	node* current;
	while(head){
		current = head->next;
		delete head; 
		head = current; 
	}
	tail = NULL; 
}

int LinkedList::returnLength(){
	return listLength;
}
