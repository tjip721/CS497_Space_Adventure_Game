#ifndef ITEM_H 
#define ITEM_H
#include <string>
#include <vector> 
#include <iostream>
#include "Area.h"
#include "Player.h"

using std::cout; 

class Item 
{
private: 
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
	bool edible; 
	bool wearable; 
	bool hidden = false; 
	std::string loadFile(std::string fileName);
	
public: 
	void setHidden(bool hide){ hidden = hide; }
	bool isHidden(){return hidden;}
	void lookAt(); 
	std::string getName(); 
	bool isTakeable(); 
	void setTakeable(bool take){ takeable = take;}
	bool isEdible(){ return edible; }
	void setEdible(bool edible); 
	bool isWearable(){return wearable;}
	void setWearable(bool wear){wearable = wear;}
	Item(std::string name, std::string description, bool takeable); 
	virtual void use(Area* location, Player* player); 
	void fix(){cout<<"You have made repairs to your ship.\n";}
}; 

#endif
