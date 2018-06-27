// Triple - Overloaded Functions

#include <iostream>
#include <string>

using namespace std;

// function prototypes
int triple(int number);
string triple(string text);

int main(){
	
	cout << "Tripling 5: " << triple(5) << endl;
	
	cout << "Tripling word: " << triple("word") << endl;
	
	
	
	return 0;
}

int triple(int number){
	
	return number * 3;
}

string triple(string text){
	return text + text + text;
}
