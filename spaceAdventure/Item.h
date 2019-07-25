#ifndef ITEM_H 
#define ITEM_H
#include <string>
#include <vector> 
#include <iostream>

class Item 
{
private: 
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
	bool edible; 
	
public: 
	void lookAt(); 
	std::string getName(); 
	bool isTakeable(); 
	bool isEdible(){ return edible; }
	void setEdible(bool edible); 
	Item(std::string name, std::string description, bool takeable); 
}; 

#endif
