#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

class System {

private:
	string name;
	double value;
	

public:
	System();
	System(string, double);
	System(System* system);
	virtual ~System();
	void setValue(double);
	void setName(string);
	double getValue();
	string getName();
	void increaseQuantity(double);
	void decreaseQuantity(double);

private:
	System& operator= (const System&);
	bool operator== (const System&);

};




#endif
