#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

class System {

private:
	/** System name*/ 
	string name;
	/**Current value in the system*/ 
	float value;
	

public:
	/** System default constructor */
	System();
	/** System constructor */
	System(string, float);
	/** System's destructor */
	virtual ~System();
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
	System(System* system);
	/** Operator = overload */
	System& operator= (const System&);
	/**  Operator == overload */
	bool operator== (const System&);

};




#endif
