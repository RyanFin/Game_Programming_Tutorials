// Overriding Boss Program

#include <iostream>
#include <string>

using namespace std;

class Enemy{
	
	public:	
	Enemy(int damage = 10){
		m_Damage = damage;
	}
	
	void taunt() const{
		cout << "The enemy says he will fight you.\n";
	}
	
	void attack() const{
		cout << "Attack! Inflicts " << m_Damage << " damage points.";
	}
	
	private:
		int m_Damage;
	
};

class Boss : public Enemy{
	public:
		// call base constructor (of superclass)with argument
		Boss(int damage = 30): Enemy(damage){
			
		}
		
		// overriden function from superclass
		void taunt() const{
			cout << "The boss says he will end your pitiful existence.\n";
		}
		
		void attack() const{
			Enemy::attack(); // output superclass attack function
			cout << " And laughs heartily at you.\n"; // override with additional functionality!
		}
			
};

int main(){
	
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.taunt();
	enemy1.attack();
	
	cout << "\n\nCreating a boss.\n";
	Boss boss1; 
	boss1.taunt();
	boss1.attack();

	
	return 0;
}
