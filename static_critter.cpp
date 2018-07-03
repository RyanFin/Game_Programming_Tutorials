// Static Critter Program

#include <iostream>

using namespace std;

class Critter{
	public:
		static int s_Total; // static data member
		
		Critter(int hunger = 0){
			m_Hunger = hunger;
			cout << "A critter has been born!" << endl;
			++s_Total;
		}
		
		static int getTotal(){
			return s_Total;
		}
		
	private:
		int m_Hunger;
		
};

int Critter::s_Total = 0; // initialise static data member

int main(){
	
	cout << "Total number of critters is: ";
	cout << Critter::s_Total << endl;
	
	Critter crit1, crit2, crit3;
	cout << "Total number of critters is: ";
	cout << Critter::getTotal() << endl;
	
	
	return 0;
}

