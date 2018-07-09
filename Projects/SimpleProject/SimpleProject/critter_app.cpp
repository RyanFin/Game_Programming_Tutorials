// critter_app.cpp 
// application file
#include <iostream>
#include "critter.h"

using namespace std;

int main() {

	cout << "Instantiating a Critter object.\n";

	Critter crit;

	crit.Greet();

	system("pause");

	return 0;
}