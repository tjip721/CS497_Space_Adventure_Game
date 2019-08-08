#include "data.h"
#include "Player.h"
#include "Area.h"
#include "Item.h"

using std::fstream;
using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;

string saveLog="saveLog.txt";

void saveGame(Player* player1, std::vector<Area*> planets) {
   fstream savegame;
   savegame.open(saveLog, fstream::out | fstream::trunc);
   savegame << "User " << player1->getLife() << " " << player1->getGas() << " " << player1->getLocation()->getName() << " ";

   //add the player inventory
   vector<Item*> playerItems = player1->getPlayerInventory();
   for(int i=0; i < playerItems.size(); i++) {
       savegame << playerItems[i]->getName() << " ";
   }
   savegame << endl;

   //Add area inventories & firstEntry to text file
   for (int j=0; j < planets.size(); j++) {
      savegame << planets[j]->getName() << " " << planets[j]->getAreaEntry() << " ";
      vector<Item*> planetItems= planets[j]->getItems();

      for (int p=0; p < planetItems.size(); p++) {
         savegame << planetItems[p]->getName() << " ";
      }
      savegame << endl;
   }
   savegame.close();
}

int open_log(){
   fstream loadgame;
   loadgame.open(saveLog, fstream::in);
   if(loadgame.is_open()){
      loadgame.close();
      return 0;
   }
   else{
      cout << "No file to load. Creating a new game" << endl;
      return 1;
   }
}
void remove_log(){}


Player  createNewPlayer(Area* Uranus, Area* Mercury, Item* jacket, Item* shoes, Item* flashlight, Item* spaceship) {
   Player player;
   double playerLife, playerGas;
   playerGas=rand() % 3 + 1;
   playerLife= rand()% 40 + 30;
   int location=rand()% 2 + 1;
   std::cout <<location << std::endl;
   if (location == 1){
      player.setVars(playerGas, playerLife);
      player.setLocation(Uranus);
   }
   else {
      player.setVars(playerGas, playerLife);
      player.setLocation(Mercury);
   }
   player.getLocation()->addItem(spaceship);
   player.addInventory(jacket);
   player.addInventory(shoes);
   player.addInventory(flashlight);
   return player;
}
vector<string> parseLoadFile() {
   string val;
   std::vector<string> fileLine;
   fstream loadFile;
   stringstream loadVector;
   loadFile.open(saveLog);
   while(!loadFile.eof()){
      getline(loadFile, val);
      fileLine.push_back(val);
   }
   return fileLine;
}

Player loadOldPlayer(vector<string> savedLines, vector<Area*> area, vector<Item*> items){
   Player player;
   string val, inventory, dummy, location;
   double health, gas;
   stringstream parseString;
   string fileString = savedLines[0];
   parseString.str(fileString);
   parseString >> dummy;
   parseString >> health;
   parseString >> gas;
   parseString >> location;
   for(int i=0; i < area.size(); i++) {
      if(area[i]->getName() == location) {
         player.setLocation(area[i]);
      }
   }
   player.setVars(gas, health);
   while(getline(parseString, inventory, ' ')){
      for(int i=0; i < items.size(); i++) {
         if(items[i]->getName() == inventory) {
            player.addInventory(items[i]);
         }  
      }
   }
   return player;
}

void loadOldPlanets(std::vector<std::string> savedLines, std::vector<Area*> planets, std::vector<Item*> items){

   string planetName, inventory, dummy;
   bool hasVisited;
   stringstream parseString;
   for(int j=1; j < savedLines.size(); j++){
      string fileString = savedLines[j];
      parseString.str(fileString);
      parseString >> dummy;
      parseString >> hasVisited;
      for(int i=0; i < planets.size(); i++){
         if(planets[i]->getName() == dummy) {
            planets[i]->setEntry(hasVisited);
            while(getline(parseString, inventory, ' ')) {
               for(int i=0; i < items.size(); i++) {
                  if(items[i]->getName() == inventory) {
                     planets[i]->addItem(items[i]);
                  }  
               }
            }
         }
      }
   }
}
void createNewPlanets(std::vector<Area*> planets, std::vector<Item*> items){
   for(int i=0; i < planets.size(); i++) {
      for(int j=0; j < items.size(); j++){
         //if(((planets[i]->getName == "Earth_Moon") || (planets[i]->getName()== "Eath")) && (items[j]->getName()=="Human")) { planets[i]->addItem(items[j]); }
         if(((planets[i]->getName() == "Mercury") || (planets[i]->getName() == "Venus2")) && (items[j]->getName() == "Gas")) { planets[i]->addItem(items[j]); }
         if((planets[i]->getName() == "Neputune2") && (items[j]->getName() == "Screw Driver")) { planets[i]->addItem(items[j]); }
         if(((planets[i]->getName() == "Lost Moon") || (planets[i]->getName() == "Pluto") || (planets[i]->getName() == "Venus2") || (planets[i]->getName() == "Venus1"))&&
            (items[j]->getName() == "Alien")){ planets[i]->addItem(items[j]); }
         if((planets[i]->getName() == "Pluto_Moon")&& (items[j]->getName() == "Pick Axe")) { planets[i]->addItem(items[j]); }
         if(((planets[i]->getName() =="Lost_Moon") || (planets[i]->getName() == "Jupiter")) && (items[j]->getName() == "Mushroom")) { planets[i]->addItem(items[j]); }
         if((planets[i]->getName() == "Pluto_Moon") && (items[j]->getName() == "Crysallith")) { planets[i]->addItem(items[j]); }
         if(((planets[i]->getName() == "Uranus") || (planets[i]->getName() == "Pluto")) && (items[j]->getName()=="Doohickey")) { planets[i]->addItem(items[j]); }
         if((planets[i]->getName() == "Saturn") && (items[j]->getName()=="Power Crystal")){ planets[i]->addItem(items[j]); }
         if(((items[j]->getName() == "Opportunity Rover") || (items[j]->getName() == "Transmitter")) && (planets[i]->getName() == "Mars")){ planets[i]->addItem(items[j]); }
         if(items[j]->getName() == "Rock") { planets[i]->addItem(items[j]); }
      }
   }

   //Mercury = Gas
   //Venus1=Alien
   //Venus2=Gas, Aliens, Humans
   //Earth= Humans
   //Uranus=Doohickey
   //Mars=Opportunity Rover, Transmitter
   //Saturn= Power Crystal
   //Neptune1=Rock
   //Neputune2=ScrewDriver, Rock
   //Pluto=Doohickey, Aliens
   //Plutos moon=Crysallith, pickaxe
}
