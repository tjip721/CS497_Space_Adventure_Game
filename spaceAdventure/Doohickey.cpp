#include "Doohickey.h"


void Doohickey::use(Area* location){
	if(location->hasItem("Spaceship")){
		//Use Power Crystal to fix spaceship
		Item* ship = location->getItem("Spaceship"); 
		if(item !=NULL){
			ship ->fix(); 
			cout << "Not sure what this doohickey does but you found a spot it fits right into on the spaceship.\n";
		}
	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


