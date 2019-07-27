#include "Flashlight.h"


void Flashlight::use(Area* location){
	if(location->isDark(){
		cout << "You flip on the flashlight and take a look around.\n"; 
	} else{
		cout << "You flip on the flashlight but it's not too dark here so everything looks the same...\n"; 
	}
}


