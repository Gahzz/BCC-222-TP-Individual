#include "unit_model.h"

void unit_Model_constructor()
{
    Model* m1 = new ModelImpl;
    assert(m1->getName() == "");

    Model *m2 = new ModelImpl("test");
    assert(m2->getName() == "test");
}

void unit_Model_destructor(){}

void unit_Model_addFlow()
{
    ModelImpl m1;
    Flow *f1 = new MyFlowUnit;
    assert(m1.add(f1) == true);
}

void unit_Model_addSystem()
{
    ModelImpl m1;
    SystemImpl *s1 = new SystemImpl();
    assert(m1.add(s1) == true);
}

void unit_Model_removeFlow()
{
    ModelImpl m1;
    SystemImpl *s1 = new SystemImpl("test1", 10);
    SystemImpl *s2 = new SystemImpl("test2", 20);
    Flow *f1 = new MyFlowUnit("teste", s1, s2);
    m1.add(f1);
    assert(m1.remove(f1) == true);
}

void unit_Model_removeSystem()
{
    ModelImpl m1;
    SystemImpl *s1 = new SystemImpl("test1", 10);
    m1.add(s1);
    assert(m1.remove(s1) == true);
}

void unit_Model_getName()
{
    ModelImpl m("test");
    assert(m.getName() == "test");
}
void unit_Model_setName()
{
    ModelImpl m("model");
    m.setName("test");
    assert(m.getName() == "test");
}
void run_unit_tests_Model()
{
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_addFlow();
    unit_Model_addSystem();
    unit_Model_removeFlow();
    unit_Model_removeSystem();
    unit_Model_getName();
    unit_Model_setName();

}