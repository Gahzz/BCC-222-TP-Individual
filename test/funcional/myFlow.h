#ifndef MY_FLOW_H
#define MY_FLOW_H

#include <math.h>
#include <assert.h>
#include "../../src/lib/modelImpl.h"
#include "../../src/lib/systemImpl.h"
#include "../../src/lib/flowImpl.h"

class MyFlowLogistical : public FlowImpl
{

public:

	MyFlowLogistical(string name, System* origin, System* target) : FlowImpl(name, origin, target)
	{

	}

	~MyFlowLogistical()
	{

	}

	float execute()
	{
		return 0.01 * (targetSystem->getValue()) * (1 - (targetSystem->getValue()) / 70);
	}
};

class MyFlowComplex : public FlowImpl
{

public:

	 MyFlowComplex(string name, System* origin, System* target) : FlowImpl(name, origin, target)
	{

	}

	~MyFlowComplex()
	{

	}

	float execute()
	{
		return 0.01 * (sourceSystem->getValue());
	}
};

class MyFlowExponential : public FlowImpl
{

public:

	MyFlowExponential(string name, System* origin, System* target) : FlowImpl(name, origin, target)
	{

	}

	~MyFlowExponential()
	{

	}

	float execute()
	{
		return 0.01 * (sourceSystem->getValue());
	}
};



#endif //!MY_FLOW_H_H