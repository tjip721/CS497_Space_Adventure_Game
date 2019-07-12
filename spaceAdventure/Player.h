#ifndef PLAYER_H 
#define PLAYER_H
#include <string>
#include <vector> 
#include "Action.h"
#include "Area.h"
#include "Item.h"

using std::vector; 

class Player 
{
private: 
	vector<Item*> inventory;  
	Area* location; 

public: 
	void drop(Item* thing); 
	bool take(Item* thing); 
	Area* getLocation(); 
	void setLocation(Area* anArea); 
	
}; 

#endif
