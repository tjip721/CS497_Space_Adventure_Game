#include "Spaceship.h"


void Spaceship::use(Area* location){
	cout << "Looks like that didn't do anything.\n"; 
}

bool Spaceship::isFixed(){
	if(fixesNeeded <= 0){
		return true; 
	} else {
		return false; 
	}
}


