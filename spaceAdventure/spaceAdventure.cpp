//Space Adventure Game main code for CS497
//Written by Tim Ip ONID # 933912896
//

#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <algorithm>
#include "spaceAdventure.h"
#include "parser.h"
#include "Player.h"
//#include "testData.h"

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::fstream;
using std::cin;
using std::fstream;
using std::transform;


// Make sure that the word_files folder is in the same directory as the executable
const string VERB_FILE_LIST = "./word_files/verb_files.txt";
const string NOUN_FILE_LIST = "./word_files/noun_files.txt";
vector<string> loadingGame;

int main() {

	srand(time(NULL));
	bool gameOver = false;

	Player player;
	//Declaring the Area objects
	Area Mercury("Mercury", "mercury_short.txt", "mercury_long.txt"), Venus1("Venus_1", "venus1_short.txt","venus1_long.txt"), Earth("Earth", "earth_short.txt", "earth_long.txt"),
   	EarthM("Earth_Moon", "earthmoon_short.txt", "earthmoon_long.txt"), LostM("Lost_Moon", "lostMoon_short.txt", "lostMoon_long.txt"), Sun("Sun", "sun_short.txt", "sun_long.txt"),
   	Mars("Mars", "mars_short.txt", "mars_long.txt"), Jupiter("Jupiter", "jupiter_short.txt", "jupiter_long.txt",false, false), Saturn("Saturn", "saturn_short.txt", "saturn_long.txt"),
   	Uranus("Uranus", "uranus_short.txt", "uranus_long.txt"), Pluto("Pluto", "pluto_short.txt", "pluto_long.txt"), PlutoM("Pluto_Moon", "pluto_moon_short.txt", "pluto_moon_long.txt"),
   	Neptune1("Neptune_1", "neptune_1_short.txt", "neptune_1_long.txt", true), Neptune2("Neptune_2", "neptune_2_short.txt", "neptune_2_long.txt"), Venus2("Venus_2", "venus2_short.txt", "venus2_long.txt");

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

	// Declare Item Objects
	Item Shoes("Shoes", "shoes.txt", 1),
		Gas("Gas", "gas.txt", 1),
		Crysallith("Crysallith", "crysallith.txt", 0),
		OpportunityR("Opportunity Rover", "opportunity_rover.txt", 0),
		Rock("Rock", "rock.txt", 0),
		Jacket("Jacket", "jacket.txt", 1);

	Doohickey doohickey("Doohickey", "doohickey.txt", 1);
	Flashlight flashlight("Flashlight", "flashlight.txt", 1);
	Mushroom mushroom("Mushroom", "mushroom.txt", 1);
	Pickaxe PickA("Pick Axe", "pickaxe.txt", 1);
	PowerCrystal PowerC("Power Crystal", "powercrystal.txt", 0);
	ScrewDriver ScrewD("Screw Driver", "screwdriver.txt", 1);
	Spaceship spaceship("Spaceship", "spaceship.txt", 0);
	Transmitter transmitter("Transmitter", "transmitter.txt", 1);

	std::vector<Item*> items;
	items.push_back(&Shoes);
	items.push_back(&Gas);
	items.push_back(&PowerC);
	items.push_back(&Crysallith);
	items.push_back(&OpportunityR);
	items.push_back(&transmitter);
	items.push_back(&ScrewD);
	items.push_back(&doohickey);
	items.push_back(&PickA);
	items.push_back(&Rock);
	items.push_back(&Jacket);
	items.push_back(&flashlight);
	items.push_back(&mushroom);
	items.push_back(&spaceship);

	planets[0]->addItem(&Shoes);

	enum Verb { look, move, help, inventory, lookAt, take, drop, fire, open, close, push, mine, launch, land, eat, bow, say, use, invalid, savegame, wear };

	// Map for converting string to enum
	map<string, Verb> verbMap = {
		{"look",look},{"move",move},{"help",help},{"inventory",inventory},{"inspect",lookAt},{"take",take},{"drop",drop},{"fire",fire},{"open",open},{"close",close},
		{"push",push},{"mine",mine},{"launch",launch},{"land",land},{"eat",eat},{"bow",bow},{"say",say},{"use",use},{"",invalid},{"savegame",savegame},{"wear",wear}
	};

	//Initialize parser
	Parser parser;
	int verb;
	string noun, command;
	if (parser.loadFiles(VERB_FILE_LIST, NOUN_FILE_LIST) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}

	//Print out intro text
	string userChooses;
	cout << "Welcome to the space adventure\n What do you want to do? \n Load Game\n New Game\n";
	getline(cin, userChooses);
	transform(userChooses.begin(), userChooses.end(), userChooses.begin(), tolower);
	if(userChooses == "loadgame" || userChooses =="load") {
		cout << "Loading game..." << endl;
		int fileReturn;
		fileReturn = open_log();
		if(fileReturn == 1 ) {
			player=createNewPlayer(&Uranus, &Mercury);
		}
		else {
			vector<string> savedLines=parseLoadFile();
			player=loadOldPlayer(savedLines, planets, items);
			loadOldPlanets(savedLines, planets, items);
		}
	}
	else{
		player= createNewPlayer(&Uranus, &Mercury);
	}

	getWelcome(&player);

	int turnCounter = 0; 
	while (!gameOver && player.getLife() > 0 && player.getGas() > 0 ){
		turnCounter++; 
		if(!player.isWearing("Jacket") && (player.getLocation()->getName().compare("Pluto")==0 ||
			player.getLocation()->getName().compare("Uranus")==0 || 
			player.getLocation()->getName().compare("Neptune")==0) && turnCounter>2 ){
					cout << "It is cold! You froze to DEATH. GAME OVER. \n";
					gameOver = true;
					break;
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

		verb = invalid;
		noun.clear();
		command.clear();
		cout << "Please enter a command: ";
		getline(cin, command);
		parser.processInput(command);
		verb = verbMap[parser.getVerb()];
		if (parser.getNouns().size() > 0) {
			noun = parser.getNouns()[0];
		}
		// Left this in for exiting game while testing
		transform(command.begin(), command.end(), command.begin(), toupper);
		if (command == "EXIT") {
			exit(0);
		}
		
		Area* location = player.getLocation();
		switch (verb){
			//Do non item actions
			//look around current location
			case look:
				player.getLocation()->look();
				break;

			//go somewhere, check exit is accessible and go there
			case move:
				if(player.isWearing("Shoes")){
					moveFxn(noun, player);
				}
				break;

			case help:
				cout << "Try one of the following commands: \n Look \n Inspect \n Move \n Inventory \n Take \n Drop \n Fire \n Eat \n Bow \n Say \n Use \n Open \n Close \n Push \n Launch \n Land \n Wear \n Mine \n Savegame \n";
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
					// If player looks at rover for the first time, add transmitter to area's items
					if (noun.compare("Opportunity Rover") == 0 && !itemExists(planets, player, "Transmitter")) {
						player.getLocation()->addItem(&transmitter);
						cout << "A transmitter is attached to Opportunity Rover.\n";
					}
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
				//Throw something
				if(noun.compare("Shoes")!=0){
					player.drop(noun);
				//Throw your shoe...
				}else if(player.drop("Shoes")){
					 cout<<"You threw your shoe"; 
					if(location->hasItem("Alien")){
						Alien* pAlien = dynamic_cast<Alien*>(location->getItem("Alien")); 
						if(pAlien != nullptr){
							//((Alien *)(location->getItem("Alien")))->aggravate(); 
							pAlien->aggravate(); 
							cout << "Looks like that aggravated the alien, it is now hostile towards you.\n"; 
						}
					}
				}else{
					cout << "Nothing happened.\n"; 
				}
				break;

			case open:
				break;

			case close:
				break;

			case push:
				break;

			case mine:
				if(!player.use("Pick Axe")){
					cout << "Looks like you can't mine right now.\n"; 
				}
				break;

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
				if (noun.compare("Mushroom") != 0 || !player.use("Mushroom")) {
					cout << "You can't eat that.\n";
				}
				break;

			case bow:
				if(location->hasItem("Alien") && player.hasItem("Crysallith")){
					Alien* pAlien = dynamic_cast<Alien*>(location->getItem("Alien")); 
					if(pAlien != nullptr ){
						pAlien->makePeace(); 
					}
					cout <<"You bow to the Alien with Crysallith in your hands. It seems to accept your peace offering.\n"; 
				}else{
					cout << "You bowed, but no one seemed to notice.\n"; 	
				}
				break;

			case say:
				if(noun=="Alien" && location->hasItem("Alien") ){
					Alien* pAlien = dynamic_cast<Alien*>(location->getItem("Alien")); 
					if(pAlien != nullptr ){
						cout << "The alien replies: "; 
						pAlien->talk(); 
					}
				} else if (noun == "Human"){
					Human* pHuman= dynamic_cast<Human*>(location->getItem("Human")); 
					if(pHuman!= nullptr ){
						cout << "The human replies: "; 
						pHuman->talk(); 
					}
				} else {
					cout << "You speak but no one seems to be around to hear you.\n"; 
				}
				break;

			case use:
				player.use(noun); 
				break; 

			case invalid:
				std::cout << "Uh that doesn't make sense try something else.\n";
				break;

			case savegame:
				saveGame(&player, planets);
				break;

			case wear:
				if ((noun.compare("Shoes") == 0 || noun.compare("Jacket") == 0) &&
					player.hasItem(noun))
				{
					player.use(noun);
				}
				else {
					cout << "You can't wear that.\n";
				}
				break;
		}
		if(location->hasItem("Alien")){
			Alien* pAlien = dynamic_cast<Alien*>(location->getItem("Alien")); 
			if(pAlien != nullptr && pAlien->isHostile()){
				pAlien->attack(&player); 
			}
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
	r_file.open(readFile);
	while(!r_file.eof()) {
		getline(r_file, file_read);
		//cout << file_read << endl;
	}
	//done to clear screen
	cout << string(20, '\n');
	cout << file_read << endl;
	r_file.close();
	return file_read;
}
void getWelcome(Player* player){

	if(player->getLocation()->getName() == "Uranus"){
		get_file_data("welcome_1.txt");
		cout << "As of now you have: " << player->getLife() << " years left" << endl;
	}
	else {
		get_file_data("welcome_0.txt");
		cout << "As of now you have: " << player->getLife() << " years left and " << player->getGas() << " million miles left in the tank\n\n" << endl;
	}
	player->getLocation()->printDescription();
}

bool itemExists(std::vector<Area*> planets, Player player, std::string item) {
	if (player.hasItem(item)) {
		return true;
	}
	for (Area* planet : planets) {
		if (planet->hasItem(item)) {
			return true;
		}
	}
	return false;
}
