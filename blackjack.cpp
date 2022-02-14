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
		enum rank  {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
		enum suit  {CLUBS, DIAMONDS, HEARTS, SPADES};
	
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
		//return value; /// this!
	}
	return value;
	/// correct scope please for 'return'
	/// function none return int!
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

GenericPlayer::GenericPlayer(const string& name): m_Name(name){
	
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

class Player : public GenericPlayer{ 
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

Player::Player(const string& name): GenericPlayer(name){
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
	cout << m_Name << " wins :)\n";
}

void Player::lose() const{
	cout << m_Name << " loses.\n";
}

void Player::push() const{
	cout << m_Name << " pushes (draws).\n";
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

House::House(const string& name): GenericPlayer(name){
	
}

House::~House(){
	
}

bool House::isHitting() const{
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

class Deck : public Hand {
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
	for(int s = Card::CLUBS; s <= Card::SPADES; ++s){
		for(int r = Card::ACE; r <= Card::KING; ++r){
			add(new Card(static_cast<Card::rank>(r),
				static_cast<Card::suit>(s)));
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

/**
---- Game Class ----
**/

class Game{
	public:
		Game(const vector<string>& names);
		
		~Game();
		
		// plays the game of blackjack
		void play();
		
	private:
		Deck m_Deck;
		House m_House;
		vector<Player> m_Players; 
};

Game::Game(const vector<string>& names){
	// create a vector of players from a vector of names
	vector<string>::const_iterator pName;
	for(pName = names.begin(); pName != names.end(); ++pName){
		m_Players.push_back(Player(*pName));
	}
	
	srand(time(0)); // seed the random number generator
	m_Deck.populate();
	m_Deck.shuffle();
}

Game::~Game(){
	
}

void Game::play(){
	// deal initial 2 cards to everyone
	vector<Player>::iterator pPlayer;
	for(int i = 0; i < 2; ++i){
		for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
			m_Deck.deal(*pPlayer);
		}
		m_Deck.deal(m_House);
	}
	
	// hide house's first card
	m_House.flipFirstCard();
	
	//display everyone's hand
	for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;
	
	// deal additional cards to players
	for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
		m_Deck.AdditionalCards(*pPlayer);
	}
	
	// reveal house's first card
	m_House.flipFirstCard();
	cout << m_House << endl;
	
	//deal additional cards to house
	m_Deck.AdditionalCards(m_House);
	
	if(m_House.IsBusted()){
		// everyone still playing wins
		for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
			if(!(pPlayer->IsBusted())){
				if(pPlayer->getTotal() > m_House.getTotal()){
					pPlayer->win();
				} else if(pPlayer->getTotal() < m_House.getTotal()){
					pPlayer->lose();
				} else{
					pPlayer->push();
				}
			}
		}
		
	}
	
	// remove everyone's cards
	for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
		pPlayer->clear();
	}
	m_House.clear();
		
}

int main(){
	cout << "\t\tWelcome to BlackJack!\n\n";
	
	int numPlayers = 0;
	
	while(numPlayers < 1 || numPlayers > 7){
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}
	
	vector<string> names;
	string name;
	
	for(int i = 0; i < numPlayers; ++i){
		cout << "Enter player names: ";
		cin >> name;
		names.push_back(name);
	}
	
	cout << endl;
	
	// the game loop
	Game aGame(names);
	char again = 'y';
	while(again != 'n' && again != 'N'){
		aGame.play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}
	
	
	return 0;
}

// overloads << operator so I can send Card object to the standard output
ostream& operator<<(ostream& os, const Card& aCard){
	const string RANKS[] = {"0", "A", "2","3","4","5","6","7","8","9","10","J","Q","K"};
	const string SUITS[] = {"c","d","h","s"};
	
	if(aCard.m_IsFaceUp){
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	} else{
		os << "XX";
	}
	return os;	
}

// overloads << operator so I can send GenericPlayer object to the standard output
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer){
	os << aGenericPlayer.m_Name << ":\t";
	
	vector<Card*>::const_iterator pCard;
	if(!aGenericPlayer.m_Cards.empty()){
		for(pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard){
			os << *(*pCard) << "\t";
		}
		if(aGenericPlayer.getTotal() != 0){
			cout << "(" << aGenericPlayer.getTotal() << ")";
	}
	} else{
			os << "<empty>";
	}
	
	return os;
	
}











