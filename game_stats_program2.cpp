//Game Stats Program 2

#include <iostream>

using namespace std;

int main(){
	
	unsigned int score = 5000;
	cout << "Score: " << score << endl;
	
	//Alter the value of score
	
	score = score + 100;
	cout << "New Score: " << score << endl;
	
	// or
	
	score += 100;
	cout << "New Score: " << score << endl;
	
	// increment operators
	int lives = 3;
	
	// preincrement
	++lives;
	cout <<  "Lives: " << lives << endl;
	
	// postincrement
	lives = 3;
	lives++;
	cout << "Lives: " << lives << endl;
	
	// Add a bonus 
	lives = 3;
	int bonus = ++lives * 10;
	cout << "Lives, Bonus: " << lives << ", " << bonus << endl;
	
	lives = 3;
	bonus = lives++ * 10;
	cout << "Lives, Bonus: " << lives << ", " << bonus << endl;
	
	// Integer wrap around
	score = 4294967295;
	cout << "\nscore: " << score << endl;
	++score;
	cout << "score: " << score << endl;

	return 0;
}
