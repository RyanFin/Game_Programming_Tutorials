// Abstract Creature
#include <iostream>

using namespace std;

// Abstract Class
class Creature{
	public:
		// constructor
		Creature(int health = 100){
		m_health = health;	
		}
		
		// pure virtual member function
		virtual void Greet() const = 0;
		
		virtual void displayHealth() const{
			cout << "Health: " << m_health << endl;
		}
		
	protected:
		int m_health;
};

class Orc : public Creature{
	public:
		// constructor
		Orc(int health = 120): Creature(health){
			
		}
		
		virtual void Greet() const{
			cout << "The orc grunts hello.\n";
		}
};

int main(){
	
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->displayHealth();
	
	return 0;
}
