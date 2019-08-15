#include "PowerCrystal.h"

PowerCrystal::PowerCrystal(std::string nameIn, std::string descriptionIn, bool takeableIn)
	: Item(nameIn, descriptionIn, takeableIn) {}

void PowerCrystal::use(Area* location, Player* player) {
	if(location->hasItem("Spaceship")){
		//Use Power Crystal to fix spaceship
		Item* item = location->getItem("Spaceship"); 
		if(item !=NULL){
			cout << "You have inserted the power crystal into the spaceship energy drive.\n";
			item->fix();
			player->eraseItem("PowerCrystal");
		}
	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


