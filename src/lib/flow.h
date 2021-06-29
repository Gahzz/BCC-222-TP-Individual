#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>

#include "System.h"

using namespace std;

class Flow {

protected:
	string name;
	System* sourceSystem;
	System* targetSystem;

public:
	Flow();
	Flow(string, System*, System*);
	virtual ~Flow();
	void setName(string);
	void setSourceSystem(System*);
	void setTargetSystem(System*);
	string getName();
	System* getSourceSystem();
	System* getTargetSystem();
	virtual double execute() = 0;

private:
	Flow& operator= (const Flow&);
	bool operator== (const Flow&);


};

#endif
