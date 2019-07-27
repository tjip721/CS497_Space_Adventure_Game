#ifndef PLAYER_H 
#define PLAYER_H
#include <string>
#include <vector> 
#include "Action.h"


using std::vector; 
//Forward declaration
class Area;
class Item;

class Player 
{
private: 
	vector<Item*> inventory;  
	vector<Item*> clothesWorn;  
	Area* location; 
	double lifeRemaining; 
	double gasRemaining; 

public: 
	bool drop(std::string targetName); 
	bool take(std::string targetName); 
	Area* getLocation();
	//Needed because of dynamic loadgame 
	void setVars(Area* anArea, double gas, double life); 
	void listInventory(); 
	void setLocation(Area* anArea);
	bool lookAt(std::string targetName); 
	double getLife(){ return lifeRemaining;} 
	double getGas(){ return gasRemaining;}
	void removeLife(int years){lifeRemaining -= years;}
	void removeGas(int gas){gasRemaining -= gas;}
	bool launch(); 
	bool eat(std::string targetName); 
	int findItem(std::string targetName); 
	void getPlayer();
	std::vector<Item*> getPlayerInventory();
	//When user chooses to "load game" adds an item object
	void initializeInventory(std::vector<Item*> toAdd);	
	bool use(std::string itemName); 
	bool isWearing(std::string name); 
	
}; 

#endif
