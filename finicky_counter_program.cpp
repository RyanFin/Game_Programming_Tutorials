// Finicky Counter Program

#include <iostream>

using namespace std;

int main(){
	
	
	int count = 0;
	
	while(true){
		
		// increment count
		count += 1;
		
		// exit condition (hence not an infinite loop)
		if(count > 10){
			break;
		}
		
		// skip the number 5, as program goes straight back to the top of the loop
		if (count == 5){
			continue;
		}
		
		cout << count << endl;
	
	}
	return 0;
}
