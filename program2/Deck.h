#ifndef _Deck_H
#define _Deck_H
class Deck;
#include "Card.h"
#include <vector>




class Deck {
private:
	

public:
	std::vector<Card> card_deck;
	Deck();
	void shuffle();
	Card draw();
	bool empty();
	void display();
};
#endif