// Private Critter

#include <iostream>

using namespace std;

class Critter{
	public:
		Critter(int hunger = 0);
		int getHunger() const;
		void setHunger(int hunger);
		
	private:
		int m_Hunger;
};

Critter::Critter(int hunger): m_Hunger(hunger){
	cout << "A new critter has been born!" << endl;
}

int Critter::getHunger() const{
	return m_Hunger;
}

void Critter::setHunger(int hunger){
	if(hunger < 0){
		cout << "You can't set a critter's hunger to less than 0.\n";
	} else{
		m_Hunger = hunger;
	}
}

int main(){
	
	Critter crit(5);
	cout << "Calling getHunger(): " << crit.getHunger() << endl;
	
	cout << "Calling setHunger() with -1: \n";
	crit.setHunger(-1);
	
	cout << "Calling setHunger() with 9: \n";
	crit.setHunger(9);
	
	cout << "Calling getHunger(): " << crit.getHunger() << endl;
	
	return 0;
}
