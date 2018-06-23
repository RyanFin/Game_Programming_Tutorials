// Using String Objects

#include <iostream>
#include <string>

using namespace std;

int main(){
	
	
	// instantiate String Variables
	string word1 = "Game";
	string word2("Over");
	string word3(3, '!');
	
	// Concatenate String Values
	string phrase = word1 + " " + word2 + word3; // use addition symbol (+) to concatenate strings
	
	cout << "The phrase is: " << phrase << endl;
	
	cout << "The phrase has a length of: " << phrase.size() << endl;
	cout << "The phrase has a length of: " << phrase.length() << endl; // Two ways of getting the length of a string 
	
	cout << "The character at position 0 is " << phrase[0] << endl;
	
	// Change the value of a single variable
	cout << "Changing the character position at 0" << endl;
	phrase[0] = 'L';
	cout << "The phrase is now " << phrase << endl;
	
	for (int i = 0; i < phrase.length(); ++i){
		cout <<"Character position at position " << i << "is: " << phrase[i] << endl;
	}
	
	// Finding substrings within a string
	cout << "The sequence 'Over' begins at location: " << phrase.find("Over") << endl;
	
	if(phrase.find("eggplant") == string::npos){
		cout << "'eggplant' is not in the phrase" << endl;
	} 
	
	phrase.erase(4, 5);
	
	cout << "The phrase is now: " << phrase << endl;
	
	phrase.erase(4);
	
	cout << "The phrase is now: " << phrase << endl;
	
	phrase.erase();
	
	cout << "The phrase is now: " << phrase << endl;
	
	if(phrase.empty()){
		cout << "\nThe phrase is no more\n";
	}

	return 0;
}
