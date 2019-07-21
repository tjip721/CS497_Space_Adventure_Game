#ifndef ITEM_H 
#define ITEM_H
#include <string>
#include <vector> 
#include <iostream>
#include "data.h"

class Item 
{
private: 
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
	
public: 
	void lookAt(); 
	std::string getName(); 
	bool isTakeable(); 
	Item(std::string name, std::string description, bool takeable); 
}; 

#endif
