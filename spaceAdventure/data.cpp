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
using std::istringstream;
string saveLog="saveLog.txt";

void saveGame(Player* player1, std::vector<Area> planets) {
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
   //Earth_Moon descriptorFiles/earthmoon_short.txt descriptorFiles/earthmoon_long.txt UIf_files/rocky.txt 0 1 0 Human Rock
   for (int j=0; j < planets.size(); j++) {
            savegame << planets[j].getName() << ' '<< planets[j].getShortFile()<< ' ';
            savegame << planets[j].getLongFile() << ' ' << planets[j].getUIFile() << ' ';
            savegame << planets[j].isDark() << ' ' << planets[j].hasOxygen() <<  ' '; 
            savegame << planets[j].isSpace() << ' '<< planets[j].getAreaEntry() << ' ';
      vector<Item*> planetItems= planets[j].getItems();
      for (int p=0; p < planetItems.size(); p++) {
         savegame << planetItems[p]->getName() << ' ';
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


Player createNewPlayer(std::vector<Area> planets, std::vector<Item> items) {
   Player player;
   double playerLife, playerGas;
   playerGas=rand() % 3 + 1;
   playerLife= rand()% 40 + 30;
   int location=rand()% 2 + 1;
   player.setVars(playerGas, playerLife);
   if (location == 1){
      for(int i=0; i < planets.size(); i++){
         if(planets[i].getName() == "Uranus"){
            player.setLocation(&planets[i]);
         }
      }
   }
   else {
      for(int i=0; i < planets.size(); i++){
         if(planets[i].getName() == "Mercury"){
            player.setLocation(&planets[i]);
         }
      }
   }

   for(int i=0; i < items.size(); i++){
      if(items[i].getName() == "Spaceship") {
         player.getLocation()->addItem(&items[i]);
      }
      if((items[i].getName() == "Jacket") || (items[i].getName() == "Shoes") || (items[i].getName() == "Flashlight")){
         player.addInventory(&items[i]);
      }
   }
   return player;
}

vector<string> parseLoadFile() {
   string val;
   std::vector<string> fileLine;
   fstream loadFile;
   loadFile.open(saveLog);
   while(!loadFile.eof()){
      getline(loadFile, val);
      fileLine.push_back(val);
   }
   loadFile.close();
   return fileLine;
}

vector<string> openLoadFile(string fileName) {
   string val;
   std::vector<string> fileLine;
   fstream loadFile;
   stringstream loadVector;
   loadFile.open(fileName);
   while(!loadFile.eof()){
      getline(loadFile, val);
      fileLine.push_back(val);
   }
   loadFile.close();
   return fileLine;
}

Player loadOldPlayer( vector<Area> area, vector<Item> items){
   vector<string> savedLines;
   savedLines=parseLoadFile();
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
      if(area[i].getName() == location) {
         player.setLocation(&area[i]);
      }
   }
   player.setVars(gas, health);
   while(getline(parseString, inventory, ' ')){
      for(int i=0; i < items.size(); i++) {
         if(items[i].getName() == inventory) {
            player.addInventory(&items[i]);
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
void createNewPlanets(std::vector<Area*> planets, std::vector<Item> items){
      for(int j=0; j < items.size(); j++){
         cout << items[j].getName() << endl;
      }
}
std::vector<Item> loadItems(){
   vector<Item> returnItems;
   std::ifstream loadFile("loadfiles/items.txt");
   string itemName, itemTextFile, fullLine;
   int takeable, wearable;
   while(std::getline(loadFile, fullLine)) {
      std::istringstream parseLine(fullLine);
      parseLine >> itemName >> itemTextFile >> takeable >> wearable;
      returnItems.push_back(Item(itemName, itemTextFile, takeable));
      if(wearable == 1){
         returnItems.back().setWearable(wearable);
      }
   }
   loadFile.close();
      //Loads the special items (their own children Objects)
      std::ifstream loadSFile("loadfiles/specialItems.txt");
      while(std::getline(loadSFile, fullLine)) {
         std::istringstream parseLine(fullLine);
         parseLine >> itemName >> itemTextFile >> takeable >> wearable;
         if(itemName == "Doohickey") {
            returnItems.push_back(Doohickey(itemName, itemTextFile, takeable));
         }
         if(itemName == "Flashlight") {
            returnItems.push_back(Flashlight(itemName, itemTextFile, takeable));
         }
         if(itemName == "Mushroom") {
            returnItems.push_back(Mushroom(itemName, itemTextFile, takeable));
         }
         if(itemName == "PickAxe") {
            returnItems.push_back(Pickaxe(itemName, itemTextFile, takeable));
         }
         if(itemName == "PowerCrystal") {
            returnItems.push_back(PowerCrystal(itemName, itemTextFile, takeable));
         }
         if(itemName == "ScrewDriver") {
            returnItems.push_back(ScrewDriver(itemName, itemTextFile, takeable));
         }
         if(itemName == "Transmitter") {
            returnItems.push_back(Transmitter(itemName, itemTextFile, takeable));
         }
         if(itemName == "Spaceship") {
            returnItems.push_back(Spaceship(itemName, itemTextFile, takeable));
         }
         if(wearable == 1){
            returnItems.back().setWearable(wearable);
         }
      }
   return returnItems;

}
std::vector<Area> loadPlanets(std::vector<Item> items){
   vector<Area> returnPlanet;
   vector<string> savedLines=openLoadFile("loadfiles/areas.txt");
   string planetName, shortFile, longFile, interFile, inventory;
   bool dark, oxy, space, visited;
   for(int j=1; j < savedLines.size(); j++){
      string fileString = savedLines[j];
      std::istringstream parseString(fileString);
      parseString >> planetName >> shortFile >> longFile >> interFile >> dark >> oxy >> space >> visited;
      returnPlanet.push_back(Area(planetName, shortFile, longFile, interFile, dark, oxy, space));
      while(getline(parseString, inventory, ' ')) {
         for(int i=0; i < items.size(); i++) {
            if(items[i].getName() == inventory) {
               returnPlanet.back().addItem(&items[i]);
            }  
         }
      }
   }
   return returnPlanet;
}

std::vector<Exit> createExits(std::vector<Area> areas){
   vector<Exit> returnExit;
   vector<string> savedLines=openLoadFile("loadfiles/exit.txt");
   string planetName;
   double life, gas;
   for(int j=1; j < savedLines.size(); j++){
      string fileString = savedLines[j];
      std::istringstream parseString(fileString);
      parseString >> planetName >> life >> gas;
      for(int i=0; i < areas.size(); i++) {
         if(areas[i].getName() == planetName){
            returnExit.push_back(Exit(planetName, &areas[i], gas, life));
         }
      }
   }
   return returnExit;
}
void setPlanetExits(std::vector<Area> planets, std::vector<Exit> exits) {
   for(int i=0; i < planets.size(); i++) {
      for(int j=0; j < exits.size(); j++) {
         if(planets[i].getName() == "Space"){
            if(exits[j].getName() != "Space") {
               planets[i].addExit(&exits[j]);
            }
         }
         else{
            if(exits[j].getName() == "Space") {
               planets[i].addExit(&exits[j]);
               planets[i].setLaunchExit(&exits[j]);
            }
         }
      }
      // Set exits from space to planets.
   }
   vector<string> savedLines=openLoadFile("loadfiles/addExit.txt");
   string planetName, exitName;
   for(int j=1; j < savedLines.size(); j++){
      string fileString = savedLines[j];
      std::istringstream parseString(fileString);
      parseString >> planetName >> exitName;

      for(int i=0; i < planets.size(); i++) {
         if(planets[i].getName() == planetName){
            for(int k=0; k < exits.size(); k++) {
               if(exits[k].getName() == exitName) {
                  planets[i].addExit(&exits[j]);
               }
            }
         }
      }
   }
}
