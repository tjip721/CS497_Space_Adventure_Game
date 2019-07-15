//Space Adventure Game main code for CS497
//Written by Tim Ip ONID # 933912896
//

#include <iostream> 
#include "spaceAdventure.h"

using std::string; 
using std::cout; 

enum Verb{look, move, help, inventory, lookAt, take, fire, open, close, push, mine, launch, land, eat, bow, say, use, invalid}; 

int main(){

bool gameOver = false; 
Player player; 

while (!gameOver){

//loadgame & savegame logic

//check for players requested action using NLP interface
int verb = 1; //	verb = verbNLP
//	noun = nounNLP
string noun = "test"; 



switch (verb){

//enum Verb{look move help inventory lookAt take fire open close push mine launch land eat bow say use invalid}; 

	//Do non item actions
	//look around current location
	case look: 
		player.getLocation()->look(); 
		break; 

	//go somewhere, check exit is accessible and go there
	case move:
		{
			Area* location = player.getLocation(); 
			bool exitValid = location->hasExit(noun); 
			if(exitValid){
				player.setLocation(location->getExit(noun));  
				player.getLocation()->printDescription(); 
			} else {
				std::cout << "Sorry that doesn't appear to be a place you can get to from here. \n"; 
			}
		}
		break; 

	case help: 
		cout << "Try one of the following commands: \n Look \n Look at \n move \n take \n fire \n open \n close \n push \n launch \n land\n" ; 
		break; 

	case inventory: 
		player.listInventory(); 
		break; 
	// If an item action is requested check if the item is available
	//Check every inventory item for the item name
	case lookAt: 
		if(player.lookAt(noun)){
			break; 
		}else if(player.getLocation()->lookAt(noun)){ 
			break; 
		}else{
			cout << "Sorry you can't look at that right now\n" ; 
			break; 
		}
	case take: 
		if(player.take(noun)){
			break; 
		}else{
			cout << "Sorry you don't seem to be able to take that right now.\n"; 
			break; 
		}

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
