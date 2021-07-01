#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"
#include "flowImpl.h"
#include "systemImpl.h"

class ModelImpl : public Model {

protected:
	/** Model name */
	string name;
	/*!< Model flows */ 
	vector<Flow*> flows;
	/*!< Model's systems */
	vector<System*> systems;

public:
	/** Model default constructor */
	ModelImpl();
	/** Model constructor */
	ModelImpl(string);
	/** Model destructor */
	virtual ~ModelImpl();
	/** Get Model Name */
	string getName();
	/** Change Model name */
	void setName(string);
	/** Add a Flow to the model */
	bool add(Flow*);
	/** Add a System to the model */
	bool add(System*);
	/**Remove a Flow from the model */
	bool remove(Flow*);
	/**Remove a System from the model */
	bool remove(System*);
	/**Run the simulation */
	void execute(int, int);

private:
	/** Model's constructor of copy*/
	ModelImpl(ModelImpl*);
	/** operator = overload */
	ModelImpl& operator= (const ModelImpl&);
	/** operator == overload */
	bool operator== (const ModelImpl&);
};


#endif
