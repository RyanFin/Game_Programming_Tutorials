// Word Jumble

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	
	enum fields{WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	// create a two-dimensional array in format - WORDS[x][HINT]
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you're banging your head against something?'"},
		{"glasses","These might help you see the answer"},
		{"laboured","Going slowly, is it?"},
		{"persistent","Keep at it."},
		{"jumble","It's what the game is all about :)"}
	};
	
	// Pick random words for choices
	
	srand(time(0)); // Seed the random generator
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; // word to guess
	string theHint = WORDS[choice][HINT]; // hint for word
	
	// Jumble the selected word
	
	string jumble = theWord; // Jumbled version of the word
	int length = jumble.size();
	for (int i = 0; i < length; ++i){
		int index1 = (rand() % length);
		int index2 = (rand() % length); // Random Index in the string
		char temp = jumble[index1]; // Store temporary character at random index of string 
		// Swap random indices
		jumble[index1] = jumble[index2]; 
		jumble[index2] = temp; 
	}
	
	// Welcome the player
	cout << "\t\t\t***Welcome to Word Jumble***" << endl;
	cout << "Unscramble the words to make a word.\n";
	cout << "Enter 'hint' for a hint." << endl;
	cout << "Enter 'quit' to quit the game." << endl;
	cout << "The jumble is: " << jumble;
	
	// Get user input
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;
	
	// Game Loop
	while((guess != theWord) && (guess != "quit")){
		
		if(guess == "hint"){
			cout << theHint;
		} else{
			cout << "Sorry, that's not it.'";
		}
		
		cout << "\n\nYour guess: ";
		cin >> guess;
	
	}
	
	// Goodbye Message
	if(guess == theWord){
		cout << "\nThat's it. Congratulations for guessing it!\n";
		
		cout << "Thanks for playing!" << endl; 
	}
	
	
	
	
	

	
	return 0;
}
