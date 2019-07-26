#include "Player.h"
#include "Area.h"
#include "Item.h"

int Player::findItem(std::string targetName){
	for(int ii=0; ii < inventory.size(); ii++){
		if(inventory[ii]->getName().compare(targetName)==0){
			return ii; 	
		}
	}
	return NULL; 
}
	

Player::Player(double life, double gas){
	lifeRemaining = life; 
	gasRemaining = gas; 
}

void Player::initializeInventory(std::vector<Item*> addItem) {
	for(int i=0; i < addItem.size(); i++) {
		inventory.push_back(addItem[i]);
		std::cout << addItem[i]->getName() << std::endl;
	}
}

bool Player::drop(std::string targetName){
	for(int ii=0; ii < inventory.size(); ii++){
		if(inventory[ii]->getName().compare(targetName)==0){
			location->dropItem(inventory[ii]); 
			inventory.erase(inventory.begin()+ii); 
			return true; 	
		}
	}
	return false; 
} 

bool Player::take(std::string targetName){
	Item* targetPtr = location->takeItem(targetName); 
	if( targetPtr != NULL){
		inventory.push_back(targetPtr); 
		std::cout << "You picked up the " << targetPtr->getName() <<"\n"; 
		return true; 
	}else{
		return false;  
	}
}

Area* Player::getLocation(){
	return location; 
}

void Player::setLocation(Area* anArea){
	location = anArea; 
}
	 
void Player::listInventory(){
	std::cout << "Your inventory:\n"; 
	for(int ii=0; ii < inventory.size(); ii++){
		std::cout << inventory[ii]->getName() << "\n"; 
	}
	if(inventory.empty()){
		std::cout << "... is empty\n"; 
	}
}

bool Player::lookAt(std::string targetName){
	for(int ii=0; ii < inventory.size(); ii++){
		if(inventory[ii]->getName().compare(targetName)==0){
			inventory[ii]->lookAt(); 
			return true; 	
		}
	}
	return false; 
}

bool Player::use(std::string targetName){
	for(int ii=0; ii < inventory.size(); ii++){
		if(inventory[ii]->getName().compare(targetName)==0){
			inventory[ii]->lookAt(); 
			clothesWorn.push_back(inventory[ii]);
			inventory.erase(inventory.begin()+ii); 
			return true; 	
		}
	}
	return false; 

}

bool Player::eat(std::string targetName){
	int itemIndex = findItem(targetName); 
	if(itemIndex != NULL){
		//Eat the item, add to asphyxiation timer?
		return true; 
	}else{
		return false; 
	}
}

/*
std::vector<Item*> Player::getPlayerInventory(){
	return inventory;
}

bool Player::launch(){
	if(location->hasItem("Spaceship"){
		
	}
}
*/



