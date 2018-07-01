// Pointer tester
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	// Null Pointer 
	string* pMyString = 0;
	
	string myString = "ryan";
	pMyString = &myString; // set the pointer to the address of myString
	
	string myString2 = "Joshua";
	
	cout << "myString is: " << myString << "\n"; 
	cout << pMyString << endl;
	cout << &myString << endl;
	cout << "*pMyString is :" << *pMyString << endl;
	
	cout << "Length of myString is: " << pMyString->size() << "\n\n"; // no dereference required
	
	cout << "pMyString pointing to a different variable....\n";
	pMyString = &myString2;
	cout << &myString2 << endl;
	cout << pMyString << endl;
	cout << "*pMyString is now: " << *pMyString << endl;
	cout << "Length of myString2 is: " << pMyString->size() << "\n\n";
	
	
	
	return 0;
}
