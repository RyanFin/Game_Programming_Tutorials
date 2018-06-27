// Taking Damage Program

#include <iostream>

using namespace std;

int radiation(int health);

int main(){
	
	int health = 80;
	cout << "Your health is: " << health << endl;
	
	health = radiation(health);
	cout << "After radiation exposure, your new health is: " << health << endl;
	
	health = radiation(health);
	cout << "After radiation exposure, your new health is: " << health << endl;
	
	health = radiation(health);
	cout << "After radiation exposure, your new health is: " << health << endl;
	
	
	return 0;
}

inline int radiation(int health){ // Inline small code such as this to improve overall performance of the program
	return (health / 2);
}
