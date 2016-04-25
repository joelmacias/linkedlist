/*
LinkedList.cpp
*/

#include "LinkedList.h" 

// Default constructor
// Assigns NULL to head 
LinkedList::LinkedList(){

	// head and tail now point to nodes 
	head = new node;
	tail = new node;
	// head and tail next pointer set to NULL 
  	head -> next = NULL;
	tail -> next = NULL; 

	// head and taill don't have these values 
	head -> drugName = ""; 
	tail -> drugName = "";
	head -> schedule = -1;
	tail -> schedule = -1; 

    listLength = 0;
	
}


void LinkedList::headInsert(node* nodeToInsert){
    
    if(listLength == 0){
        head -> next = nodeToInsert;
        tail -> next = nodeToInsert;
        listLength++;
        nodeToInsert -> next = NULL;
        return;
    }
    
    // temp points to soon to be old head node
    node* temp = head -> next;
    
    // head points to new head node
    head -> next = nodeToInsert;
    
    // new head points to old head node
    nodeToInsert -> next = temp;
    listLength++;

}

void LinkedList::tailInsert(node* nodeToInsert){

	// If the list is empty, head and tail will both point to same node
	if(listLength == 0){
		// head points to newly inserted node
		head -> next = nodeToInsert; 	
	
		// tail points to newly inserted node
		tail -> next = nodeToInsert; 

		// increment list length
		listLength++; 	

		// set inserted node's next pointer to NULL
		nodeToInsert -> next = NULL;
		
		return; 	
	}

	// last node now points to nodeToInsert which is now the last node
	(tail -> next) -> next = nodeToInsert; 
	listLength++; 

	// tail now points to nodeToInsert
	tail -> next = nodeToInsert; 

	// inserted node points to NULL
	nodeToInsert -> next = NULL;
}

void LinkedList::print(){
	
	if(listLength == 0){
		std::cout << "The list is empty\n\n";
		return;	
	}

	node* temp = head; 

		while(temp -> next){
            
            std::cout<<"+---------------+\n";
			std::cout << "Schedule: " << (temp -> next) -> schedule;
			std::cout << "\nDrug: " << (temp -> next) -> drugName << "\n";
			std::cout<<"+---------------+\n\n";
            
            temp =  temp -> next;//) -> next;
		}

}

void LinkedList::tailRemove(){
    
    if (listLength <= 0) {
        std::cout << "The list is empty! Nothing to remove.\n\n";
        return;
    }
    
    if (listLength ==1) {
        node* temp = head -> next;
        head -> next = NULL;
        tail -> next = NULL;
        delete temp;
        listLength--;
        print(); 
        return;
    }
    
    // assign nodeToRemove with...the node that will be removed
    node* nodeToRemove = tail -> next;
    
    // p points to the first node
    node* p = head -> next;
    
    // c points to the second node
    node* c = p -> next;
    
    // exit loop once c is equal to the node that needs to be removed
    // p will point to the second to last node
    while (c  != nodeToRemove) {
        p = c;
        c = c -> next;
    }
    
    tail -> next = p;
    p -> next = NULL;
    listLength--;
    
    delete nodeToRemove;
    
    print();
}


void LinkedList::insertAtIndex(node* newNode, int index){
    
    if (index < 0) {
        std::cout << "Index to insert cannot be less than 0\n";
    }
    if(index > listLength){
        std::cout << "Index is larger than list size\n";
    }

	if(index == listLength){
		std::cout << "Node inserted at tail\n";
		// temp point to last node in list
		node* temp = tail-> next;
		// last node points to newNode 
		temp -> next = newNode;
		// tail points to newNode
		tail -> next = newNode;
		// newNode points to NULL; 
		newNode -> next = NULL;
	}
		
    
    if (index == 0) {
		std::cout<<"Node inserted at head\n";
		head -> next = newNode;
		tail -> next = newNode;
		newNode -> next = NULL; 
		return; 
    }
    
	// current points to first node in list
	node* current = head->next; 
    for (int i = 1; i < listLength; i++) {
        
        if (index == i) {
     		     
        }
    }
    
    
    
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
