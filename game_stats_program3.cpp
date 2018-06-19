// Game Stats Program 3

#include <iostream>

using namespace std;

int main(){
	
	const int ALIEN_POINTS = 150;
	int alienKilled = 10;
	int score = alienKilled * ALIEN_POINTS;
	cout << "Score: " << score << endl;
	
	enum difficulty { NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
	difficulty myDifficulty = EASY;
	
	cout << "Difficulty: " << myDifficulty << endl;
	
	enum ship{FIGHTER = 25, BOMBER, CRUISER = 50, DESTROYER = 100};
	ship myShip = BOMBER;
	cout << "\nTo upgrade my ship to a cruiser will cost " << (CRUISER - myShip) << " Resource Points.\n";
	
	
	return 0;
}
