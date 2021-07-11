#include "UnittestFlow.h"



class Flows1 : public FlowsImpl{

public:
Flows1(string name, SystemsImpl *origin, SystemsImpl *destiny) : FlowsImpl(name, origin, destiny){}

	~Flows1(){}

	double equation(){
		return origin->getContent() * 0.05;
	}
};


void UnittestFlow(){
	SystemsImpl* s1 = new SystemsImpl("System",2);
	Flows1* f1 = new Flows1("Flow",NULL,NULL);


	assert(f1->getName() == "Flow 1");
	assert(f1->getOrigin() == NULL);
	assert(f1->getDestiny() == NULL);

	f1->setDestiny(s1);

	assert(f1->getOrigin() == NULL);
	assert(f1->getDestiny() != NULL);
	assert(f1->equation() == 2);

	f1->setOrigin(s1);

	assert(f1->getOrigin() != NULL);
	assert(f1->getDestiny() != NULL);

	delete s1;
	delete f1;
}
