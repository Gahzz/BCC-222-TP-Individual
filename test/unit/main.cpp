#include <iostream>
#include "uni_tests.h"


using namespace std;

int main()
{
	cout << "Start of unit tests !\n";

	flowtest();
	systemtest();
	modeltest();

	cout << "End of unit tests";


	return 0;
}