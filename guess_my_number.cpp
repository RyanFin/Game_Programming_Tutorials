// Guess My Number

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	
	cout << "   	**Welcome to Guess My Number**" << endl; // Title
	
	
	//Seed the random number generator
	srand(time(0));
	
	int randomNo = rand() % 100 + 1; // Create random number between 0-100
	
	bool guessedNumber = false; // Initialise user guessed number as false
	
	int tries = 0;
	int guess;
	
	
	while(guessedNumber == false){
		
		//Prompt user to enter a guess 
			cout << "Pick a number\n";
			cin >> guess;
			++tries;
			
			if(guess > randomNo){
				cout << "Too High!\n\n";
			}
			
			if (guess < randomNo){
				cout << "Too Low!\n\n";
			}
			
			if(guess == randomNo){
				cout << "You Guessed correctly mate :)\n\n";
				guessedNumber = true;
				cout << "Attempts: " << tries << endl;
			}	
		
	}
	
	
	return 0;
}
