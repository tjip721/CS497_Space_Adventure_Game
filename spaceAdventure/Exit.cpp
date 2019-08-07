#include "Exit.h"
#include "Area.h"
#include <fstream>
/*class Area; 
class Exit 
{
private: 
	std::string name; 
	std::string longDescription;
	std::string shortDescription; 
	Area* toArea; 
}; 
*/

Exit::Exit(std::string nameIn, std::string ldIn, std::string sdIn, Area* toAreaIn, double gasDist, double lifeDist) {
	name = nameIn;
	longDescription = loadFile(ldIn);
	shortDescription = loadFile(sdIn);
	toArea = toAreaIn;
	gasDistance = gasDist;
	lifeDistance = lifeDist;
}

std::string Exit::loadFile(std::string fileName) {
	fileName = "./descriptorFiles/" + fileName;
	std::ifstream file(fileName.c_str());
	std::string str;
	getline(file, str);
	file.close();
	return str;
}

Area* Exit::getArea(){
	return toArea; 
}

std::string Exit::getName(){
	return name; 
} 

void Exit::printLongDescription(){
	// temporarily switched to name for testing.
	//std::cout << longDescription << "\n";
	std::cout << name;
}
	
void Exit::printShortDescription(){
	// temporarily switched to name for testing.
	//std::cout << shortDescription << "\n"; 
	std::cout << name;
} 
