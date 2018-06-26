// hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main(){
	// Setup
	const int MAX_WRONG = 8; // max num of incorrect guesses allowed
	
	vector<string> words; // collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT"); // populate the vector collection
	
	srand(time(0)); // Seed for random order each time program is started
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; // choose the first word in the list
	int wrong = 0; 
	string soFar(THE_WORD.size(), '-'); // Add dashes to signify the amonut of letters in the secret word
	string used = "";
	
	// Game Loop
	cout << "\t\t\tWelcome to Hangman!!\n";
	
	while((wrong < MAX_WRONG) && (soFar != THE_WORD)){
		
		cout << "\n\nYou have " << (MAX_WRONG - wrong) << "incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;
		
		// Get user input
		char guess;
		cout << "\n\nEnter your guess: " << endl;
		cin >> guess;
		guess = toupper(guess); //convert guess to UPPERCASE
		while(used.find(guess) != string::npos){ //while the guess is not equal to an empty string
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
			
		}
		
		used += guess; // add guess to the 'used' string
		
	
		
		
		
	}
	
	
	
	
	
	 
	
	

	return 0; 
}
