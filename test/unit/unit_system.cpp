#include "unit_system.h"

void unit_System_constructor()
{
    System* s1 = new SystemImpl;
    assert(s1->getValue() == 0);
    assert(s1->getName() == "");

    System* s2 = new SystemImpl("test",10);
    assert(s2->getValue() == 10);
    assert(s2->getName() == "test");
}

void unit_System_destructor(){}

void unit_System_getValue()
{
    SystemImpl s("test", 10);
    assert(s.getValue() == 10);
}

void unit_System_setValue()
{
    SystemImpl s("sistems", 0);
    s.setValue(100);
    assert(s.getValue() == 100);
}

void unit_System_getName()
{
    SystemImpl s("test", 10);
    assert(s.getName() == "test");
}

void unit_System_setName()
{
    SystemImpl s("sistem", 0);
    s.setName("test");
    assert(s.getName() == "test");
}

void unit_System_increaseQuantity()
{
    SystemImpl s("sistem", 0);
    s.increaseQuantity(1);
    assert(s.getValue() == 1);
}     
void unit_System_decreaseQuantity()
{
    SystemImpl s("sistem", 1);
    s.decreaseQuantity(1);
    assert(s.getValue() == 0);
}

void run_unit_tests_System()
{
        unit_System_constructor();
        unit_System_destructor();        
        unit_System_getValue();
        unit_System_setValue();
        unit_System_getName();
        unit_System_setName();
        unit_System_increaseQuantity();
        unit_System_decreaseQuantity();        
}





void unit_System_increaseQuantity();      
void unit_System_decreaseQuantity();