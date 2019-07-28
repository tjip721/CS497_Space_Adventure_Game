#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
//#include "Player.h"
//#include "Area.h"
class Player;
class Area; 
class Item;



//UI functions --to be pretty
void display_planet();
void display_descriptions();
//i.e. game over, start menue
void display_gameInstances();
Player createNewPlayer(Area* Mercury, Area* Uranus);
void createNewPlanets(std::vector<Area*> planets);
//save log file conditions, will be called in the "main" game
void saveGame(Player* player1, std::vector<Area*> planets); 
//Parse the save_log.txt and place in constructor for the areas + user
int open_log();
Player loadOldPlayer(std::vector<std::string> savedLines, std::vector<Area*> planets, std::vector<Item*> items);
void loadOldPlanets(std::vector<std::string> savedLines, std::vector<Area*> planets, std::vector<Item*> items);
std::vector<std::string> parseLoadFile();
#endif // DATA_H
