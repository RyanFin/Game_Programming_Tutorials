// Score Rater Program 2

#include <iostream>
using namespace std;

int main(){
	
	cout << "Enter your score: \n";
	
	int userScore;
	cin >> userScore;
	
	if(userScore > 500){
		cout << "You got over 500. Nice score :)\n";
	} else{
		cout << "You got 500 or less. Nothing to brag about mate.\n";
	}
	
	return 0;
}
