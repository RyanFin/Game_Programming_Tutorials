// Simple Critter Program

#include <iostream>

using namespace std;

class Critter{			// Class definition
	public:
		int m_hunger;	// data member
		void greet(); 	// data function prototype
};

void Critter::greet(){	// member function definition
	cout << "Hi. I'm a critter. My hunger level is: " << m_hunger << endl;
}


int main(){
	
	Critter crit1, crit2;
	
	crit1.m_hunger = 9;
	cout << "Crit1's hunger level is: " << crit1.m_hunger << endl;
	
	crit2.m_hunger = 3;
	cout << "Crit2's hunger level is: " << crit2.m_hunger << endl;
	
	crit1.greet();
	crit2.greet();
	
		
	return 0;
}
