#include "Exit.h"
#include "Area.h"
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

Exit::Exit(std::string nameIn, std::string ldIn, Area* toAreaIn) {
	name = nameIn;
	longDescription = ldIn;
	toArea = toAreaIn;
}

Area* Exit::getArea(){
	return toArea; 
}

std::string Exit::getName(){
	return name; 
} 

void Exit::printLongDescription(){
	std::cout << longDescription << "\n"; 
}
	
void Exit::printShortDescription(){
	std::cout << shortDescription << "\n"; 
} 
