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
	double lifeRemaining; 
	double gasRemaining; 

public: 
	bool drop(std::string targetName); 
	bool take(std::string targetName); 
	Area* getLocation(); 
	void setLocation(Area* anArea); 
	void listInventory(); 
	bool lookAt(std::string targetName); 
	
}; 

#endif
