#include "Pickaxe.h"


void Pickaxe::use(Area* location){
	if(location->hasItem("Crysallith"){
		//Make Crysallith takeable
		Item* item = location->getItem("Crysallith"); 
		if(item !=NULL){
			item->setTakeable(true); 
			cout << "It appears you knocked the Crysallith loose.\n";
		}
	}else if(location->hasItem("Power Crystal"){
		Item* item = location->getItem("Power Crystal"); 
		if(item !=NULL){
			item->setTakeable(true); 
			cout << "It appears you uncovered a power crystal.\n";

	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


