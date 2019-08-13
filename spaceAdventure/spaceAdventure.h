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
#include "Doohickey.h"
#include "Transmitter.h"
#include "data.h"
#include "Alien.h"
#include "Human.h"
#include "ScrewDriver.h"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

using std::string;
class Player;
//open description file to save to an object variable
string get_file_data(string text);

void getWelcome(Player* player);
void moveFxn(string noun, Player &player, Item &spaceship); 
bool itemExists(std::vector<Area*> planets, Player player, string item);
void read_uif_files(std::string fileName);

#endif
