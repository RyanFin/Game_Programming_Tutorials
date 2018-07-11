// Blackjack
// plays a simple version of the casino game of blackjack; for 1 - 7 players

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/**
---- Card Class ----
**/

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

/**
---- Hand Class ----
**/

class Hand{
	public:
		Hand();
		
		virtual ~Hand();
		
		// adds a card to the hand
		void add(Card* pCard);
		
		// clears hand of all cards
		void clear();
		
		// gets hand total value, intelligently treats aces as 1 or 11
		int getTotal() const;
		
	protected:
		vector<Card*> m_Cards;
};

Hand::Hand(){
	m_Cards.reserve(7);
}

Hand::~Hand(){
	clear();
}

void Hand::add(Card* pCard){
	m_Cards.push_back(pCard);
}

void Hand::clear(){
	// iterate through the vector, freeing all memory on the heap
	vector<Card*>::iterator iter = m_Cards.begin();
	
	for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
		delete *iter;
		*iter = 0;
	}
	
	// clear vector of points 
	m_Cards.clear();
}

int Hand::getTotal() const{
	// if no cards in hand, return 0
	if(m_Cards.empty()){
		return 0;
	}
	
	// if a first card has a value of 0, then card is face down; return 0
	if(m_Cards[0]->getValue() == 0){
		return 0;
	}
	
	// add up card values, treat each ace as 1
	int total = 0;
	vector<Card*>::const_iterator iter;
	for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
		total += (*iter)->getValue();
	}
	
	// determine if hand contains an ace
	bool containsAce = false;
	for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
		if((*iter)->getValue() == Card::ACE){
			containsAce = true;
		}
	}
	
	// if hand contains ace and total is low enough, treat ace as 11
	if(containsAce && total <= 11){
		// add only 10 since we've already added 1 for the ace
		total += 10;
	}
	
	return total;
}

/**
---- Generic Player Class ----
**/

class GenericPlayer : public Hand{
	
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
	
	public:
		GenericPlayer(const string& name = "");
		
		virtual ~GenericPlayer();
		
		// indicates whether or not generic player wants to keep hitting
		virtual bool isHitting() const = 0; // pure virtual function
		
		//returns whether generic player has busted - has a total greater than 21
		bool IsBusted() const;
		
		// announces that the generic player busts
		void bust() const;
		
	protected:
		string m_Name;
};

GenericPlayer::GenericPlayer(const string& name = ""){
	m_Name = name;
}

GenericPlayer::~GenericPlayer(){
	
}

bool GenericPlayer::IsBusted() const{
	return (getTotal() > 21);
}

void GenericPlayer::bust() const{
	cout << m_Name << " busts.\n";
}

/**
---- Player Class ----
**/

class Player : GenericPlayer{ 
	public:
		Player(const string& name = "");
		
		virtual ~Player();
		
		// returns whether or not the player wants another hit
		virtual bool isHitting() const;
		
		// announces that the Player wins
		void win() const;
		
		// announces that the Player loses
		void lose() const;
		
		// announces that the Player pushes / draws 
		void push() const;
};

Player::Player(const string& name = ""): GenericPlayer(name){
}	

Player::~Player(){
	
}

bool Player::isHitting() const{
	cout << m_Name << ", do you want a hit? (Y/N): \n";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::win() const{
	cout << m_Name << "wins.\n";
}

void Player::lose() const{
	cout << m_Name << "loses.\n";
}

void Player::push() const{
	cout << m_Name << "pushes (draws).\n";
}

/**
---- House Class ----
**/
class House : public GenericPlayer{
	public:
		House(const string& name = "House");
		
		virtual ~House();
		
		// indicates whether house is hitting - will always hit on 16 or less
		virtual bool isHitting() const;
		
		// flips over first card
		void flipFirstCard();
		
};

House::House(const string& name = "House"): GenericPlayer(name){
	
}

House::~House(){
	
}

House::isHitting() const{
	return (getTotal() <= 16);
}

void House::flipFirstCard(){
	if(!(m_Cards.empty())){
		m_Cards[0]->flip();
	} else{
		cout << "No card to flip!\n";
	}
}

/**
---- Deck Class ----
**/

class Deck : public Hand{
	public:
		Deck();
		
		virtual ~Deck();
		
		// create a standard deck of 52 playing cards
		void populate();
		
		// shuffle cards
		void shuffle();
		
		// deal one card to a hand
		void deal(Hand& aHand);
		
		// give additional cards to a generic player
		void AdditionalCards(GenericPlayer& aGenericPlayer);
	
};

Deck::Deck(){
	m_Cards.reserve(52); // reserve memory for 52 spaces, 52 cards.
	populate();
}

Deck::~Deck(){
	
}

void Deck::populate(){
	clear();
	
	// create standard deck 
	for(int s = Card::CLUBS, s <= Card::SPADES, ++s){
		for(int r = Card::ACE; r <= Card::KING; ++r){
			add(new Card(static_cast<Card::rank>(r),static_cast<Card::rank>(s)));
		}	
	}
}

void Deck::shuffle(){
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::deal(Hand& aHand){
	if(!m_Cards.empty()){
		aHand.add(m_Cards.back());
		m_Cards.pop_back();
	} else{
		cout << "Out of cards. Unable to deal.";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer){
	cout << endl;
	//continue to deal a card as long as generic player isn't busted and wants another hit
	while(!(aGenericPlayer.IsBusted()) && aGenericPlayer.isHitting()){
		deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		
		if(aGenericPlayer.IsBusted()){
			aGenericPlayer.bust();
		}
	}
}










