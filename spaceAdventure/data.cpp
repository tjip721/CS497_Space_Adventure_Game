#include "data.h"

std::string get_file_data(std::string fileName){
	std::fstream r_file;
	std::string file_read;
	r_file.open(fileName);

	getline(r_file, file_read);
	r_file.close();
	return file_read;
}
void saveGame(Player::Player player1, std::vector<Area*> planets) {
   std::fstream savegame;
   savegame.open("saveLog.txt", std::fstream::out | std::fstream::trunc);
   savegame << player1.getLife() << " " << player1.getGas() << " " << player1.getLocation()->getName() << " ";

   //add the player inventory
   std::vector<Item*> playerItems = player1.getPlayerInventory();
   for(int i=0; i < playerItems.size(); i++) {
       savegame << playerItems[i]->getName() << " ";
   }
   savegame << endl;

   //Add area inventories & firstEntry to text file
   std::cout << planets.size();
   for (int j=0; j < planets.size(); j++) {
      savegame << planets[j]->getAreaEntry() << " ";
      std::vector<Item*> planetItems= planets[j]->getItems();
      for (int p=0; p < planetItems.size(); p++) {
         savegame << planetItems[p]->getName();
      }
      savegame << endl;
   }
   savegame.close();
}
void open_log(){}
void remove_log(){}
