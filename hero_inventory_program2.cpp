// Hero Inventory Program 2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    
    vector<string> inventory;
    inventory.push_back("Sword");
    inventory.push_back("Armour");
    inventory.push_back("Shield");
    
    cout << "You have " << inventory.size() << "items. \n";
    
    cout << "Your Items: \n";
    
    for(int i = 0; i < inventory.size(); ++i){
    	cout << inventory[i] << endl;
	}
	
	cout << "\nYou trade your sword for a battle axe.\n";
	inventory[0] = "Battle Axe";  
	
	cout << "\nYour Items: \n";
	
	for (int i = 0; i < inventory.size(); ++i){
		cout << inventory[i] << endl;
	}
	
	cout << "\nThe item name'" << inventory[0] << "' has ";
	cout << inventory[0].size() << " letters in it.\n";
	
	cout << "\nYour shield is destroyed in a fierce battle.\n";
	inventory.pop_back(); // Pop off the last item from the vector list
	
	cout << "Your Items: \n";
	for (int i = 0; i < inventory.size(); ++i){
		cout << inventory[i] << endl;
	}
	
	cout << "You have been robbed of all possessions..." << endl;
	inventory.clear();
	
	if(inventory.empty()){
		cout << "\nYou have nothing\n";
	} else{
		cout << "\nYou have at least one item\n";
	}
	
	
		
    
    return 0;
}
