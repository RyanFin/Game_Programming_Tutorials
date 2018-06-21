// Score Rater Program

#include <iostream>

using namespace std;

int main(){
	
	if(true){
		cout << "This is always displayed. \n\n";
		
		cout << "This is never displayed. \n\n";
		
		int score = 1000;
		
		if(score){ // Any non-zero value is equivalent to 'true'. 0 is equal to false
			cout << "At least you did not score zero...\n\n";
		}
		
		if(-13){ // Even Negative numbers count as true by the if-statement
			cout << "Will this piece of code ever run..." << endl;
		}
		
		if(0){ // 0 counts as false
			cout << "This is never displayed.\n";
		}
		
		if(score > 500){
			cout << "You scored over 500. Nice :)\n\n";
		}
		
		if(score == 1000){
			cout << "Congrats you scored 1000!\n\n";
			cout << "Now that's impressive.\n";
		}
		
		if(score > 500){
			cout << "You scored over 500.\n";
			if(score == 1000){
			cout << "Congrats you scored 1000!\n\n";
		}
		}
		
		
		
	}
	
	
	return 0;
}
