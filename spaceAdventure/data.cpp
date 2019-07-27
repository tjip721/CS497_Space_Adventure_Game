#include "data.h"
#include "Player.h"
#include "Area.h"

void saveGame(Player::Player player1, std::vector<Area*> planets) {
   std::fstream savegame;
   savegame.open("saveLog.txt", std::fstream::out | std::fstream::trunc);
   savegame << "User " << player1.getLife() << " " << player1.getGas() << " " << player1.getLocation()->getName() << " ";

   //add the player inventory
   std::vector<Item*> playerItems = player1.getPlayerInventory();
   for(int i=0; i < playerItems.size(); i++) {
       savegame << playerItems[i]->getName() << " ";
   }
   savegame << endl;

   //Add area inventories & firstEntry to text file
   for (int j=0; j < planets.size(); j++) {
      savegame << planets[j]->getName() << " " << planets[j]->getAreaEntry() << " ";
      std::vector<Item*> planetItems= planets[j]->getItems();
      for (int p=0; p < planetItems.size(); p++) {
         savegame << planetItems[p]->getName() << " ";
      }
      savegame << endl;
   }
   savegame.close();
}
void open_log(){}
void remove_log(){}
