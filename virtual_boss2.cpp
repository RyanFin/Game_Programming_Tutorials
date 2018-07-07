// Virtual Boss 2

#include <iostream>
#include <string>

using namespace std;

class Enemy{
	public:
		
		//virtual constructor
		Enemy(int damage = 10){  
			m_pDamage = new int(damage);
		}
		
		//virtual destructor
		virtual ~Enemy(){
			cout << "m_pDamage deleted.\n";
			delete m_pDamage;	
		}
		
		void taunt() const{
			cout << "The enemy says he will fight you.\n";
		}
		
		void virtual Vtaunt() const{
			cout << "The enemy says he will fight you.\n";
		}
		
	protected:
		int* m_pDamage;
		
};

class Boss : public Enemy{
	public:
		
		Boss(int multiplier = 3){
			m_pDamageMultiplier = new int(multiplier);
		}
		
		virtual ~Boss(){
			cout << "m_pDamageMultiplier deleted\n";
			delete m_pDamageMultiplier;
		}
		
		void taunt() const{
			cout << "The boss says that he will end your pitiful existence.\n";
		}
		
		virtual void Vtaunt() const{
			cout << "The boss says that he will end your pitiful existence.\n";
		}
		
	private:
		int* m_pDamageMultiplier;
};

int main(){
	
	cout << "Pointer to Enemy that points to a Boss object:\n";
	Enemy* pBadGuy = new Boss();
	pBadGuy->taunt();
	pBadGuy->Vtaunt();
	
	cout << "Deleting pointer to enemy.\n";
	delete pBadGuy; // delete the pointer
	pBadGuy = 0; // clear the memory

	return 0;
}
