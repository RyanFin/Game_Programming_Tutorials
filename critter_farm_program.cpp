// Critter Farm Program

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter{
	public:
		//Constructor using a 'Pointer to a constant' (Can't modify the value of the object that pointer points, 
		//but CAN change the pointers address: where it points) with default value of empty string ("")
		Critter(const string& name = ""){
			m_Name = name;
		}
		
		string getName() const {return m_Name;}

	private:
		string m_Name;
	
};

class Farm{
	
	public:
		Farm(int spaces = 1){
			m_Critters.reserve(spaces);
		}
		// Use of references to efficiently access the direct critter object passed as a parameter. No copies are made!
		void add(const Critter& aCritter){ // Constant reference. CANNOT refer to more than one variable at once (no alter-ego)
			m_Critters.push_back(aCritter); // add a critter to the vector (arraylist)
		}
		
		void rollCall() const{
			for(vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); ++iter){
				cout << iter->getName() << " here.\n";
			}
		
		}
		
	private:
		vector<Critter> m_Critters;
	
};

int main(){
	
	// Create a critter
	Critter crit("Poochie");
	cout << "My critters name is: " << crit.getName() << endl;
	
	cout << "Creating a critter farm.\n";
	Farm myFarm(3); // set 'spaces' variable to 3
	
	cout << "Adding Critters to the farm.\n";
	myFarm.add(crit);
	myFarm.add(Critter("Moe"));
	myFarm.add(Critter("Larry"));
	myFarm.add(Critter("Curly"));
	
	cout << "Calling Roll Call....\n";
	myFarm.rollCall();
	
	// References vs Constant References
	cout << "\t\t\t****References****\n\n";
	Critter perry("Perry");
	Critter& agentP = perry; // Reference functions as an alternate name (alter-ego!)
	cout << agentP.getName() << endl;

	
	Critter spot("Spot");
	const Critter& constRef = spot;
//	constRef = perry; // invalid as a constant reference CANNOT refer to another variable
	cout << constRef.getName() << endl;
	
	
	
	return 0;
}
