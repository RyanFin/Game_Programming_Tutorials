// Game Lobby Program

#include <iostream>
#include <string>

using namespace std;


// Player Class
class Player{
	public:
		Player(const string& name=""){
			m_Name = name;
			m_pNext = 0; // null pointer
		}
		
		// Getter functions
		string getName() const{
			return m_Name;
		}
		
		Player* getNext() const{
			return m_pNext;
		}
		
		// Setter functions
		void setNext(Player* next){
			m_pNext = next;
		}
		
		
	private:
		string m_Name;
		Player* m_pNext; // Pointer to the next player in the list (forming a linked list of nodes)
	
};

// Lobby class
// Lobby / line in which player must wait
class Lobby{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby); // declare the '<<' as a friend of the Lobby class so that Lobby objects can be sent to cout
	public:
		Lobby(){
			m_pHead = 0; // null pointer
		}
		// destructor
		~Lobby(){
			clear();
		}
		void addPlayer(); // instantiates a Player object on the heap in memory - adds to the end of the list
		void removePlayer(); // removes the first Player object in the list, freeing the allocated memory
		void clear(); // frees allocated memory as all Player objects are deleted from the linked list
	private:
		Player* m_pHead;
};

// Adds a player to the end of the line in the Lobby
void Lobby::addPlayer(){
	// create a new Player node
	cout << "Please enter the name of the player: " << endl;
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name); // Create a pointer that allocates memory to a new player at a new address in the heap
	
	// if the list is empty, make head of list this new player
	if(m_pHead == 0){
		m_pHead = pNewPlayer;
	} else{
		// otherwise find the end of the list and add the player there
		Player* pIter = m_pHead;
		while(pIter->getNext() != 0){ // if getNext equals 0, this means that the Player object is the last object in the list
			pIter = pIter->getNext(); // If not the last element in the list, get the next Player object
		}
		pIter->setNext(pNewPlayer); // Otherwise add the new player to the end of the list
	}	
}

// Removes a player from the lobby
void Lobby::removePlayer(){
	if(m_pHead == 0){
		cout << "The game lobby is empty. No one to remove!\n";
	} else{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->getNext();
		delete pTemp;
	}
}

// clear ALL Player object nodes from the linked list
void Lobby::clear(){
	while(m_pHead != 0){
		removePlayer();
	}
}

// modify the default '<<' operator and customise for use with the lobby
ostream& operator<<(ostream& os, const Lobby& aLobby){
	Player* pIter = aLobby.m_pHead;
	
	os << "\nHere's who's in the game lobby: ''\n";
	if(pIter == 0){
		os << "The lobby is empty.\n";
	} else{
		while(pIter != 0){
			os << pIter->getName() << endl;
			pIter = pIter->getNext();
		}
	}
	return os;
}



int main(){
	// Instantiate the Lobby
	Lobby myLobby;
	int choice;
	
	do{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";
		cout << endl << "Enter Choice: ";
		cin >> choice;
		
		switch(choice){
			case 0:
				cout << "Goodbye.\n";
				break;
			case 1:
				myLobby.addPlayer();
				break;
			case 2:
				myLobby.removePlayer();
				break;
			case 3:
				myLobby.clear();
				break;
			default:
				cout << "That was not a valid choice.\n";
		}
		
	} while(choice != 0);
	
	
	
	return 0;
}
