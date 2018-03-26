#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>
#ifndef _Node_H
#define _Node_H
using namespace std;

class Item {
public:
	float weight;
	int amount;
	Item(float w, int a) {
		weight = w;
		amount = a;
	}
	Item();
	float getWeight() {
		return weight;
	}
	int getAmount() {
		return amount;
	}
	
};

class Node {
public:
	Node(){
		depth = 0;
		profit = 0;
		bound = 0;
		weight = 0;
		ratio = 0;

	}
	//Node(int d, int p, float w)
	int depth;
	int profit;
	float bound;
	deque<Item> included_items;
	float weight;
	double ratio;
	void addItem(Item i) {
		included_items.push_front(i);
	}
	int getDepth() {
		return depth;
	}
	int getProfit() {
		return profit;
	}
	int getBound() {
		return bound;
	}
	float getWeight() {
		return weight;
	}
	
};


#endif