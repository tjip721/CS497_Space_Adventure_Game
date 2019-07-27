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

Area* Exit::getArea(){
	return toArea; 
}
std::string Exit::getName(){
	return name; 
} 

Exit::Exit(std::string nameIn, std::string ldIn, Area* toAreaIn){
	name = nameIn; 
	longDescription = ldIn;
	toArea = toAreaIn;
}
