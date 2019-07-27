#ifndef SPACEADVENTURE_H
#define SPACEADVENTURE_H
#include <string>
#include <vector> 
#include "Exit.h"
#include "Area.h"
#include "Action.h"
#include "Item.h"
#include "Player.h"
#include "data.h"

using std::string;

//open description file to save to an object variable
string get_file_data(string text);


void moveFxn(string noun, Player player); 



#endif
