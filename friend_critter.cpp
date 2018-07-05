// 'Friend' Critter Program
// Demonstrates friend functions and operator overloading

#include <iostream>

using namespace std;

class Critter{
	
	// make following global functions friends off the critter class
	friend void Peek(const Critter& aCritter);
	friend ostream& operator<<(ostream& os, const Critter& aCritter);
	
	public:
		Critter(const string& name = ""){
			m_Name = name;
		}
	private:
		string m_Name;	
};

void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main(){
	
	Critter crit("Poochie");
	
	cout << "Calling Peek() to access crit's private data member, mName: \n";
	Peek(crit);
	
	cout << "\nSending crit object to cout with the << operator\n";
	cout << crit;
	
	return 0;
}

// global friend function which can access all of a Critter object's members
void Peek(const Critter& aCritter){
	cout << aCritter.m_Name << endl;
}

// global friend function which can access all of a Critter object's members
// overloads the << operator so you can send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& aCritter){
	os << "Critter object -";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}


