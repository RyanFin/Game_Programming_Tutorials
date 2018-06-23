// Hero Inventory Program

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS]; // Set length of the array
    
    int numItems = 0;
    inventory[numItems++] = "Sword";
    inventory[numItems++] = "Armour";
    inventory[numItems++] = "Shield";
    
    cout << "Your Items \n";
    for (int i = 0; i < numItems; ++i){
    	cout << inventory[i] << endl;
	}
	
	cout << "\nYou trade your sword for a battle axe.\n";
	inventory[0] = "Battle Axe"; // replace sword
	
	cout << "Your Items\n";
	
	for (int i = 0; i < numItems; ++i){
		cout << inventory[i] << endl;
	}
	
	cout << "The item name '" << inventory[0] << "' has ";
	cout << inventory[0].size() << " letters in it.\n";
	
	cout << "\nYou find a healing potion.";
	
	// Add a healing potion to the inventory if the number of items does not 
	// exceed the total inventory capacity 
	if(numItems < MAX_ITEMS){
		inventory[numItems++] = "Healing Potion"; 
	} else{
		cout << "You have too many items and can't carry anymore...\n";
	}
	
	cout << "Your Items\n";
	
	for (int i = 0; i < numItems; ++i){
		cout << inventory[i] << endl;
	}
	

    return 0;
}
