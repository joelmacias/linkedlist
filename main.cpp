/*
main.cpp
*/

#include "LinkedList.h"



int main(){

	// create an empty linked list
	LinkedList drugSchedule = LinkedList();


	bool x = true;
	char userChoice;
    std::string drugNameInput;
    int scheduleInput;
    
	while(x){

        
        std::cout << "Choose from the following options:\n";
        std::cout << "To add a node to the linked list enter '1'\n";
        std::cout << "To remove a node from the linked list enter '2'\n";
        std::cout << "To print the current linked list enter '3'\n";
        std::cout << "To exit the program enter '4'\n";
        std::cout << "Enter choice: ";
        std::cin >> userChoice;
        
        switch (userChoice) {
            case '1':
            {
                
                std::cout <<"Enter the drug's name: ";
                std::cin >> drugNameInput;
                
                std::cout <<"Enter the drug's schedule: ";
                std::cout << "Enter choice: "; 
                std::cin >> scheduleInput;
                
                node* newNode = new node;
                newNode -> drugName = drugNameInput;
                newNode -> schedule = scheduleInput;
                
                std::cout << "How do you want to insert the node?\n";
                std::cout << "To insert at the head of of the linked list enter '1'\n";
                std::cout << "To insert at the tail of the the linked list enter '2'\n";
                std::cin >> userChoice;
                
                    if(userChoice == '2'){
                        drugSchedule.tailInsert(newNode);
                        std::cout<<"\n-DEA Drug Schedule-\n";
                        drugSchedule.print();
                    }
                        
                    else if(userChoice == '1'){
                        drugSchedule.headInsert(newNode);
                        std::cout<<"\n-DEA Drug Schedule-\n";
                        drugSchedule.print();
                    }
                    else{
                        std::cout << "Invalid input!\n";
                    }
                break;
            }
                
            case '2':
                drugSchedule.tailRemove();
                break;
            case '3':
                drugSchedule.print();
                break;
                
            case '4':
                x = false;
                break;
                
            default:
                break;
        }
    }
    
    drugSchedule.print();
    
	return 0;
}
