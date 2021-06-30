#include <iostream>
#include <string>
#include <assert.h>
#include <cmath>
#include "funcional_tests.h"

#include "../../src/lib/model.h"
#include "../../src/lib/system.h"
//#include "../../src/lib/flow.h"

using namespace std;

class MyFlow1 : public Flow
{

public:

	MyFlow1(string name, System* origin, System* target) : Flow(name, origin, target)
	{

	}

	~MyFlow1()
	{

	}

	float execute()
	{
		return 0.01 * (targetSystem->getValue()) * (1 - (targetSystem->getValue()) / 70);
	}
};

class MyFlow2 : public Flow
{

public:

	MyFlow2(string name, System* origin, System* target) : Flow(name, origin, target)
	{

	}

	~MyFlow2()
	{

	}

	float execute()
	{
		return 0.01 * (sourceSystem->getValue());
	}
};


void exponencialFuncionalTest()
{

	//Remove 0.01 from pop1 and insert into pop2
	//Pop1 has Initial value 100, and pop2 starts at 0
	//Run from 0 to 100

	System* pop1 = new System("pop1", 100), *pop2 = new System("pop2",0);
	Model* m1 = new Model;
	MyFlow2* exponencial = new MyFlow2("exponencial", pop1, pop2); ;

	m1->add(exponencial);
	m1->add(pop1);
	m1->add(pop2);

	m1->execute(0, 100);

	assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
	assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

	delete m1;
}

void logisticalFuncionalTest()
{
	//There are two systems p1 and p1
	//Remove 0.01*(p1)*(1-p1/70) from p1 and insert in p2
	//P1 has Initial value 100, and p2 starts at 10

	System *p1 = new System("p", 100), *p2 = new System("p2", 10);
	MyFlow1* logistica =  new MyFlow1("logistica", p1, p2);
	Model* m2 = new Model;
	m2->add(p1);
	m2->add(p2);
	m2->add(logistica);
	m2->execute(0, 100);

	assert(fabs(p1->getValue() - 88.2167) < 0.0001);
	assert(fabs(p2->getValue() - 21.7833) < 0.0001);
	
	delete m2;
}

void complexFuncionalTest()
{
	// System q1 initialized at 100 , q2, q3, q4, q5, at 0
	//Equation of all flow is 0.01*(Source System)
	//There are flows:
	//q1 to q2, q1 to q3, q4 to q1, q3 to q4, q2 to q3, q2 to q5
	// Executed 101 times

	System *q1 = new System("Q1", 100), *q2 =  new System("Q2", 0), *q3 = new System("Q3", 100), 
		*q4 = new System("Q4", 0), *q5 = new System("Q5", 0);

	MyFlow2 *f = new MyFlow2("f", q1, q2), *g = new MyFlow2("g", q1, q3),
		*v = new MyFlow2("v", q4, q1), *u = new MyFlow2("u", q3, q4),
		*t = new MyFlow2("t", q2, q3), *r = new MyFlow2("r", q2, q5);

	Model* m3 = new Model;
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