#ifndef FLOW_H
#define FLOW_H


#include "System.h"

using namespace std;

/**interface declaration*/
class Flow {

public:
	
	/** Flow destructor */
	virtual ~Flow(){};
	/** Change Flow name */
    virtual void setName(string) = 0;
	/**Insert a Source system */
	virtual void setSourceSystem(System*) = 0;
	/**Insert a Target system */
	virtual void setTargetSystem(System*) = 0;
	/** Get Flow name */
	virtual string getName() = 0;
	/** Get Flow source */
	virtual System* getSourceSystem() = 0;
	/** Get Flow target */
	virtual System* getTargetSystem() = 0;
	/** Define the equation to the Flow */
	virtual float execute() = 0;

};

#endif
