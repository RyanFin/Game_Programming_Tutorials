// Referencing

#include <iostream>

using namespace std;

int main(){
	
	int myScore = 1000;
	int& mikesScore = myScore; // create a reference
	
	cout << "myScore is: " << myScore << endl;
	cout << "mikesScore is: " << mikesScore << endl;
	
	cout << "Adding 500 to myScore\n";
	myScore += 500;
	
	cout << "myScore is: " << myScore << endl;
	cout << "mikesScore is: " << mikesScore << endl;
	
	cout << "Adding 500 to mikesScore.\n";
	mikesScore += 500;
	
	cout << "myScore is: " << myScore << endl;
	cout << "mikesScore is: " << mikesScore << endl;
	
	return 0;
}
