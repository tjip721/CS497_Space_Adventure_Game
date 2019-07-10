#ifndef ITEM_H 
#define ITEM_H
#include <string>
#include <vector> 
#include <iostream>

class Item 
{
private: 
	std::string name; 
	std::string description; 
	bool breakable; 
	bool takeable; 
	
public: 
	void lookAt(){
		std::cout << description << "\n"; 
	}
}; 

#endif
