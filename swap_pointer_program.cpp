// Swap Program

#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main(){
	
	int score = 150;
	int yourScore = 1000;
	cout << "\t\t\t---Original Values--- " << endl;
	
	cout << "Score : " << score << endl;
	cout << "Your Score : " << yourScore << endl;
	
	cout << "Calling Bad Swap\n";
	badSwap(score, yourScore);
	cout << "Score : " << score << endl;
	cout << "Your Score : " << yourScore << endl; // Swap does not persist. Original values are reprinted in main()
	
	
	cout << "Calling Good Swap\n";
	goodSwap(&score, &yourScore);
	cout << "Score : " << score << endl;
	cout << "Your Score : " << yourScore << endl;
	
	return 0;
}

void badSwap(int x, int y){
	int temp = x;
	x = y;
	y = temp;
	// Values do swap, however this is transient and only lasts for the duration of the loop
}

void goodSwap(int* const pX, int* const pY){
	// store value pointed to by pX in temp
	int temp = *pX;
	// store value pointed to by pY in address pointed to by pX
	*pX = *pY;
	// store value originally pointed to by pX in address pointed to by pY
	*pY = temp;

}






