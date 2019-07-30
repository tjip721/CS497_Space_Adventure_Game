#ifndef SPACESHIP_H 
#define SPACESHIP_H
#include "Item.h"

class Spaceship : public Item
{
private: 

	int fixesNeeded = 3; 
/* Inherited attributes for reference
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
	bool edible; 
	bool wearable; 
*/
	
public: 
/* Inherited methods for reference
	void lookAt(); 
	std::string getName(); 
	bool isTakeable(); 
	bool isEdible(){ return edible; }
	void setEdible(bool edible); 
	bool isWearable(){return wearable;}
	void setWearable(bool wear){wearable = wear;}
	Item(std::string name, std::string description, bool takeable); 
*/
	void use(Area* location); 
	void fix(){ fixesNeeded--;}
	bool isFixed();
	
}; 

#endif