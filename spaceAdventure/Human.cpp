#include "Human.h"
#include <time.h>

Human::Human(std::string nameIn, std::string descriptionIn, bool takeableIn)
	: Item(nameIn, descriptionIn, takeableIn) {}

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


