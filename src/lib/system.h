#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

/**interface declaration*/
class System {

public:
	
	/** System's destructor */
	virtual ~System(){};
	/** Change System value*/
	virtual void setValue(float) = 0;
	/** Change System name*/
	virtual void setName(string) = 0;
	/** Get System value */
	virtual double getValue() = 0;
	/** Get System name */
	virtual string getName() = 0;
	/** Increase System quantity. */
	virtual void increaseQuantity(float) = 0;
	/**Decreases system quantity*/
	virtual void decreaseQuantity(float) = 0;
};




#endif
