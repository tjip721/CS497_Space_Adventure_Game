#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector> 
#include "Action.h"
#include "Item.h"
#include "Exit.h"
#include "data.h"
using std::vector; 

class Area
{
private: 
	string longDescription;
	string shortDescription; 
	vector<Exit*> exits; 
	vector<Item*> items;  
	vector<Action> availableActions;  
	bool firstEntry = true;
public: 
	void printDescription(); 
	void look(); 
	Item* takeItem(std::string targetName); 
	void dropItem(Item* thing); 
	bool hasExit(std::string target); 	
	Area* getExit(std::string targetName); 	
	bool lookAt(std::string targetName); 
	
	void addExit(Exit* exit); 
	void addItem(Item* item); 
	void setLongDescription(std::string text); 
	void setShortDescription(std::string text); 
	//Prints all of the items in the Area + the Area name -- done for save log.
	void getItems();
	
}; 

#endif
