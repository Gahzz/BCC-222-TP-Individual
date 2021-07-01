#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

using namespace std;

class SystemImpl : public System{

private:
	/** System name*/ 
	string name;
	/**Current value in the system*/ 
	float value;
	

public:
	/** System default constructor */
	SystemImpl();
	/** System constructor */
	SystemImpl(string, float);
	/** System destructor */
	virtual ~SystemImpl();
	/** Change System value*/
	void setValue(float);
	/** Change System name*/
	void setName(string);
	/** Get System value */
	double getValue();
	/** Get System name */
	string getName();
	/** Increase System quantity. */
	void increaseQuantity(float);
	/**Decreases system quantity*/
	void decreaseQuantity(float);

private:
	/** System constructor of copy */
	SystemImpl(SystemImpl* system);
	/** Operator = overload */
	SystemImpl& operator= (const SystemImpl&);
	/**  Operator == overload */
	bool operator== (const SystemImpl&);

};




#endif
