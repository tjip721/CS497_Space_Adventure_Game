//Space Adventure Game main code for CS497
//Written by Tim Ip ONID # 933912896
//

#include <iostream> 
#include "spaceAdventure.h"

enum Verb{look, move, help, inventory, lookAt, take, fire, open, close, push, mine, launch, land, eat, bow, say, use, invalid}; 

int main(){

bool gameOver = false; 
Player player; 

while (!gameOver){

//loadgame & savegame logic

//check for players requested action using NLP interface
int verb = 1; //	verb = verbNLP
//	noun = nounNLP



switch (verb){

//enum Verb{look move help inventory lookAt take fire open close push mine launch land eat bow say use invalid}; 

	//Do non item actions
	//look
	case look: 


	//go somewhere
	case move: 
	case help: 
	case inventory: 
	// If an item action is requested check if the item is available
	//Check every inventory item for the item name
	case lookAt: 
	case take: 
	case fire: 
	case open: 
	case close: 
	case push: 
	case mine: 
	case launch: 
	case land: 
	case eat: 
	case bow: 
	case say: 
	case use: 
	case invalid: 
		std::cout << "Uh that doesn't make sense try something else.\n"; 		break; 

	std::cout << "Hello world.\n"; 
}


gameOver = true; 

}

return 0; 
}
