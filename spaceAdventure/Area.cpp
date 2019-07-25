#include "Area.h"
#include <iostream>
/*
private: 
	string areaName;
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
		if(items.size() > 0){
			std::cout << "There are some items here: "; 
			for(int ii=0; ii < items.size(); ii++){
				std::cout << items[ii]->getName() << "\n"; 
			}
		}
		//Add logic to print description of items here
	} else {
		std::cout << shortDescription << "\n"; 
	}
}

void Area::look(){
	firstEntry = true; 
	printDescription();
} 

Item* Area::getItem(std::string targetName){
	Item* itemPtr; 
	for(int ii=0; ii < items.size(); ii++){
		if(items[ii]->getName().compare(targetName)==0){
			itemPtr = items[ii];
			return itemPtr; 
		}
	}
	return NULL; 
}

Item* Area::takeItem(std::string target){
	Item* itemPtr; 
	for(int ii=0; ii < items.size(); ii++){
		if(items[ii]->getName().compare(target)==0 && items[ii]->isTakeable() ){
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


Exit* Area::getExit(std::string targetName){
	for(int ii=0; ii < exits.size(); ii++){
		if(exits[ii]->getName().compare(targetName)==0){
			return exits[ii]; 
		} 
	}
	return NULL; 
}

bool Area::lookAt(std::string targetName){
	for(int ii=0; ii < items.size(); ii++){
		if(items[ii]->getName().compare(targetName)==0){
			items[ii]->lookAt(); 
			return true; 
		}
	}
	return false; 
}  

bool Area::hasItem(std::string targetName){
for(int ii=0; ii < items.size(); ii++){
		if(items[ii]->getName().compare(targetName)==0){
			return true; 
		}
	}
	return false; 

}

void Area::addExit(Exit* exit){
	exits.push_back(exit); 
}
void Area::addItem(Item* item){ 
	items.push_back(item); 
}


void Area::setLongDescription(std::string fileName){
	//from data.h
	longDescription = fileName; 
}
void Area::setShortDescription(std::string fileName){
	//from data.h
	shortDescription= fileName; 
}

	
std::vector<Item*> Area::getItems(){
        return items;
}
bool Area::getAreaEntry() {
        return firstEntry;
}

std::string Area::getName(){
	return areaName;
}






