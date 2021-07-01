#include "funcionalTests_exponential.h"

void runExponentialTests()
{
	//Remove 0.01 from pop1 and insert into pop2
	//Pop1 has Initial value 100, and pop2 starts at 0
	//Run from 0 to 100

	System* pop1 = new SystemImpl("pop1", 100), *pop2 = new SystemImpl("pop2",0);
	Model* m1 = new ModelImpl;
	Flow* exponencial = new MyFlowExponential("exponencial", pop1, pop2); ;

	m1->add(exponencial);
	m1->add(pop1);
	m1->add(pop2);

	m1->execute(0, 100);

	assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
	assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

	delete m1;

}