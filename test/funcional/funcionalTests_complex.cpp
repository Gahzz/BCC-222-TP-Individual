#include "funcionalTests_complex.h"

void runComplexTests()
{
	// System q1 initialized at 100 , q2, q3, q4, q5, at 0
	//Equation of all flow is 0.01*(Source System)
	//There are flows:
	//q1 to q2, q1 to q3, q4 to q1, q3 to q4, q2 to q3, q2 to q5
	// Executed 101 times

	System *q1 = new SystemImpl("Q1", 100), *q2 =  new SystemImpl("Q2", 0), *q3 = new SystemImpl("Q3", 100), 
		*q4 = new SystemImpl("Q4", 0), *q5 = new SystemImpl("Q5", 0);

	Flow *f = new MyFlowComplex("f", q1, q2), *g = new MyFlowComplex("g", q1, q3),
		*v = new MyFlowComplex("v", q4, q1), *u = new MyFlowComplex("u", q3, q4),
		*t = new MyFlowComplex("t", q2, q3), *r = new MyFlowComplex("r", q2, q5);

	Model* m3 = new ModelImpl;
	m3->add(q1);
	m3->add(q2);
	m3->add(q3);
	m3->add(q4);
	m3->add(q5);
	m3->add(f);
	m3->add(g);
	m3->add(v);
	m3->add(u);
	m3->add(t);
	m3->add(r);
	m3->execute(0, 100);

	assert(fabs(q1->getValue() - 31.8513) < 0.0001);
	assert(fabs(q2->getValue() - 18.4003) < 0.0001);
	assert(fabs(q3->getValue() - 77.1143) < 0.0001);
	assert(fabs(q4->getValue() - 56.1728) < 0.0001);
	assert(fabs(q5->getValue() - 16.4612) < 0.0001);

	delete m3;

}