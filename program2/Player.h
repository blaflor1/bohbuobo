#ifndef _Player_H
#define _Player_H
#include "Player.h"
#include "Card.h"
#include <iostream>

using namespace std;

class Player {

private:
	string name;
	int money;
   


public:
   //Card hand;
   Card hand;
   ~Player();
   Player(string name, int budget);
   string getName() {
      return name;
   }
   Player(const Player &other);
   bool bet(int amount);
   void collectWinnings(int amount);
   //void setMoney(int amount);
   void setName(string s);
   int getBudget();
   //Player * getLeft() {
     // return left;
   //}
   //Player * getRight() {
     // return right;
   //}
   //Player * getParent() {
    //  return parent;
   //}
   void setMoney(int s) {
      money = s;
   }




  

};

#endif
