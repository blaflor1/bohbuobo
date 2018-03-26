#include "Deck.h"
//#include iostream;
using namespace std;

Deck::Deck() {
	for (int i = 1; i < 5; i++)
	{
		for (int j = 2; j < 15 ; j++)
		{
			Card * add_card = new Card(i, j);
			add_card->display();
			card_deck.enqueue(add_card);
		}
	}
}

Card  Deck::draw() {
	//Card temp = card_deck.peek();
	return *(card_deck.dequeue());
}

bool Deck::empty() {
	bool ret_val = card_deck.empty();
	return ret_val;
}