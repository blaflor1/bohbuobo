	#include "Card.h"
	#include <iostream>
	using namespace std;


	Card::Card(int s, int v) {
		suit = s;
		value = v;
	}

	int Card::getValue() {
		return value;
	}
	int Card::getSuit() {
		return suit;
	}
	bool Card::operator==(const Card &other) {
		bool equal = false;
		if(suit == other.suit && value == other.value) equal = true;
		return equal;
	}

	bool Card::operator!=(const Card &other ) {
		bool equal = true;
		if(suit != other.suit || value != other.value) equal = false;
		return equal;
	}

	void Card::display() {
		cout << "Suit: " << suit << "Value: " << value << endl;
	}
