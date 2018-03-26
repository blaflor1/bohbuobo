	#include "Card.h"
	#include <iostream>
	using namespace std;


	Card::Card(int s, int v) {
		suit = s;
		value = v;
	}

	Card::Card() {
		suit = 1;
		value = 1;
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

	bool Card::operator>(const Card &other) {
		bool greater = false;
		if(value > other.value) greater = true;
		else if(value == other.value) {
			if(suit > other.suit) greater = true;
		}
		return greater;
	}

	bool Card::operator<(const Card &other) {
		bool lesser = false;
		if(value < other.value) lesser = true;
		else if(value == other.value) {
			if(suit < other.suit) lesser = true;

		}
		return lesser;
	}

	void Card::display() {
		cout << "Suit: " << suit << "Value: " << value << endl;
	}
