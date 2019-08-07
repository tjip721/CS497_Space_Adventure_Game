#ifndef EXIT_H 
#define EXIT_H
#include <string>
#include <vector> 
#include <iostream> 
//#include "Area.h"

class Area; 
class Exit 
{
private: 
	std::string name; 
	std::string longDescription;
	std::string shortDescription; 
	Area* toArea; 
	double gasDistance;
	double lifeDistance; 
public:
	Exit(std::string name, std::string longDescription, Area* toArea); 
	Area* getArea(); 
	std::string getName(); 
	double getGasDistance(){return gasDistance;}
	double getLifeDistance(){return lifeDistance;}
	void printLongDescription(); 
	void printShortDescription(); 
}; 

#endif
