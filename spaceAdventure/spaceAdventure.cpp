//Space Adventure Game main code for CS497
//Written by Tim Ip ONID # 933912896
//

#include <iostream> 
#include <vector>
#include <time.h>
#include <map>
#include "spaceAdventure.h"
#include "parser.hpp"

//#include "testData.h"

using std::string; 
using std::cout; 
using std::endl; 
using std::vector;
using std::fstream;
using std::cin;
using std::fstream;


// Make sure that the word_files folder is in the same directory as the executable
const string VERB_FILE_LIST = "word_files/verb_files.txt";
const string NOUN_FILE_LIST = "word_files/noun_files.txt";
vector<string> loadingGame;

int main(){

	srand(time(NULL));
	bool gameOver = false; 

	Player player;
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
	//Declaring Item objects
	Item Shoe("Shoe","shoe.txt",1), Gas("Gas","gas.txt",1), PowerC("Power Crystal","powercrystal.txt",1), Crysallith("Crysallith","crysallith.txt",1), OpportunityR("Opportunity Rover","opportunity_rover.txt",0), Transmitter("Transmitter","transmitter.txt",1), ScrewD("Screw Driver","screwdriver.txt",1), Doohickey("Doohickey","doohickey.txt",1), PickA("Pick Axe","pickaxe.txt",1), Rock("Rock","rock.txt",0), Jacket("Jacket","jacket.txt",1), Flashlight("Flashlight","flashlight.txt" ,1), Mushroom("Mushroom", "mushroom.txt", 1);
	
	planets[0]->addItem(&Shoe);
	
	std::vector<Item*> items;
	items.push_back(&Shoe);
	items.push_back(&Gas);
	items.push_back(&PowerC);
	items.push_back(&Crysallith);
	items.push_back(&OpportunityR);
	items.push_back(&Transmitter);
	items.push_back(&ScrewD);
	items.push_back(&Doohickey);
	items.push_back(&PickA);
	items.push_back(&Rock);
	items.push_back(&Jacket);
	items.push_back(&Flashlight);
	items.push_back(&Mushroom);

	enum Verb { look, move, help, inventory, lookAt, take, drop, fire, open, close, push, mine, launch, land, eat, bow, say, use, invalid, savegame };
	
	// Map for converting string to enum
	std::map<std::string, Verb> verbMap = {
		{"look",look},{"move",move},{"help",help},{"inventory",inventory},{"lookAt",lookAt},{"take",take},{"drop",drop},{"fire",fire},{"open",open},{"close",close},
		{"push",push},{"mine",mine},{"launch",launch},{"land",land},{"eat",eat},{"bow",bow},{"say",say},{"use",use},{"",invalid},{"savegame",savegame}
	};

	// Initialize parser
	Parser parser;
	// Load word files for parser
	if (parser.loadFiles(VERB_FILE_LIST, NOUN_FILE_LIST) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}
		
	//Print out intro text
	string userChooses;
	cout << "Welcome to the space adventure\n What do you want to do? \n Load Game\n New Game\n";
	getline(cin, userChooses);

	int fileReturn;
	double playerLife, playerGas;
	if(userChooses == "loadgame" || userChooses =="load" || userChooses == "Load") {
		cout << "Loading game..." << endl;
		fileReturn = open_log();
		if(fileReturn == 1 ) {
			player=createNewPlayer(&Uranus, &Mercury);
		}
		else {
			vector<string> savedLines=parseLoadFile();
			player=loadOldPlayer(savedLines, planets, items);
			loadOldPlanets(savedLines, planets, items);
		}	
	}else{
		player= createNewPlayer(&Uranus, &Mercury);
	}

	while (!gameOver && player.getLife() > 0 && player.getGas() > 0 ){

		if(!player.isWearing("Jacket") && (player.getLocation()->getName().compare("Pluto")==0 || 
					player.getLocation()->getName().compare("Uranus")==0 || player.getLocation()->getName().compare("Neptune")==0) ){
					cout << "Pluto is cold! You froze to DEATH. GAME OVER. \n"; 
					gameOver = true; 
		}

		int suffocationCounter = 1; 
		if( (player.getLocation()->getName().compare("Lost Moon") || player.getLocation()->getName().compare("Jupiter")) && !player.getLocation()->hasOxygen() ){
			if(suffocationCounter < 0){
				gameOver = true; 
				cout << "Oh no looks like you suffocated.\n"; 
				break; 
			}
			cout << "You don't seem to be able to breath here.\n"; 
			suffocationCounter--; 	
		}

	
		int verb = 18;
		string noun = "";
		string command;
		cout << "Please enter a command: ";
		getline(cin, command);
		parser.processInput(command);
		verb = verbMap[parser.getVerb()];
		if (parser.getNouns().size() > 0) {
			noun = parser.getNouns()[0];
		}
		//cout << "Give enumerated verb choice as int:0 look, 1 move, 2 help, 3 inventory,4 lookAt, 5 take, 6 drop 7 fire, 8 open, 9 close, 10 push, 11 mine, 12 launch, 13 land, 14 eat, 15 bow, 16 say, 17 use, 18 invalid, 19 savegame\n";
		//cout << "Give target item name:"; 

		Area* location = player.getLocation(); 
		switch (verb){
			//Do non item actions
			//look around current location
			case look: 
				player.getLocation()->look(); 
				break; 

			//go somewhere, check exit is accessible and go there
			case move:
				if(player.isWearing("Shoes") || player.getLocation()->getName().compare("Shoes")==0 ){
					moveFxn(noun, player); 
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
				// IF spaceship is present launch to space
				if(location->hasItem("Spaceship") && location->getLaunchExit() != NULL){
					moveFxn(noun, player); 
				}else{ 
					cout << "Sorry you don't appear to be able to launch from here.\n"; 
				}
				break; 

			case land: 
				//If in space land on specified planet
				if(location->hasItem("Spaceship") && location->getLandExit() != NULL){
					moveFxn(noun, player); 
				}else{
					cout << "Sorry you don't appear to be able to land there from here.\n"; 
				}
				break; 

			case eat: 
				if(player.eat(noun)){
					cout << "You at the " << noun << ".\n";
					break; 
				}else {
					cout << "You can't eat that.\n"; 
					break; 
				}

			case bow: 

			case say: 

			case use: 

			case invalid: 
				std::cout << "Uh that doesn't make sense try something else.\n"; 		
				break; 

			case savegame:
				//savegame(player, planets);
				break; 

		}
		cout << "\n";


	}

return 0; 
}


void moveFxn(string noun, Player player){
	Area* location = player.getLocation(); 
	bool exitValid = location->hasExit(noun); 
	if(exitValid){
		Exit* targetExit = location->getExit(noun); 
		player.removeLife(targetExit->getLifeDistance()); 
		player.removeGas(targetExit->getGasDistance()); 
		if(player.getLife() < 0){
			cout << "Oh no! It appears you died of old age in transit. \n GAME OVER. \n"; 
		}else if (player.getGas() < 0){
			cout << "Oh no! It appears you ran out of gas and are stranded in space. \n GAME OVER. \n"; 
		}
		player.setLocation(location->getExit(noun)->getArea());  
		player.getLocation()->look(); 
	} else {
		std::cout << "Sorry that doesn't appear to be a place you can get to from here. \n"; 
	}
}

std::string get_file_data(std::string fileName){
	fstream r_file;
	string file_read;
	const string readFile= "descriptorFiles/"+fileName;
        cout << readFile << endl;
	r_file.open(readFile);

	getline(r_file, file_read);
	cout << file_read << endl;
	r_file.close();
	return file_read;
}


