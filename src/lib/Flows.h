#ifndef FLOWS_H
#define FLOWS_H

#include <iostream>
#include <string>

#include "Systems.h"

using namespace std;

class Flows {

public:

	/** Flow destructor */
	virtual ~Flows(){};
	/** Change the name as a string type */
 	virtual	void setName(string) = 0;
	/** Change the origin as a Systems type */
	virtual Systems* setOrigin() = 0;
		/** Change the destiny as a Systems type */
	virtual Systems* setDestiny() = 0;
	/** Gets the name */
	virtual	string getName() = 0;
	/** Gets the origin */
	virtual Systems* getOrigin() = 0;
	/** Gets the destiny */
	virtual Systems* getDestiny() = 0;
	/** Connection with 2 parameters as a Systems type */
	void connect(Systems *, Systems *);
	/** Begin the value of the equation as 0 and with double type*/
	virtual double equation() = 0;

};

#endif
