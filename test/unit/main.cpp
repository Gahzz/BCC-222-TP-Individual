#include <iostream>
#include "UnittestSystem.h"
#include "UnittestFlow.h"
#include "UnittestModel.h"

using namespace std;


int main(){

  cout << "\nBegin of the Unit Tests";

  UnittestFlow();
	UnittestSystem();
	UnittestModel();


  return 0;
}
