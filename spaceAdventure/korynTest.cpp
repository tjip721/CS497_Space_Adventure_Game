#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "Item.h"


using namespace std;
std::string filename = "saveLog.txt";
std::string planets[]={"Sun", "Mercury", "Lost Moon", "Earth's Moon", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", 
"Pluto", "Pluto's Moon"};

void saveGame(Player::Player player1) {
   std::fstream savegame;
   savegame.open("saveLog.txt", std::fstream::out | std::fstream::trunc);
   savegame << player1.getLife() << " " << player1.getGas() << " " << player1.getLocation()->getName();
   //add the player inventory
   std::vector<Item*> playerItems = player1.getPlayerInventory();
   for(int i=0; i < playerItems.size(); i++) {
       savegame << playerItems[i]->getName() << " ";
   }
   savegame << endl;
   //Add areas to text file

   savegame.close();
}

int main() {
   cout << filename << endl;
   Item shoe("shoe", "shoe", true); 
   Item knife("knife", "knife", true); 
   std::vector<Item*> newItem;
   newItem.push_back(&shoe);
   newItem.push_back(&knife);
   Area Mars;
   Player User1(30, 30);
   User1.initializeInventory(newItem);
   saveGame(User1);
   return 0;
}
