// Constructor Critter Program

#include <iostream>

using namespace std;

// Create Class
class Critter{
	public:
		int m_Hunger;
		
		Critter(int hunger = 0); // constructor prototype with default value
		void Greet();
};

Critter::Critter(int hunger){	// constructor definition
	cout << "A new critter has been born!" << endl;
	m_Hunger = hunger;
}

void Critter::Greet(){
	cout << "Hi! I am a critter, my hunger level is: " << m_Hunger <<".\n\n";  
}


int main(){
	
	// Create critter object using the constructor
	Critter crit1(7);
	// Call the Greet() member function / operation
	crit1.Greet();
	
	return 0;
}
