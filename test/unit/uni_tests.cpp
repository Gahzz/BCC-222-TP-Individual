#include "uni_tests.h"
#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>

#include "../../src/lib/model.h"
#include "../../src/lib/system.h"
#include "../../src/lib/flow.h"



class MyFlow1 : public Flow
{

public:

	MyFlow1(string name, System* origin, System* target) : Flow(name, origin, target)
	{

	}

	~MyFlow1()
	{

	}

	double execute()
	{
		return targetSystem->getValue() * 2;
	}
};

void flowtest()
{
	System* s1 = new System("system1", 3);
	MyFlow1* f1 = new MyFlow1("flow1",NULL, NULL);

	assert(f1->getName() == "flow1");
	assert(f1->getSourceSystem() == NULL);
	assert(f1->getTargetSystem() == NULL);

	f1->setTargetSystem(s1);

	assert(f1->getSourceSystem() == NULL);
	assert(f1->getTargetSystem() != NULL);
	assert(f1->execute() == 6);

	f1->setSourceSystem(s1);

	assert(f1->getSourceSystem() != NULL);
	assert(f1->getTargetSystem() != NULL);

	delete s1;
	delete f1;
}



void systemtest()
{
	System* s1 = new System("system1", 3.0);
	MyFlow1* f1 = new MyFlow1("flow1", NULL, NULL);

	assert(s1->getName() == "system1");
	assert(s1->getValue() == 3.0);

	f1->setTargetSystem(s1);

	s1->setName("system2");
	s1->setValue(9.5);

	s1->increaseQuantity(f1->execute());

	assert(s1->getValue() == 28.5);
	assert(s1->getName() == "system2");

	delete s1;
	delete f1;
	
}

void modeltest()
{
	Model* m1 = new Model("model1");
	System* s1 = new System("system1", 3.0);
	MyFlow1* f1 = new MyFlow1("flow1", NULL, s1);


	assert(m1->getName() == "model1");

	m1->setName("model2");

	assert(m1->getName() == "model2");

	m1->add(s1);
	m1->add(f1);
	m1->execute(0, 1);

	assert(s1->getValue() == 9.0);

	m1->remove(f1);

	m1->execute(0,1);

	assert(s1->getValue() == 9.0);


	delete s1;
	delete f1;
	delete m1;
}