#ifndef EXIT_H 
#define EXIT_H
#include <string>
#include <vector> 
//#include "Area.h"

class Area; 
class Exit 
{
private: 
	std::string name; 
	std::string longDescription;
	std::string shortDescription; 
	Area* toArea; 
public:
	Area* getArea(); 
	std::string getName(); 
}; 

#endif
