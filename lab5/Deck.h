#ifndef _Deck_H
#define _Deck_H
class Deck;
#include "Card.h"
#include "Queue.h"




class Deck {
private:
	Queue<Card*> card_deck;

public:
	Deck();
	Card draw();
	bool empty();
};
#endif