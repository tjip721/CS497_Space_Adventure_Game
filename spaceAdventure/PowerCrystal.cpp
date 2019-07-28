#include "PowerCrystal.h"


void PowerCrystal::use(Area* location){
	if(location->hasItem("Spaceship")){
		//Use Power Crystal to fix spaceship
		Item* item = location->getItem("Spaceship"); 
		if(item !=NULL){
			item->fix(); 
			cout << "You have inserted the power crystal into the spaceship energy drive.\n";
		}
	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


