// Inventory Referencer Program

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// returns a reference to a string
string& refToElement(vector<string>& vec, int i); // function prototype 

int main(){
	
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield"); 
	
	
	// displays string that the returned reference refers to
	cout << "Sending the returned reference to cout:\n";
	cout << refToElement(inventory, 0);
	
	// Assigns one reference to another - inexpensive assignment
	cout << "Assigning the returned reference to another reference.\n";
	string& rStr = refToElement(inventory, 1);
	cout << "Sending the new reference to cout:\n";
	cout << rStr << endl;
	
	// Altering the string object through a returned reference 
	cout << "Altering the object through a returned reference.\n";
	rStr = "Healing Potion";
	cout << "Sending the altered object to cout:\n";
	cout << inventory[1] << endl;
	
	return 0;
}


string& refToElement(vector<string>& vec, int i){
	
	return vec[i];
	
}


