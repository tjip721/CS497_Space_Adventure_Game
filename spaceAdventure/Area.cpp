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

void Area::look(){
	std::cout << longDescription << "\n"; 
} 

Item* Area::takeItem(std::string target){
	Item* itemPtr; 
	for(int ii=0; ii < items.size(); ii++){
		if(items[ii]->getName().compare(target)&&items[ii]->isTakeable() ){
			itemPtr = items[ii]; 
			items.erase(items.begin()+ii); 
			return itemPtr; 
		}
	}
	return NULL; 
}

void Area::dropItem(Item* thing){
	items.push_back(thing); 
} 
	

bool Area::hasExit(std::string target){
	int exitValid = false;  
	for(int ii=0; ii < exits.size(); ii++){
		if(exits[ii]->getName().compare(target)==0){
			exitValid = true; 
			break;
		} 
	}
	return exitValid; 
}


Area* Area::getExit(std::string targetName){
	for(int ii=0; ii < exits.size(); ii++){
		if(exits[ii]->getName().compare(targetName)==0){
			return exits[ii]->getArea(); 
		} 
	}
	return NULL; 
}

bool Area::lookAt(std::string targetName){
	for(int ii=0; ii < items.size(); ii++){
		if(items[ii]->getName().compare(targetName)){
			items[ii]->lookAt(); 
			return true; 
		}
	}
	return false; 
}  










