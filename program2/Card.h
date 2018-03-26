#ifndef _Card_H
#define _Card_H
class Card;
#include <iostream>





class Card {
private:
	int suit;
	int value;
public:
	Card(int s, int v);
	Card();
	int getValue();
	int getSuit();
	bool operator==(const Card &other);
	bool operator!=(const Card &other);
	void display();
	bool operator<(const Card &other);
	bool operator>(const Card &other);
	//friend ostream & operator<<(ostream &out, const Card &other);
};
#endif