#ifndef ITEM_H 
#define ITEM_H
#include <string>
#include <vector> 
#include <iostream>

class Area; 

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
	void use(Area* location); 
}; 

#endif
