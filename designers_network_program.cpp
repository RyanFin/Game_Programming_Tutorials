// Designers Network Program

#include <iostream>

using namespace std;

int main(){
	
	cout << "           Game Designer's Network\n";
	
	cout << "username: ";
	
	string username, password;
	
	int securityLevel = 0;
	
	cin >> username;
	
	cout << "password: " ;
	
	cin >> password;
	
	if (username == "21296921" && password == "1234"){
		
		cout << "Hey 21296921" << endl;
		securityLevel = 5;
			
	} else{
		cout << "Your login failed\n";
	}
	
	if(username == "guest" || password == "guest"){
		cout << "Access Granted..." << endl;
		securityLevel = 1;
	}
	
	if(!securityLevel){
		cout << "Your login failed\n";
	}
	
	
	
	
	return 0;
}


