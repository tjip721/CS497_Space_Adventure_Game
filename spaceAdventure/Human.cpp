#include "Human.h"


void Human::attack(Player* player){
	srand(time(NULL)); 
	int flip = rand()%2; 
	if(flip){
		player->kill(); 
	}
}

void Human::talk(){
	std::cout<< speech << "\n"; 
}


