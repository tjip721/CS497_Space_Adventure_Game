#ifndef ALIEN_H 
#define ALIEN_H
#include "Item.h"
#include "Player.h"

class Alien : public Item
{
private: 

/* Inherited attributes for reference
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
	bool edible; 
	bool wearable; 
*/
	bool hostile; 
	std::string speech; 
	
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
	void aggravate(){hostile = true;}
	void makePeace(){hostile = false;}
	bool isHostile(){return hostile;}
	void attack(Player* player); 
	void talk(); 
	
}; 

#endif
