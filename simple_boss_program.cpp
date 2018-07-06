// Simple Boss Program

#include <iostream>
#include <string>

using namespace std;

class Enemy{
	public:
		int m_Damage;
		
		// constructor
		Enemy(){
			m_Damage = 10;
		}
		
		void attack() const{
		cout << "Enemy inflicts " << m_Damage << " damage points!\n"; 
		}		
};

class Boss : public Enemy{
	public:
		int m_DamageMultiplier;
		
		// constructor
		Boss(){
			m_DamageMultiplier = 3;
		}
		
		void specialAttack() const{
			cout << "Special attack inflicts: " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
		}
};


int main(){
	
	cout << "Creating an enemy" << endl;
	Enemy enemy1;
	enemy1.attack();
	
	cout << "Creating a boss" << endl;
	Boss boss1;
	boss1.attack();
	boss1.specialAttack();
	
	return 0;
}
