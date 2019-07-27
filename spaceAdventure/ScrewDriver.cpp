#include "ScrewDriver.h"


void ScrewDriver::use(Area* location){
	if(location->hasItem("Spaceship")){
		//Use Power Crystal to fix spaceship
		Item* ship = location->getItem("Spaceship"); 
		if(item !=NULL){
			ship ->fix(); 
			cout << "You fixed all the loose screws on the spaceship, looks like it won't fall apart now.\n";
		}
	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


