// Hero Inventory Program 3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	vector<string> inventory;
	inventory.push_back("Sword");
	inventory.push_back("Armour");
	inventory.push_back("Shield");
	
	// Create iterator of the type vector<string>
	vector<string>::iterator myIterator;
	// Create constant iterator of the type vector<string>
	vector<string>::const_iterator iter; // can NOT modify the value of the element it is tagged to within the container
	
	cout << "Your Items: \n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter){
		cout << *iter << endl; // output the element that the iterator refers to
	}
	
	cout << "\nYou trade your sword for a battle axe\n";
	
	myIterator = inventory.begin();
//	myIterator++;
	*myIterator = "Battle Axe"; //Change to battle axe whilst myIterator references the first element in the container
	
	cout << "Your Items: " << endl;
	
	for(iter = inventory.begin(); iter != inventory.end(); ++iter){
		cout << *iter << endl;
	}
	
	// Display the number of characters in the first item of the hero's inventory
	cout << "The item name '" << *myIterator << "' has ";
	cout << (*myIterator).size() << " letters in it.\n"; 
	
	// Alternative syntax
	cout << "The item name'" << *myIterator << "' has ";
	cout << myIterator->size() << " letters in it.\n";
    
    return 0;
}
