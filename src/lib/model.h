#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "flow.h"

class Model {

protected:
	/** Model name */
	string name;
	/*!< Model flows */ 
	vector<Flow*> flows;
	/*!< Model's systems */
	vector<System*> systems;

public:
	/** Model default constructor */
	Model();
	/** Model constructor */
	Model(string);
	/** Model destructor */
	virtual ~Model();
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
	Model(Model*);
	/** operator = overload */
	Model& operator= (const Model&);
	/** operator == overload */
	bool operator== (const Model&);
};


#endif
