#include "Alien.h"
#include <time.h>


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




