#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

#include "Flows.h"
#include "FlowsImpl.h"
#include "SystemsImpl.h"
#include "Model.h"

class ModelImpl : public Model{


public:
/** Model builder */
	ModelImpl();
/** Model destructor */
	~ModelImpl();
/** Model as string type */
	ModelImpl(string);
/** Model getting the pointer */
	ModelImpl(ModelImpl*);
/** Gets the name */
	string getName();
/** Change the name as a string type */
	void setName(string);
/** Add a System */
  bool addSystems(Systems*);
/** Remove a System */
	bool removeSystems(Systems*);
/** Add a Flow */
  bool addFlows(Flows*);
/** Remove a Flow */
  bool removeFlows(Flows*);
/** Increase the value */
	void increase();

private:
	/** Gets the adress of the Model as a const and put on the operator */
	ModelImpl& operator= (const ModelImpl&);
	bool operator== (const ModelImpl&);


protected:
	/** Declares the name as string type */
	string name;
	/** Declares the system as a vector */
	vector<Systems*> systems;
	/** Declares the flow as a vector */
	vector<Flows*> flows;
};

#endif
