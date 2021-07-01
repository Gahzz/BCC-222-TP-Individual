#include "unit_system.h"
#include "unit_flow.h"
#include "unit_model.h"

int main() {

   	cout << "Start of unit tests !\n";
	
	run_unit_tests_System();
	run_unit_tests_Flow();
	run_unit_tests_Model();

	cout << "End of unit tests\n";

	return 0;
}