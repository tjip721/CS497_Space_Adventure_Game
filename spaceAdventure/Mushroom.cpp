#include "Mushroom.h"


void Mushroom::use(Area* location){
	if(!location->hasOxygen(){
		location->setOxygen(true); 
		cout << "Wow you can suddenly breath.\n"; 
	}else{
		cout << "Looks like that didn't do anything.\n"; 
	}
}


