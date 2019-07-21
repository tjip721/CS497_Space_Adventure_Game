#ifndef DATA_H
#define DATA_H

#include <string>
#include <fstream>



//std::string save_data = "save_log.txt";

//open description file to save to an object variable
std::string get_file_data(std::string text);

//UI functions --to be pretty
void display_planet();
void display_descriptions();
//i.e. game over, start menue
void display_gameInstances();

//save log file conditions, will be called in the "main" game
void save_log();
//Parse the save_log.txt and place in constructor for the areas + user
void open_log();


#endif // DATA_H
