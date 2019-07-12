#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector> 
#include "Action.h"
#include "Item.h"
#include "Exit.h"
using std::vector; 

class Area
{
private: 
	string longDescription;
	string shortDescription; 
	vector<Exit*> exits; 
	vector<Item*> items;  
	vector<Action> availableActions;  
	bool firstEntry; 
public: 
	void printDescription(); 
	void takeItem(Item* thing); 
	void dropItem(Item* thing); 
	
}; 

#endif
