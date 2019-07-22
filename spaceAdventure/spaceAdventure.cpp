//Space Adventure Game main code for CS497
//Written by Tim Ip ONID # 933912896
//

#include <iostream> 
#include <vector>
#include "spaceAdventure.h"

using std::string; 
using std::cout; 



int main(){

	#include "testData.h"
	bool gameOver = false; 
	//Declaring the Area objects
	Area Mercury("Mercury", "mercury_short.txt", "mercury_long.txt"), Venus1("Venus_1", "venus1_short.txt","venus1_long.txt"), Earth("Earth", "earth_short.txt", "earth_long.txt"), 
   	EarthM("Earth_Moon", "earthmoon_short.txt", "earthmoon_long.txt"), LostM("Lost_Moon", "lostMoon_short.txt", "lostMoon_long.txt"), Sun("Sun", "sun_short.txt", "sun_long.txt"), 
   	Mars("Mars", "mars_short.txt", "mars_long.txt"), Jupiter("Jupiter", "jupiter_short.txt", "jupiter_long.txt"), Saturn("Saturn", "saturn_short.txt", "saturn_long.txt"), 
   	Uranus("Uranus", "uranus_short.txt", "uranus_long.txt"), Pluto("Pluto", "pluto_short.txt", "pluto_long.txt"), PlutoM("Pluto_Moon", "pluto_moon_short.txt", "pluto_moon_long.txt"), 
   	Neptune1("Neptune_1", "neptune_1_short.txt", "neptune_1_long.txt"), Neptune2("Neptune_2", "neptune_2_short.txt", "neptune_2_long.txt"), Venus2("Venus_2", "venus2_short.txt", "venus2_long.txt");
	std::vector<Area*> planets;
	planets.push_back(&Mercury);
	planets.push_back(&Venus1);
	planets.push_back(&Earth);
	planets.push_back(&EarthM);
	planets.push_back(&LostM);
	planets.push_back(&Sun);
	planets.push_back(&Mars);
	planets.push_back(&Jupiter);
	planets.push_back(&Saturn);
	planets.push_back(&Uranus);
	planets.push_back(&Pluto);
	planets.push_back(&PlutoM);
	planets.push_back(&Neptune1);
	planets.push_back(&Neptune2);
	planets.push_back(&Venus2);

	//Print out intro text
	cout << "Welcome to the space adventure\n";
	player.getLocation()->printDescription(); 

while (!gameOver && player.getLife() > 0 && player.getGas() > 0 ){

//loadgame & savegame logic
	if(userChooses == "loadgame") {
	}
	else {
	
	}

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
