// Menu Chooser Program

#include <iostream>

using namespace std;

int main(){
	
	// Title
	cout << "Difficulty Level" << endl;
	
	cout << "1 - Easy\n";
	cout << "2 - Medium\n";
	cout << "3 - Hard\n";
	
	cout << "Your Choice: " << endl;
	int choice;
	cin >> choice;
	
	switch(choice){
		case 1: cout << "Easy Mode Selected.\n";
				break;
		case 2: cout << "Medium Mode Selected.\n";
				break;
		case 3: cout << "Hard Mode Selected.\n";
				break;
		default: cout << "No valid Entry...";
				break;
	}

	
	return 0;
}
