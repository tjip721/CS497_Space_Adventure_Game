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

Item* getItemPtr(string itemName, vector<Item> *itemList) {
	for(int i=0; i<(*itemList).size();i++){
		if (((*itemList)[i].getName()).compare(itemName) == 0) {
			return &(*itemList)[i];
		}
	}
	return NULL;
}

int main() {
	srand(time(NULL));
	vector<Item> items=loadItems();

	enum Verb { look, move, help, inventory, lookAt, take, drop, fire, push, mine, launch, land, eat, bow, say, use, invalid, savegame, wear, status, quit };
	map<string, Verb> verbMap = {
		{"look",look},{"move",move},{"help",help},{"inventory",inventory},{"look at",lookAt},{"take",take},{"drop",drop},{"fire",fire},{"push",push},{"mine",mine},{"launch",launch},
		{"land",land},{"eat",eat},{"bow",bow},{"say",say},{"use",use},{"",invalid},{"savegame",savegame},{"wear",wear},{"status",status},{"quit",quit}
	};

	//Initialize parser
	Parser parser;
	int verb;
	string noun, command;
	if (parser.loadFiles(VERB_FILE_LIST, NOUN_FILE_LIST) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}

	// Welcome message
	Player player;
	vector<Area> planets;
	vector<Exit> exits;
	string userChooses;
	cout << "Welcome to the space adventure\n What do you want to do? \n Load Game\n New Game\n";
	getline(cin, userChooses);
	transform(userChooses.begin(), userChooses.end(), userChooses.begin(), tolower);
	//load the game
	//createNewPlanets(planets, items); 
	if(userChooses == "loadgame" || userChooses =="load" || userChooses == "load game") {
		cout << "Loading game..." << endl;
		int fileReturn;
		fileReturn = open_log();
		if(fileReturn == 1 ) {
			vector<string> savedLines=openLoadFile("loadfiles/areas.txt");
			planets=loadPlanets(savedLines, items);
			player=createNewPlayer(savedLines, planets, items);
		}
		else {
			vector<string> savedLines=openLoadFile("saveLog.txt");
			planets=loadPlanets(savedLines, items);
			player=loadOldPlayer(savedLines, planets, items);
		}
	}
	else{
		vector<string> savedLines=openLoadFile("loadfiles/areas.txt");
		planets=loadPlanets(savedLines, items);
		player=createNewPlayer(savedLines, planets, items);
	}
	//Create exit objects + setting exits for each planet
	exits=createExits(planets);
	setPlanetExits(planets, exits);
	//Welcome text displaying object of the game
	//getWelcome(&player);
	saveGame(&player, planets);


	bool gameOver = false;
	int turnCounter = 0;
	int suffocationCounter = 15;
	player.getLocation()->addItem(getItemPtr("Spaceship", &items));
	while (!gameOver && player.getLife() > 0 && player.getGas() > 0 ){
		turnCounter++; 
		// Cold area check
		if(!player.isWearing("Jacket") && (player.getLocation()->getName().compare("Pluto")==0 ||
			player.getLocation()->getName().compare("Uranus")==0 || 
			player.getLocation()->getName().compare("Neptune")==0) && turnCounter>15 ){
					//cout << "Quick, put on your jacket!" << endl;
					cout << "You didn't put your jacket on. You froze to DEATH.\n";
					read_uif_files("UIf_files/failure.txt");
					gameOver = true;
					break;
		}

		// No oxygen check
		
		if( (player.getLocation()->getName().compare("Lost Moon") || player.getLocation()->getName().compare("Jupiter")) && !player.getLocation()->hasOxygen() ){
			if(suffocationCounter < 0){
				gameOver = true;
				read_uif_files("UIf_files/failure.txt");
				cout << "Oh no looks like you suffocated.\n";
				break;
			}
			cout << "You don't seem to be able to breath here.\n";
			suffocationCounter--;
		}

		// Process user input
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
	
		Area* location = player.getLocation();
		switch (verb){
			//look around current location
			case look:
				player.getLocation()->look();
				break;

			//go somewhere, check exit is accessible and go there
			case move:
				if(player.isWearing("Shoes") && !location->isSpace()){
					moveFxn(noun, player, getItemPtr("Spaceship",&items));
				}else{
					cout << "It's hard to walk anywhere on this surface in your bare feet...\n"; 
				}
				if( (player.getLocation()->getName().compare("Lost Moon") || player.getLocation()->getName().compare("Jupiter")) ){
					suffocationCounter = 1; 
				}
				break;

			case help:
				cout << "Try one of the following commands: \n Look \n Look at \n Move \n Inventory \n Take \n Drop \n Fire \n Eat \n Bow \n Say \n Use \n Push \n Launch \n Land \n Wear \n Mine \n Status \n Quit \n Savegame \n";
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
					if (noun.compare("Opportunity Rover") == 0 && !itemExists(&planets, player, "Transmitter")) {
						player.getLocation()->addItem(getItemPtr("Transmitter",&items));
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

			case push:
				if(noun.compare("Alien")==0 && location->hasItem("Alien")){
					Alien* pAlien = dynamic_cast<Alien*>(location->getItem("Alien")); 
					if(pAlien != nullptr){
						pAlien->aggravate(); 
						cout << "Looks like that aggravated the alien, it is now hostile towards you.\n"; 
					}
				}else{
					cout << "You can't push that.\n"; 
				}
				break;

			case mine:
				if(!player.use("Pick Axe")){
					cout << "Looks like you can't mine right now.\n"; 
				}
				break;

			case launch:
				// IF spaceship is present launch to space
				if(location->hasItem("Spaceship") && location->getLaunchExit() != NULL){
					if(player.isWearing("Shoes") && !location->isSpace()){
						moveFxn(noun, player, getItemPtr("Spaceship",&items));
					}else{
						cout << "You're having trouble walking to your space ship in your bare feet...\n"; 
					}
				}else{
					cout << "Sorry you don't appear to be able to launch from here.\n";
				}
				if( (player.getLocation()->getName().compare("Lost Moon") || player.getLocation()->getName().compare("Jupiter")) ){
					suffocationCounter = 1; 
				}
				break;

			case land:
				//If in space land on specified planet
				if(location->isSpace()){
					if(noun.compare("Earth")==0){
						if(((Spaceship*)getItemPtr("Spaceship",&items))->isFixed()){
							moveFxn(noun, player, getItemPtr("Spaceship",&items));
						} else {
							cout << "Sorry your space ship isn't fixed yet. It won't survive entry into Earth's atmosphere.\n"; 
						}
					}else{
						moveFxn(noun, player, getItemPtr("Spaceship", &items));
					}
				}else{
					cout << "You will need to be flying in space before you can land your ship.\n";
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
					read_uif_files("crystal.txt");
					cout <<"You bow to the Alien with Crysallith in your hands. It seems to accept your peace offering.\n"; 
				}else{
					cout << "You bowed, but no one seemed to notice.\n"; 	
				}
				break;

			case say:
				if(noun=="Alien" && location->hasItem("Alien") ){
					read_uif_files("UIF_files/alien.txt");
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
			case status:
				cout << "You have " << player.getLife() << " years to live and " << player.getGas() << " gas left.\n";
				break;
			case quit:
				cout << "Are you sure you want to quit and exit the game? Type yes or no: ";
				getline(cin, command);
				transform(command.begin(), command.end(), command.begin(), tolower);
				if(command.compare("yes") == 0) {
					return 0;
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


void moveFxn(string noun, Player &player, Item *spaceship){
	Area* location = player.getLocation();
	bool exitValid = location->hasExit(noun);
	if(exitValid){
		Exit* targetExit = location->getExit(noun);
		if (targetExit->getName().compare("Space") == 0) {
			player.getLocation()->eraseItem("Spaceship");
		}
		player.removeLife(targetExit->getLifeDistance());
		player.removeGas(targetExit->getGasDistance());
		if(player.getLife() <= 0){
			cout << "Oh no! It appears you died of old age before reaching Earth. \n GAME OVER. \n";
		}else if (player.getGas() <= 0){
			cout << "Oh no! It appears you ran out of gas and are stranded in space. \n GAME OVER. \n";
		}
		player.setLocation(location->getExit(noun)->getArea());
		if (location->getName().compare("Space") == 0) {
			player.getLocation()->addItem(spaceship);
		}
		player.getLocation()->look();
	} else {
		std::cout << "Sorry that doesn't appear to be a place you can get to from here. \n";
	}
}

void read_uif_files(string fileName){
	cout << string(20, '\n');
	fstream r_file;
	string file_read;
	const string readFile=fileName;
	r_file.open(readFile);
	while(!r_file.eof()) {
		getline(r_file, file_read);
		cout << file_read << endl;
	}
	r_file.close();	
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
	//player->getLocation()->printDescription();
}

bool itemExists(vector<Area> *planets, Player player, string item) {
	if (player.hasItem(item)) {
		return true;
	}
	for (int i = 0; i < planets->size();i++) {
		if ((*planets)[i].hasItem(item)) {
			return true;
		}
	}
	return false;

}
