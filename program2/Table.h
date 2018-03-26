#ifndef _Table_H
#define _Table_H
#include <vector>
#include <iostream>
#include <string>
#include "Heap.h"
#include "Deck.h"
#include "Player.h"
using namespace std;

class Table {
private:
	vector<Player> players;



public:
   Deck playingDeck;
   ~Table();
   vector<Player> winner;
   int max_seats;
   int ante;
   int winnings;
   Table(int num_seats, int ante1);
   bool emptySeat();
   vector<Player> playRound();
   void addPlayer(Player p);
   void printWinner();
};
#endif