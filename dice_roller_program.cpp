// Dice Roller Program

#include <iostream>
#include <cstdlib> // Use of the rand() function
#include <ctime>

using namespace std;

int main(){
	
	srand(time(0)); // Seed random number generator based on current time
	
	int randomNumber = rand(); // Generate random number
	
	int die = (randomNumber % 6) + 1; // Get a number between 1 and 6
	cout << "You rolled a " << die << endl;
	
	return 0;
}
