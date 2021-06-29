#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "flow.h"

class Model {

protected:
	string name;
	vector<Flow*> flows;
	vector<System*> systems;

public:
	Model();
	Model(string);
	Model(Model*);
	virtual ~Model();
	string getName();
	void setName(string);
	bool add(Flow*);
	bool add(System*);
	bool remove(Flow*);
	bool remove(System*);
	void execute(int, int);

private:
	Model& operator= (const Model&);
	bool operator== (const Model&);
};


#endif
