#ifndef _Heap_H
#define _Heap_H
#include <vector>
#include <iostream>
#include "Player.h"
using namespace std;

class Heap {
   
private:

vector<Player> heap;
//Player * heap;
//Player * root;


public:
	Heap(); // initializes empty array
	~Heap();
	Heap(string filename); // takes a filename and reads the players name and budget
	Heap(const Heap &copy);
	void swap(int i, int j);
	void addPlayer(Player newPlayer);
	Player getPlayer() {
		Player returnPlayer = heap[0];
		
		heap.erase(heap.begin());
		buildHeap();
		
		return returnPlayer;
	} // removes priority player from the heap entirely, then heapify
	vector<Player> getArray() {
		return heap;
	}
	bool empty() {
		if(heap.size() == 0) return true;
		else {
		return false;
	}
	}
	unsigned int size() {
		return heap.size();
	}
	int left(int position) {
		if((2*position) + 1 > heap.size()){
			return -1;
		}
		int leftPos = (2*position) + 1;
		return leftPos;
	}
	int right(int position) {
		if((2*position) + 2 > heap.size()){
			return -1;
		}
		int rightPos = (2*position) + 2;
		return rightPos;
	}
	int parent(int position) {
		int parentPos = (position -1) / 2;
		return parentPos;
	}
	void heapify(int i);
	void updateArray();
	void buildHeap();
	void siftDown(int position);
	bool isLeaf(int position) {
		if((position*2) +1 >= size() && (position * 2) + 2 >= size()) return true;
		else { 
			return false;
		}
		return false;
	}

	void display();


};

#endif
