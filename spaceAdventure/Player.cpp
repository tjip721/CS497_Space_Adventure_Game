#include "Player.h"

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
}

