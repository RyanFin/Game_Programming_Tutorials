// Lost Fortune 
// A personalised adventure

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;
	
	// Get Information
	cout << "Welcome to Lost Fortune!" << endl;

	cout << "Please enter the following for your personalised adventure: " << endl;
	
	cout << "Enter a number: " << endl;
	cin >> adventurers;

	cout << "Enter a number, smaller than the first: " << endl;

	cin >> killed;
	
	// Determine Survivors
	survivors = adventurers - killed;
	
	cout << "Enter your last name: " << endl;
	cin >> leader;
	
	// Tell the story
		
	cout << "A large group of " << adventurers << " adventurers set out on a quest -- in search of the lost treasure of Ancient Dwarves." << 
	"The group was led by a legendary rouge, who comes by the name of " << leader <<"." << endl;
	
	cout << "\nAlong the way, a band of maurauding ogres attack the party. All fought valiantly under the command of " << 
	leader << ", and the ogres were swiftly defeated, but a cost of " << killed << " lives who perished in the battle. Leaving just " << 
	survivors << " remaining in the group." <<endl;
	
	cout << "\nThe party was about to give up all hope. But whilst leaving the deceased to rest, they stumbled upon the buried fortune." <<
	" So the adventurers split "<< GOLD_PIECES << " gold pieces." << leader << " held on to the extra "<< (GOLD_PIECES % survivors) << " pieces to keep things fair of course.\n" << endl;
	
	system("pause");
	return 0;
}
