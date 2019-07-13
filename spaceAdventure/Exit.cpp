#include "Exit.h"

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

