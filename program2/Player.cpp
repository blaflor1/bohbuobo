#include "Player.h"
#include "Card.h"
#include <iostream>
#include <string>
using namespace std;


Player::Player(string n, int budget) {

	name = n;
	money = budget;
	Card hand;
   

}


Player::~Player() {
	
}

Player::Player(const Player &other) {
	name = other.name;
	money = other.money;
	hand = other.hand;

}

int Player::getBudget() {
   return money;

}

void Player::setName(string s) {
	name = s;
}

bool Player::bet(int amount) {
	bool ret_val = false;
	if(money > amount) {
		money -= amount;
		ret_val = true;
	}
	return ret_val;
}

void Player::collectWinnings(int amount) {
	money += amount;
}
