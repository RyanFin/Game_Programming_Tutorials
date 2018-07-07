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
			
		}
		
	protected:
		int m_health;
	
};

int main(){
	
	
	
	return 0;
}
