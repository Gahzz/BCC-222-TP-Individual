#include "unit_flow.h"

void unit_Flow_constructor()
{
    Flow* f1 = new MyFlowUnit;
    assert(f1->getName() == "");
    assert(f1->getSourceSystem() == NULL);
    assert(f1->getTargetSystem() == NULL);

    System *s1 = new SystemImpl("test1", 10);
    System *s2 = new SystemImpl("test2", 20);
    Flow* f2 = new MyFlowUnit("test", s1, s2);

    assert(f2->getName() == "test");
    assert(f2->getSourceSystem() == s1);
    assert(f2->getTargetSystem() == s2);
}

void unit_Flow_destructor(){}

void unit_Flow_setName()
{
    System *s1 = new SystemImpl("test1", 10);
    System *s2 = new SystemImpl("test2", 20);
    Flow* f1 = new MyFlowUnit("test", s1, s2);
    assert(f1->getName() == "test");
}

void unit_Flow_getName()
{
    Flow* f1= new MyFlowUnit;
    f1->setName("test");
    assert(f1->getName() == "test");
}

void unit_Flow_SetSourceSystem()
{   
    Flow* f1 = new MyFlowUnit;
    System *s1 = new SystemImpl;
    f1->setSourceSystem(s1);

    assert(f1->getSourceSystem() == s1);

}
void unit_Flow_SetTargetSystem()
{
    Flow* f1 = new MyFlowUnit;
    System *s1 = new SystemImpl;
    f1->setTargetSystem(s1);

    assert(f1->getTargetSystem() == s1);
}
void unit_Flow_GetSourceSystem()
{
    Flow* f1 = new MyFlowUnit;
    System *s1 = new SystemImpl;
    f1->setSourceSystem(s1);

    assert(f1->getSourceSystem() == s1);
}
void unit_Flow_GetTargetSystem()
{
    Flow* f1 = new MyFlowUnit;
    System *s1 = new SystemImpl;
    f1->setTargetSystem(s1);

    assert(f1->getTargetSystem() == s1);
}

void unit_Flow_Execute()
{
    Flow* f1 = new MyFlowUnit;   
    assert(f1->execute() == 2);
}

void run_unit_tests_Flow()
{
    unit_Flow_constructor();  
    unit_Flow_destructor();
    unit_Flow_setName();
    unit_Flow_getName();
    unit_Flow_SetSourceSystem();
    unit_Flow_SetTargetSystem();
    unit_Flow_GetSourceSystem();
    unit_Flow_GetTargetSystem();
    unit_Flow_Execute();
}