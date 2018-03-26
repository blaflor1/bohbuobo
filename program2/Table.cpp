#include <vector>
#include <iostream>
#include <string>
#include "Table.h"
#include "Deck.h"
#include "Heap.h"
#include "Player.h"
#include <algorithm>

using namespace std;

Table::Table(int num_seats, int ante1) {
	max_seats = num_seats;
	ante = ante1;
	string j = "juan";
	int x = 10;
	Player juan(j, x);
	winner.push_back(juan);
	

	
}

Table::~Table() {

}

bool Table::emptySeat() {
	bool ret_val = false;
	if(players.size() < max_seats) ret_val = true;
	return ret_val;
}

void Table::addPlayer(Player p){
	players.push_back(p);
}

void Table::printWinner() {
	cout << "Winner is: " << winner[0].getName() << " with: $" << winner[0].getBudget() << endl;

}

vector<Player> Table::playRound() {
	random_shuffle(playingDeck.card_deck.begin(), playingDeck.card_deck.end());
	int i = 0;
	//if(players.size() == 0) { 
	//	return players;
	//}
	for(vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
		bool play = it->bet(ante);
			
		it->hand = playingDeck.draw();
			

	}
	//if(players.size() == 0) { 
	//	return players;
	//}
	
	winnings = ante * (players.size());
		
	
	int largestIndex = 0;
	for(int j = 0; j < players.size(); j++) {
		if(players[largestIndex].hand < players[j].hand) largestIndex = j;
	}
	//cout << "largestIndex = " << largestIndex << endl;
	//cout << "Winners money: " << players[largestIndex].getBudget() << endl;
	//cout << "Winnings: " << winnings << endl;
	players[largestIndex].collectWinnings(winnings);
	//cout << "Winners money: " << players[largestIndex].getBudget() << endl;
	vector<Player> losers;
	for(int x = 0; x < largestIndex; x++) {
		losers.push_back(players[x]);
	//	cout << "Losers name: " << players[x].getName() << endl;
	//	cout << "losers amount: " << players[x].getBudget() << endl;
	}
	for(int z = largestIndex+1; z < players.size(); z++) {
		losers.push_back(players[z]);
	//	cout << "Losers name: " << players[z].getName() << endl;
	//	cout << "losers amount: " << players[z].getBudget() << endl;
	}
	
	Deck new_deck;
	playingDeck = new_deck;
	
	Player newWinner = players[largestIndex];
	players.clear();
	players.push_back(newWinner);
	winner.clear();
	winner.push_back(newWinner);
	//winner = &newWinner;
	//printWinner();
	
	winnings = 0;
	//cout << "End of function play round" << endl;
	return losers;
	}



