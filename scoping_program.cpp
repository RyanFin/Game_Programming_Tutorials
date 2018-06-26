// Scoping Program - Demonstrates scopes

#include <iostream>

using namespace std;

// function prototyping
void func();

int main(){
	
	int var = 5; // local variable in main method
	cout << "In main() var is: " << var << endl;
	
	func();
	
	cout << "Back in main() var is: " << var << "\n\n";
	
	// Add nested scope 
	{
		cout << "In main() in a new scope var is: " << var << endl;
		
		cout << "Creating a new scope.\n";
		int var = 10; 	// Variable in new scope, hides other variable named 'var'
		cout << "In a new 'nested' scope in main(), var is: " << var << endl;
	}
	
	cout << "At the end of main() var created in new scope no longer exists.\n";
	cout << "At the end of main() var is: " << var << "\n\n";
	
	
	return 0;
}

void func(){
	int var = -5;
	cout << "In func() var is: " << var << endl;
	
}
