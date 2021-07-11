#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <iostream>
#include <string>

using namespace std;

class Systems{

public:
  	/** System destructor */
	virtual ~Systems(){};
  	/** Get the name */
  virtual string getName() = 0;
    	/** Get the content */
  virtual double getContent() = 0;
	/** Change the name as a string type */
  virtual void setName(string) = 0;
  	/** Change the content as a double type */
  virtual void setContent(double) = 0;
	/** Increases the value as a double type */
  virtual void increase(double) = 0;
  		/** Decreases the value as a double type */
  virtual void decrease(double) = 0;
};

#endif
