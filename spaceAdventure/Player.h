#ifndef PLAYER_H 
#define PLAYER_H
#include <string>
#include <vector> 
#include "Action.h"
#include "Item.h"

class Player 
{
private: 
	vector<Item> inventory;  
	Area* location; 

public: 
	void drop(Item); 
	bool teak(Item); 
	Area* getLocation(); 
	void setLocation(Area*); 
	
}; 

#endif
