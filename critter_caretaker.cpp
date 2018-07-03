// Critter Caretaker

#include <iostream>

using namespace std;

class Critter{
	public:
		Critter(int hunger = 0, int boredom = 0);
		void talk();
		void eat(int food = 0);
		void play(int fun = 0);
	
	private:
		int m_Hunger, m_Boredom;
		
		int getMood() const;
		void passTime(int time = 1);
	
};

// Constructor
Critter::Critter(int hunger, int boredom){
	m_Hunger = hunger;
	m_Boredom = boredom;
}

inline int Critter::getMood() const{
	return (m_Hunger + m_Boredom);
}

void Critter::passTime(int time){
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::talk(){
	cout << "I'm a critter and I feel ";
	int mood = getMood();
	if(mood > 15){
		cout << "Mad.\n";
	} else if(mood > 10){
		cout << "Frustrated.\n";
	} else if(mood > 5){
		cout << "Okay.\n";
	} else{
		cout << "Happy.\n";
		passTime();
	}
}

void Critter::eat(int food){
	cout << "Brruppp.\n";
	m_Hunger -= food;
	if(m_Hunger < 0){
		m_Hunger = 0;
	}
	passTime();
}

void Critter::play(int fun){
	cout << "Wheee!\n";
	m_Boredom -= fun;
	if(m_Boredom < 0){
		m_Boredom = 0;
	}
	passTime();
}


int main(){
	
	Critter crit;
	crit.talk();
	
	int choice;
	do{
		cout << "\n\t\t\t****Critter Caretaker****\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter.\n";
		cout << "2 - Feed your critter.\n";
		cout << "3 - Play with your critter.\n";
		// Add additional option
		
		
		cout << "Choice: " << endl;
		cin >> choice;
		
		switch(choice){
			case 0:
				cout << "Good-bye.\n";
				break;
			case 1:
				crit.talk();
				break;
			case 2:
				crit.eat();
				break;
			case 3:
				crit.play();
				break;
			default:
				cout << "\nSorry, but " << choice << "is not a valid choice.\n";
		}
		
		
	} while(choice != 0);
	
	return 0;
}
