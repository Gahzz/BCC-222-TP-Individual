#ifndef UTILITY_UNIT_H
#define UTILITY_UNIT_H

#include <assert.h>
#include <string>
#include <iostream>

#include "../../src/lib/modelImpl.h"
#include "../../src/lib/flowImpl.h"
#include "../../src/lib/systemImpl.h"

using namespace std;

class MyFlowUnit : public FlowImpl
{

public:
    
    MyFlowUnit() {}
    
	MyFlowUnit(string name, System* origin, System* target) : FlowImpl(name, origin, target)
	{

	}

	~MyFlowUnit()
	{

	}

	float execute()
	{
		return 2;
	}
};






#endif //!UTILITY_UNIT_H