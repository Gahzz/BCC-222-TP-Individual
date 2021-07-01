#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "flow.h"

using namespace std;


class FlowImpl : public Flow{

protected:
	/** Flow's Name */
	string name;
	/** The System of origin, that is, which will give the quantity */
	System* sourceSystem;
	/** The System that will receive a value, ie, the target System */
	System* targetSystem;

public:
	/** Default Flow constructor */
	FlowImpl();
	/** Flow constructor */
	FlowImpl(string, System*, System*);
	/** Flow destructor */
	virtual ~FlowImpl();
	/** Change Flow name */
	void setName(string);
	/**Insert a Source system */
	void setSourceSystem(System*);
	/**Insert a Target system */
	void setTargetSystem(System*);
	/** Get Flow name */
	string getName();
	/** Get Flow source */
	System* getSourceSystem();
	/** Get Flow target */
	System* getTargetSystem();
	/** Define the equation to the Flow */
	virtual float execute() = 0;
	
private:
	/** operator == overload */
	bool operator== (const FlowImpl&);
	/** operator = overload */
	FlowImpl& operator= (const FlowImpl&);
	/** Copy Flow constructor */
	FlowImpl(FlowImpl*);
	
};

#endif
