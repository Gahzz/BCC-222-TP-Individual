#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "utility_unit.h"

void unit_Model_constructor();
void unit_Model_destructor();
void unit_Model_addFlow();
void unit_Model_addSystem();
void unit_Model_removeFlow();
void unit_Model_removeSystem();
void unit_Model_getName();
void unit_Model_setName();
void run_unit_tests_Model();

#endif //!UNIT_MODEL_H