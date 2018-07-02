// Inventory Pointer

#include <iostream>
#include <vector>
#include <string>


using namespace std;

// returns a pointer to a string element
	string* ptrToElement(vector<string>* const pVec, int i); // Constant Pointer

int main(){
	
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");
	
	// create an iterator
	vector<string>::const_iterator iter; // constant so that values CANNOT be modified
	
	// displays string object that the returned pointer points to
	cout << "Sending the objected pointed to by returned pointer:\n";
	cout << *(ptrToElement(&inventory, 0)) << "\n\n"; 
	
	// assigns one pointer to another - inexpensive assignment
	cout << "Assigning the returned pointer to another pointer" << endl;
	string* pStr = ptrToElement(&inventory, 1); 
	cout << "Sending the object pointed to by new pointer to cout.\n";
	cout << *pStr << endl;
	
	
	// copies a string object - expensive assignment
	cout << "Assigning object pointed by pointer to a string object.\n";
	string str = *(ptrToElement(&inventory, 2));
	cout << "Sending the new string object to cout:\n";
	cout << str << endl;
	
	// altering the string object through a returned pointer
	cout << "Altering an object through a returned pointer.\n";
	*pStr = "Healing Potion";
	cout << "Sending the altered object to cout:\n";
	cout << *pStr << endl;
	
	cout << "\nInventory: " << endl;
	// iterate through the items with a constant iterator!
	for(iter = inventory.begin(); iter != inventory.end(); ++iter){
		
		cout << *iter << endl;
	}
	
	cout << "\nInventory: " << endl;
	for (int i = 0; i < inventory.size(); i++){
		cout << inventory[i] << endl;
	}
	
	
	
	return 0;
}

string* ptrToElement(vector<string>* const pVec, int i){
	// returns address of the string in position i of vector that pVec points to
	cout << "pVec: " << pVec << endl;
	
	return &((*pVec)[i]);
}

