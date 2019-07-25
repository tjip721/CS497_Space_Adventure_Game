#include "Item.h"
/*
private: 
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
*/	

	
Item::Item(std::string nameIn, std::string descriptionIn, bool takeableIn){
	name = nameIn; 
	description = descriptionIn; 
	takeable = takeableIn; 
}


void Item::lookAt(){
	std::cout << description << "\n"; 
} 

std::string Item::getName(){
	return name; 
}


void Item::setEdible(bool yummy){
	edible = yummy;
} 

bool Item::isTakeable(){
	return takeable; 
} 
