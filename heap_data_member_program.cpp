// Head Data Member Program

#include <iostream>
#include <string>

using namespace std;

class Critter{
	public:
		// Constructor
		Critter(const string& name = ""){
			cout << "Constructor called...\n";
			m_pName = new string(name); // allocate memory for the string at a new memory address
		}
		
		//Destructor
		~Critter(){
			cout << "Destructor called...\n";
			delete m_pName; // delete variable and free memory!
		}
		
		// Copy Constructor
		Critter(const Critter& c){
			cout << "Copy constructor called...\n";
			m_pName = new string; // points the pointer to a new address in memory with the same value!
			*m_pName = c.getName();
		}
		
		// Overloaded assignment operator
		Critter& operator=(const Critter& c){
			cout << "Overloaded assignment operator called...\n";
			if(this == &c){
				return *this;
			} else{
				*m_pName = c.getName();
			}
		}
		
		string getName() const{
			return *m_pName;
		}
		void setName(const string& name = ""){
			*m_pName = name;
		}
		
		void sayHi() const{
			cout << "Hi, my name is " << getName() << endl;
		}
		
		private:
			string* m_pName; // data member pointer points to string value in the heap
	
};

// function prototypes
void testDestructor();
void testCopyConstructor(Critter copy);
void testAssignmentOp();

int main(){
	testDestructor();
	cout << endl;
	
	Critter crit("Poochie");
	crit.sayHi();
	testCopyConstructor(crit); // variable is copies using 'pass by value'
	testAssignmentOp();
	
	return 0;
}

void testDestructor(){
	Critter crit("Rover");
	crit.sayHi();
}

void testCopyConstructor(Critter copy){
	copy.sayHi(); // Pass by value means a copy of a critter is made, unlike pass by reference which works with the passed variable directly
}

void testAssignmentOp(){
	
	Critter crit1("crit 1");
	Critter crit2("crit 2");
	crit1 = crit2;
	crit1.sayHi();
	crit2.sayHi();
	
	cout << "Setting the name of crit1 back to 'crit1'\n";
	crit1.setName("crit 1");
	crit1.sayHi();
	crit2.sayHi();
	
	Critter crit("crit");
	crit = crit;
		
}
