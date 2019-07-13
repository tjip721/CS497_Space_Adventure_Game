#include "Item.h"
/*
private: 
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
*/	
	
void Item::lookAt(){
	std::cout << description << "\n"; 
} 

std::string Item::getName(){
	return name; 
}

