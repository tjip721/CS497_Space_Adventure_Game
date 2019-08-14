#include "Alien.h"
#include <time.h>

Alien::Alien(std::string nameIn, std::string descriptionIn, bool takeableIn)
	: Item(nameIn, descriptionIn, takeableIn) {}
void Alien::attack(Player* player){
	srand(time(NULL)); 
	int flip = rand()%2; 
	if(flip){
		player->kill(); 
	}
}

void Alien::talk(){
	std::cout<< speech << "\n"; 
}




