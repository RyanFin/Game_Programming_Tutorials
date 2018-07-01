// Pointing Program

#include <iostream>

using namespace std;

int main(){
	
	int* pAPointer; 	// initialise a pointer
	int* pScore = 0; 	// declare and initialise a pointer
	
	int score = 1000;
	pScore = &score; // assign pointer 'pScore' to the address location of variable 'score'
	
	cout << "Assigning &score to pScore...\n";
	cout << "&score is: " << &score << endl; 	// address location of score variable
	cout << "pScore is: " << pScore << endl;	// address stored in pointer
	cout << "score is: " << score << endl;
	cout << "*pScore is: " << *pScore << "\n\n"; 	// value pointed to by pointer
	
	cout << "Adding 500 to score...\n";
	score += 500;
	cout << "score is: " << score << endl;
	cout << "*pScore is: " << *pScore << "\n\n";
	
	cout << "Adding 500 to pScore...\n";
	*pScore += 500; // Must dereference the pointer before adding a value to it!!
	cout << "score is: " << score << endl;
	cout << "*pScore is: " << *pScore << "\n\n";
	
	cout << "Assigning &newScore to pScore...";
	int newScore = 5000;
	pScore = &newScore; // Assign the pointer to newScore (without the dereferencer)
	cout << "&newScore is: " << &newScore << endl;
	cout << "pScore is: " << pScore << endl;
	cout << "newScore is: " << newScore << "\n\n";
	
	cout << "Assigning &str to pStr..." << endl;
	string str = "score";
	string* pStr = &str; // pointer for address location of str variable
	cout << "str is: " << str << endl;
	cout << "*pStr is: " << *pStr << endl;
//	cout << "pStr is: " << pStr <<endl;
	cout << "(*pStr).size() is: " << (*pStr).size() << endl;
	cout << "pStr->size() is: " << pStr->size() << "\n\n";

	return 0;
}
