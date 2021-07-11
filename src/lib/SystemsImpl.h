#ifndef SYSTEMSIMPL_H
#define SYSTEMSIMPL_H

#include <iostream>
#include <string>
#include "Systems.h"
using namespace std;

class SystemsImpl : public Systems{
	

private:
  /** Declare the name as string type */
  string name;
  /** Declare the content as double type */
  double content;


public:
  	/** Flow builder */
	SystemsImpl();
  	/** Declare Systems with 2 parameters as string and double types */
	SystemsImpl(string, double);
  	/** Declare Systems that points to systems on the class Systems  */
	SystemsImpl(SystemsImpl* systems);
  	/** Get the name */
  string getName(void);
    	/** Get the content */
  double getContent();
	/** Change the name as a string type */
  void setName(string);
  	/** Change the content as a double type */
  void setContent(double);
	/** Increases the value as a double type */
  void increase(double);
  		/** Decreases the value as a double type */
  void decrease(double);
};

#endif
