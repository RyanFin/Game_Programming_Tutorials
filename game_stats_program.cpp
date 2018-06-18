// Game Stats 
// Simple Variable program in C++

#include <iostream>

using namespace std;

int main(){
	
	// Instance Variables
	int score;
	double distance;
	char playAgain;
	bool shieldsUp;
	
	short lives, aliensKilled;
	
	// Initialisation 
	score = 0;
	distance = 1200.76;
	playAgain = 'y';
	shieldsUp = true;
	lives = 3;
	aliensKilled = 10;
	
	double engineTemp = 6572.89;
	
	// Output values
	
	cout << "Score: " << score << endl;
	cout << "Distance: " << distance << endl;
	cout << "Play Again: " << playAgain << endl;
	cout << "Lives: " << lives << endl;
	cout << "Aliens Killed: " << aliensKilled << endl;
	cout << "Engine Temperture: " << engineTemp << endl;
	
	// Input Fuel values
	
	int fuel;
	cout << "\nHow much fuel?" << endl;
	cin >> fuel;
	cout << "Fuel: " << fuel << endl;
	
	typedef unsigned short int ushort;
	ushort bonus = 10;
	cout << "\Bonus: " << bonus << endl;
	
	
	
	
	system("pause");
	
	return 0;
}
