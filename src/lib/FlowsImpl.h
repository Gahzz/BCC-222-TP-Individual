#ifndef FLOWSIMPL_H
#define FLOWSIMPL_H

#include <iostream>
#include <string>
#include "Flows.h"
#include "Systems.h"

using namespace std;

class FlowsImpl : public Flows{

protected:
		/** Declare the name as string type */
	string name;
		/** Declare the origin as Systems type */
	Systems* origin;
	/** Declare the destiny as Systems type */
	Systems* destiny;

public:
	/** Flow builder */
	FlowsImpl();
	/** Flow with 3 parameters, as string, and two systems type */
	FlowsImpl(string, Systems*, Systems*);
	/** Flow destructor */
	virtual ~FlowsImpl();
	/** Change the name as a string type */
	void setName(string);
	/** Change the origin as a Systems type */
	void setOrigin(Systems*);
		/** Change the destiny as a Systems type */
	void setDestiny(Systems*);
	/** Gets the name */
	string getName();
	/** Gets the origin */
	Systems* getOrigin();
	/** Gets the destiny */
	Systems* getDestiny();
	/** Connection with 2 parameters as a Systems type */
	void connect(Systems *, Systems *);
	/** Begin the value of the equation as 0 and with double type*/
	virtual double equation() = 0;

private:
	/** Gets the adress of the Flows as a const and put on the operator */
	FlowsImpl& operator= (const FlowsImpl&);
	bool operator== (const FlowsImpl&);

};

#endif
