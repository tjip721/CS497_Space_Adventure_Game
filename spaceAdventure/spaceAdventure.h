#ifndef SPACEADVENTURE_H
#define SPACEADVENTURE_H
#include <string>
#include <vector> 
#include "Exit.h"
#include "Area.h"
#include "Action.h"
#include "Item.h"
#include "Pickaxe.h"
#include "Flashlight.h"
#include "Mushroom.h"
#include "PowerCrystal.h"
#include "Spaceship.h"
#include "data.h"
#include "Alien.h"
#include "Human.h"

using std::string;
class Player;
//open description file to save to an object variable
string get_file_data(string text);

void getWelcome(Player* player);
void moveFxn(string noun, Player player); 
bool itemExists(std::vector<Area*> planets, Player player, string item);


#endif
