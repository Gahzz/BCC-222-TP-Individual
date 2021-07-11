#include "UnittestModel.h"



class Flows1 : public FlowsImpl{

public:
Flows1(string name, SystemsImpl *origin, SystemsImpl *destiny) : FlowsImpl(name, origin, destiny){}

	~Flows1(){}

	double equation(){
		return origin->getContent() * 0.05;
	}



void UnittestModel(){
	ModelImpl* m1 = new ModelImpl("Model");
	SystemsImpl* s1 = new SystemsImpl("System", 2);
	Flows1* f1 = new Flows1("Flow", NULL, s1);


	assert(m1->getName() == "Model 1");

	m1->setName("Model 2");

	assert(m1->getName() == "Model 2");

	m1->addFlows(f1);
	m1->increase();

	assert(s1->getContent() == 2);

	m1->removeFlows(f1);

	m1->increase();

	assert(s1->getContent() == 2);

	delete s1;
	delete f1;
	delete m1;
}
};