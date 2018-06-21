// Play Again Program

#include <iostream>

using namespace std;

int main(){
	
	char again = 'y';
	
	do{ // Guarantees that the statement will run atleast once!
		cout << "*Played an amazing game*\n";
		cout << "Play again??";
		cin >> again;
	}
	while(again == 'y');
	
	cout << "Exit Game...";
	
	system("pause");
	return 0;
}
