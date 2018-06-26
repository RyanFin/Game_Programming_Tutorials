// Yes or No Program

#include <iostream>
#include <string>

using namespace std;

// function prototyping
char askYesNo1();
char askYesNo2(string question);

int main(){
	
	char answer1 = askYesNo1();
	cout << "Thanks for answering " << answer1 << "\n\n" <<  endl;
	
	char answer2 = askYesNo2("Do you wish to save your game?");
	cout << "Thanks for answering " << answer2 << "\n\n" <<  endl;
	
	return 0;
}

char askYesNo1(){
	char response1;
	
	do{
		cout << "\nPlease enter 'y' or 'n': \n";
		cin >> response1;
	} while(response1 != 'y' && response1 != 'n');
	
	
	return response1;
}

char askYesNo2(string question){
	char response2;
	
	do{
		cout << question << " (y/n): " << endl;
		cin >> response2;
		
	} while(response2 != 'y' && response2 != 'n');
}



