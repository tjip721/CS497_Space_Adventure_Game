//Space Adventure Game main code for CS497
//Written by Tim Ip ONID # 933912896
//

#include <iostream> 
#include "spaceAdventure.h"

using std::string; 
using std::cout; 



int main(){

#include "testData.h"
bool gameOver = false; 

//Print out intro text
cout << "Welcome to the space adventure\n";
player.getLocation()->printDescription(); 

while (!gameOver && player.getLife() > 0 && player.getGas() > 0 ){

//loadgame & savegame logic

//check for players requested action using NLP interface


//------------------------------------------------
//Temporary read in commands for TESTing
int verb; //	verb = verbNLP
//	noun = nounNLP
string noun = "test"; 
cout << "Give enumerated verb choice as int:0 look, 1 move, 2 help, 3 inventory,4 lookAt, 5 take, 6 drop 7 fire, 8 open, 9 close, 10 push, 11 mine, 12 launch, 13 land, 14 eat, 15 bow, 16 say, 17 use, 18 invalid\n";

std::cin >> verb; 
cout << "Give target item name:"; 
std::cin >> noun;

//-----------------------------------------------

enum Verb{look, move, help, inventory, lookAt, take, drop, fire, open, close, push, mine, launch, land, eat, bow, say, use, invalid}; 


switch (verb){
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
		cout << "Try one of the following commands: \n Look \n Look at \n Move \n Take \n Fire \n Open \n Close \n Push \n Launch \n Land\n" ; 
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
	case drop: 
		if(player.drop(noun)){
			cout << "You dropped the " << noun << ".\n";
			break; 
		} else {
			cout << "Sorry you don't seem to have that in your inventory... soooo you can't drop it.\n"; 
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
		std::cout << "Uh that doesn't make sense try something else.\n"; 		
		break; 

}
cout << "\n";


}

return 0; 
}
