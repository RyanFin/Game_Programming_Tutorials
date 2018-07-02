// Array Passer Program

#include <iostream>

using namespace std;

// function prototypes
void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);

int main(){
	
	cout << "Creating an array of high scores.\n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = {5000, 3500, 2700};
	
	cout << "Displaying scores using the array name as a constant pointer.\n";
	cout << *highScores << endl; // same as array[0]!
	cout << *(highScores + 1) << endl;
	cout << *(highScores + 2) << endl;
	
	cout << "Increasing scores by passing array as a constant pointer.\n\n";
	increase(highScores, NUM_SCORES);
	
	cout << "Displaying scores by passing array as a constant pointer to a constant.\n\n";
	display(highScores, NUM_SCORES);
	
	return 0;
}

void increase(int* const array, const int NUM_ELEMENTS){
	for(int i = 0; i < NUM_ELEMENTS; ++i){
		array[i] += 500;
	}
}


void display(const int* const array, const int NUM_ELEMENTS){
	for(int i = 0; i < NUM_ELEMENTS; ++i){
		cout << array[i] << endl;
	}
}


