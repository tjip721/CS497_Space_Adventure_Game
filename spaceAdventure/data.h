#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include "Player.h"
//#include "Area.h"
class Player;
class Area; 



//open description file to save to an object variable
std::string get_file_data(std::string text);

//UI functions --to be pretty
void display_planet();
void display_descriptions();
//i.e. game over, start menue
void display_gameInstances();

//save log file conditions, will be called in the "main" game
void saveGame(Player* player1, std::vector<Area*> planets); 
//Parse the save_log.txt and place in constructor for the areas + user
void open_log();


#endif // DATA_H
