#include <iostream>
#include <assert.h>
#include <string>


#include "testsFunc.h"

using namespace std;

#include "../../src/lib/Systems.h"
#include "../../src/lib/Flows.h"
#include "../../src/lib/Model.h"



class Flows1 : public Flows{
public:
	Flows1(string name, Systems* origin, Systems* destiny) : Flows(name, origin, destiny){}

  ~Flows1(){}

	double equation(){
		return 0.05 * (destiny->getContent()) * (1 - (destiny->getContent()) / 50);
	}
};

class Flows2 : public Flows
{

public:

	Flows2(string name, Systems* origin, Systems* destiny) : Flows(name, origin, destiny){}

	~Flows2(){}

	double equation(){
		return 0.05 * (origin->getContent());
	}
};


void testExpFunc()
{

	//Remove 5% from p1 and insert into p2
	//p1 begins with 50, and p2 starts with 0
	//The test runs from 0 to 50

	Systems* p1 = new Systems("p1", 50), *p2 = new Systems("p2",0);
	Model* m1 = new Model("ModelExp",0,50);
	Flows2* exp = new Flows2("exp", p1, p2); ;

	m1->addFlows(exp);

	m1->increase();

	assert(p1->getContent() < 25 && p1->getContent() > 0);
	assert(p2->getContent() < 50 && p2->getContent() > 26);

	delete m1;
}

void testLogisticFunc()
{
	//We have the systems v1 and v2
	//It removes 0.05 * (v1) * (1 - v1/50) from v1 and insert in v2
	//V1 has Initial value 50, and v2 starts at 10

	Systems *v1 = new Systems("v", 50), *v2 = new Systems("v2", 10);
	Flows* logic =  new Flows1("logic", v1, v2);
	Model* m2 = new Model("Logic",0,50);
	m2->addFlows(logic);
	m2->increase();

	assert(v1->getContent() < 70 && v1->getContent() > 55);
	assert(v2->getContent() < 30 && v2->getContent() > 15);

	delete m2;
}

void testComplexFunc()
{
	// The System s1 initialized at 50 , s2, s3 at 0
	//Equation of all flow is 0.05 * (Source System)
	//There are flows:
	//s1 to s3, s2 to s3, s3 to s1, s3 to s2


	Systems *s1 = new Systems("S1", 50), *q2 =  new Systems("S2", 0), *s3 = new Systems("S3", 100),

	Flows2 *f = new Flows2("f", s1, s3),
				 *g = new Flows2("g", s3, s1),
				 *v = new Flows2("v", s2, s3),
				 *u = new Flows("u", s3, s2);


	Model* m3 = new Model;
	m3->addFlows(f);
	m3->addFlows(g);
	m3->addflows(v);
	m3->addflows(u);
	m3->increase();

	assert(s1->getContent() < 38 && s1->getContent() > 30);
	assert(s2->getContent() < 40 && s2->getContent() > 15);
	assert(s3->getContent() < 10 && s3->getContent() > 5);

	delete m3;
}
