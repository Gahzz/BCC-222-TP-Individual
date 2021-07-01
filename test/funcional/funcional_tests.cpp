#include <iostream>
#include "funcional_tests.h"
#include "funcionalTests_logistical.h"
#include "funcionalTests_exponential.h"
#include "funcionalTests_complex.h"

using namespace std;

void runFuncionalTests()
{
	//--------------------------------------
	cout <<"\n\nRun Complex Tests.";

	runComplexTests();

	cout <<"\nEnd Complex Tests.\n";

	//--------------------------------------

	//--------------------------------------
	cout <<"\nRun Exponential Tests.";

	runExponentialTests();

	cout <<"\nEnd Exponential Tests.\n";
	//--------------------------------------

	//--------------------------------------
	cout <<"\nRun Logistical Tests.";

	runLogisticalTests();

	cout <<"\nEnd Logistical Tests.\n";
	//--------------------------------------
}
