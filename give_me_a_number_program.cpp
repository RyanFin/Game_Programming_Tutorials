// Give me a number program

#include <iostream>
#include <string>

using namespace std;

// function prototyping with default value assigned
int askNumber(int high, int low = 1);

int main(){
	
	int number = askNumber(5); // Uses default value (1) as the value for the parameter 'low'
	
	cout << "Thanks for entering: " << number << endl;
	
	number = askNumber(10, 5);
	
	cout << "Thanks for entering: " << number << endl;
	

	return 0;
}

int askNumber(int high, int low){
	
	int num;
	
	do{
		
		cout << "Please enter a number: " << "(" << low << " - " << high << "): ";
		cin >> num;
		
		
	} while(num > high || num < low);
	
	return num;
}
