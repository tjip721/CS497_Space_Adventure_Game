#include "ScrewDriver.h"


void ScrewDriver::use(Area* location){
	if(location->hasItem("Spaceship") && fixes > 0){
		//Use Power Crystal to fix spaceship
		Item* ship = location->getItem("Spaceship"); 
		if(ship !=NULL){
			ship ->fix(); 
			cout << "You fixed all the loose screws on the spaceship, looks like it won't fall apart now.\n";
			fixes--; 
		}
	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


