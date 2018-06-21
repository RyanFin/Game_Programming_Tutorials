// Play Again Program

#include <iostream>

using namespace std;

int main(){
	
	char again = 'y';
	
	
	while(again == 'y'){
		cout << "*Played an amazing game*\n";
		cout << "Play again??";
		cin >> again;
	}
	
	cout << "Exit Game...";
	
	system("pause");
	return 0;
}
