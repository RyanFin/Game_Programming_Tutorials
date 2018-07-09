// Blackjack
// plays a simple version of the casino game of blackjack; for 1 - 7 players

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card{
	public:
		enum rank = {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
		enum suit = {CLUBS, DIAMONDS, HEARTS, SPADES};
	
	// overloading << operator so can send Card object to standard output
	friend ostream& operator<<(ostream& os, const Card& aCard);
	
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	
	// returns the value of a card, 1 - 11
	int getValue() const;
	
	// flips a card; if face up, becomes face down and vice versa
	void flip();
	
	private:
		rank m_Rank;
		suit m_Suit;
		bool m_IsFaceUp;
	
};

Card::Card(rank r, suit s, bool ifu){
	m_Rank = r;
	m_Suit = s;
	m_IsFaceUp = ifu;
}

int Card::getValue() const{
	// if a card is face down, its value is 0
	int value = 0;
	if(m_IsFaceUp){
		// value is number showing on card
		value = m_Rank;
		// value is 10 for face cards
		if(value > 10){
			value = 10;
		}
		return value;
	}
}

void Card::flip(){
	m_IsFaceUp = !(m_IsFaceUp);
}
