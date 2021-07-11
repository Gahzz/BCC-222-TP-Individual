#ifndef MODEL_H
#define MODEL_H

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

#include "Flows.h"



class Model{


public:
/** Model destructor */
	virtual ~Model(){};
/** Gets the name */
	string getName();
/** Change the name as a string type */
 	virtual void setName(string) = 0;
/** Add a System */
  	virtual bool addSystems(Systems*) = 0;
/** Remove a System */
	virtual bool removeSystems(Systems*) = 0;
/** Add a Flow */
 	virtual bool addFlows(Flows*) = 0;
/** Remove a Flow */
  	virtual bool removeFlows(Flows*) = 0;
/** Increase the value */
	virtual void increase() = 0;

};

#endif
