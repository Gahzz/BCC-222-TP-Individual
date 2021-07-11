#include "UnittestSystem.h"


class Flows1 : public FlowsImpl{

public:
Flows1(string name, SystemsImpl *origin, SystemsImpl *destiny) : FlowsImpl(name, origin, destiny){}

	~Flows1(){}

	double equation(){
		return origin->getContent() * 0.05;
	}
};

void UnittestSystem()
{
	SystemsImpl* s1 = new SystemsImpl("System", 2);
	Flows1* f1 = new Flows1("Flow", NULL, NULL);

	assert(s1->getName() == "System 1");
	assert(s1->getContent() == 2);

	f1->setDestiny(s1);

	s1->setName("System 2");
	s1->setContent(2);

	s1->increase(f1->equation());

	assert(s1->getContent() == 20);
	assert(s1->getName() == "System 2");

	delete s1;
	delete f1;

}
