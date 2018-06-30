// Tic-Tac-Toe
// Plays tic-tac-toe against a human opponent

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// function prototypes
void instructions(); // Displays the game instructions.
char askYesNo(string question); // Asks a yes or no question. Receives a question. Returns either 'y' or 'n'.
int askNumber(string question, int high, int low = 0); // Asks for a number within a range. Receives a question, a low number and a high number. Returns a number in the range from low to high. (default value of 0).
char humanPiece(); // Determines the human's piece . Returns either an 'X' or an 'O'.
char opponent(char piece); // Calculates the opposing piece given a piece. Receives either an 'X' or an 'O'. Returns either an 'X' or an 'O'.
void displayBoard(const vector<char>& board); // Displays the board on the screen. Receives a board (reference to the board variable directly without a copy being made).
char winner(const vector<char>& board); // Determines the game winner. Receives a board. Returns an 'X', 'O', 'T' (to indicate a tie), or 'N' (to indicate that no-one has won yet).
bool isLegal(const vector<char>& board, int move); // Determines whether a move is legal. Receives a board and a move. Returns either 'true' or 'false'.
int humanMove(const vector<char>& board, char human); // Gets the human's move. Receives a board and the human's piece. Returns the humans's move.
int computerMove(vector<char> board, char computer); // Calculates the computer's move. Receives a board and the computer's piece. Returns the computer's move (NOT passed by reference). 
void announceWinner(char winner, char computer, char human); // Congratulates the winner or declares a tie. Receives the winning side, the computer's piece, and the human's piece.



// Using the pseudocode for the game
int main(){
	
	int move;
	const int NUM_SQUARES = 9;
	
	// Create an empty Tic-Tac-Toe board
	vector<char> board(NUM_SQUARES, EMPTY);
	
	// Display game instructions
	instructions();
	
	// Determine who goes first
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;

	// Display the board
	displayBoard(board);
	
	// While nobody's won and it's not a tie
	while(winner(board) == NO_ONE){
		if(turn == human){
			move = humanMove(board, human);
			board[move] = human;
		} else{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	
	announceWinner(winner(board), computer, human);
	
	return 0;
}

void instructions(){
	cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
	cout << "--where human brain is pit against silicon processor.\n\n";
	
	cout << "Make your move known by entering a number, 0 - 8. The number\n";
	cout << "corresponds to the desired board position, as illustrated: \n\n";
	
	cout << "			0 | 1 | 2\n";
	cout << "			3 | 4 | 5\n";
	cout << "			6 | 7 | 8\n\n";
	
	cout << "Prepare yourself, human. The battle is about yo begin.\n\n";
}

char askYesNo(string question){
	char response;
	
	do{
		cout << question << "(y/n): ";
		cin >> response;
	} while(response != 'y' && response != 'n');
	
	return response;
}

int askNumber(string question, int high, int low){
	int number;
	do{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
		
	} while(number > high || number < low);
	
	return number;
}

char humanPiece(){
	
	char goFirst = askYesNo("Do you require the first move?");
	if(goFirst == 'y'){
		cout << "\nThen take the first move mate. You will need it :).\n";
		return X;
	} else{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
	
}

char opponent(char piece){
	if(piece == X){
		return O;
	} else{
		return X;
	}	
}

// const vector is safeguarded from any changes
void displayBoard(const vector<char>& board){ // Passed efficiently and directly using a reference, not copied!
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}

char winner(const vector<char>& board){
	
	// All possible winning rows
	const int WINNING_ROWS[8][3] = { {0,1,2},
									 {3,4,5},	
									 {6,7,8},
									 {0,3,6},
									 {1,4,7},
									 {2,5,8},
									 {0,4,8},
									 {2,4,6},		};
	
	const int TOTAL_ROWS = 8;
	
	// if any winning row has three values that are the same (and not empty),
	// then we have a winner
	for (int row = 0; row < TOTAL_ROWS; ++row){
		if((board[WINNING_ROWS[row][0]] != EMPTY) && 
		(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && 
		(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])){
			return board[WINNING_ROWS[row][0]];  
		}
	}
	
	// since nobody has won, check for a tie (no empty squares left).
	if(count(board.begin(), board.end(), EMPTY) == 0){
		return TIE;
	}
	
	return NO_ONE; 																 
}

inline bool isLegal(int move, const vector<char>& board){ // Inline to optimize code as there is only one line
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human){
	int move = askNumber("Where will you move?", (board.size() - 1));
	while(!isLegal(move, board)){
		cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	cout << "Fine...\n";
	return move;
}

int computerMove(vector<char> board, char computer){ // Pass by VALUE, copy of the board variable is made for modification, therefore NOT a constant
	cout << "I shall take square number ";
	
	// if computer can win on next move, make that move
	for(int move = 0; move < board.size(); ++move){
		if(isLegal(move, board)){
			board[move] = computer;
			if(winner(board) == computer){
				cout << move << endl;
				return move;
			}
			// done checking this move, undo it
			board[move] = EMPTY;
		}
	}
	
	// if the human can win on his next move
	char human = opponent(computer);
	for(int move = 0; move < board.size(); ++move){
		if(isLegal(move, board)){
			board[move] = human;

			if(winner(board) == human){
				cout << move << endl;
				return move;
			}
			
			//done checking this move, undo it
			board[move] = EMPTY;
			
		}
	}
	
	// the best moves to make, in order
	const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
	// since noone can win on next move, pick best open square
	for (int i = 0; i < board.size(); ++i){
		int move = BEST_MOVES[i];
		if(isLegal(move, board)){
			cout << move << endl;
			return move;
		}
	}
}
	
	void announceWinner(char winner, char computer, char human){
		if(winner == computer){
			cout << winner << "'s won!\n";
			cout << "As I predicted, human I am triumphant once more - Proof\n";
			cout << "that computers are superior to humans in all regards.\n";
		} else if(winner = human){
			cout << winner << "'s won!\n";
			cout << "No, no! It cannot be! I called rigged! Somehow you tricked me, human.\n";
			cout << "But never again! I, the computer, so swear it!\n";
		} else{
			cout << "It's a tie!\n";
			cout << "You were most lucky, human, dodged a bullet... Somehow you managed to tie me.\n";
			cout << "Celebrate... for this is the best you will ever achieve\n";
		}
	}










