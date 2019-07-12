#include "Player.h"

void Player::drop(Item* thing){
	location->dropItem(thing); 
} 

bool Player::take(Item* thing){
	inventory.push_back(thing); 
	location->takeItem(thing); 
}

Area* Player::getLocation(){
	return location; 
}

void Player::setLocation(Area* anArea){
	location = anArea; 
}
	 

