// Simple Boss Program

#include <iostream>
#include <string>

using namespace std;

class Enemy{
	public:

		// constructor
		Enemy(){
			m_Damage = 10;
		}
		
		void attack() const{
		cout << "Enemy inflicts " << m_Damage << " damage points!\n"; 
		}
	
	protected:
		int m_Damage;		
};

class Boss : public Enemy{
	public:

		// constructor
		Boss(){
			m_DamageMultiplier = 3;
		}
		
		void specialAttack() const{
			cout << "Special attack inflicts: " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
		}
		
	private:
		int m_DamageMultiplier;
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
