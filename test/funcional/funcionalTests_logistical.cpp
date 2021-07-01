#include "funcionalTests_logistical.h"

void runLogisticalTests()
{
	//There are two systems p1 and p1
	//Remove 0.01*(p1)*(1-p1/70) from p1 and insert in p2
	//P1 has Initial value 100, and p2 starts at 10

	System *p1 = new SystemImpl("p", 100), *p2 = new SystemImpl("p2", 10);
	Flow* logistica =  new MyFlowLogistical("logistica", p1, p2);
	Model* m2 = new ModelImpl;
	m2->add(p1);
	m2->add(p2);
	m2->add(logistica);
	m2->execute(0, 100);

	assert(fabs(p1->getValue() - 88.2167) < 0.0001);
	assert(fabs(p2->getValue() - 21.7833) < 0.0001);
	
	delete m2;

}