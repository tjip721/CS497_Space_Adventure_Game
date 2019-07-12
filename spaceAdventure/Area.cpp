#include "Area.h"
#include <iostream>
/*
private: 
	string longDescription;
	string shortDescription; 
	vector<Exit*> exits; 
	vector<Item*> items;  
	vector<Action> availableActions;  
	bool firstEntry; 
*/	

void Area::printDescription(){
	if(firstEntry){
		std::cout << longDescription << "\n"; 
		firstEntry = false; 
	} else {
		std::cout << shortDescription << "\n"; 
	}
}

void Area::takeItem(Item* thing){
	for(int ii=0; ii < items.size(); ii++){
		if(items[ii] == thing){
			items.erase(items.begin()+ii); 
		}
	}
}

void Area::dropItem(Item* thing){
	items.push_back(thing); 
} 
	

