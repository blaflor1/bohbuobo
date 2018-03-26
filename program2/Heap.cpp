

#include "Heap.h"
#include "Player.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

Heap::Heap() {
	//heap;

}

Heap::~Heap() {
	
}

void Heap::display() {
		for(vector<Player>::iterator it = heap.begin(); it != heap.end(); it++) {
			cout << "Player name: " << it->getName() << "  Money: " << it->getBudget() << endl;

		}
	}

Heap::Heap(const Heap &copy) {
	vector<Player> newHeap = copy.heap;
	for(vector<Player>::iterator it = newHeap.begin(); it != newHeap.end(); it++) {
		Player * add_play = new Player(it->getName(), it->getBudget());
		addPlayer(*add_play);
		delete add_play;
	}




}

Heap::Heap(string filename) {
	ifstream myfile;
	myfile.open(filename.c_str());
	stringstream ss;
	string test;
	string test2;
	int i = 0;
	if(!myfile.is_open()) {
		return;
	}
	while(getline(myfile, test, '\n')) {
		stringstream stream(test);
		string check;
		stream >> check;
		//cout << "Printing test string: " << check << endl;
		getline(myfile, test2, '\n');
		stringstream ss(test2);
		int test1;
		ss >> test1;
		//cout << "Check: " << test1 << endl;
		Player add_play(check, test1);
		addPlayer(add_play);
		
		

	}
    myfile.close();

}


//void updateArray() {
//	Player *new_array = new Player[array.size()];
//	int i = 0;
//	for(vector<Player>::iterator it = array.begin(); it != array.end(); it++){
//		new_array[i] = *it;
//		i++;
//	}
//	heap = new_array;
//}

void Heap::buildHeap() {
	int n = heap.size();
	for(int i = (n-1); i>=0; i--) {
		this->heapify(i);
	}
}



void Heap::siftDown(int position) {
	if(position < 0 || position >= heap.size()) return;
	while(!this->isLeaf(position)){
		int j = this->left(position); //Write Code to return left children of heap		if((j+1) < array.size() && (array[j] < array[j+1])) j++;
		if(heap[position].getBudget() > heap[j].getBudget()) return;
		this->swap(position, j);
		position = j;
	}
}


 void Heap::heapify(int position) {
 	 int larger;
 	 int leftChild;
 	 int rightChild;
 	 Player temp = heap[position];
 	leftChild = left(position);
 	rightChild = right(position);
 	larger = position;
 	if(leftChild < heap.size() && heap[leftChild].getBudget() > heap[larger].getBudget()) {
 		larger = leftChild;
 	}
 	if(rightChild < heap.size() && heap[rightChild].getBudget() > heap[larger].getBudget()) {
 		larger = rightChild;
 	}
 	if(larger != position) {
 		//temp = heap[position];
 		heap[position] = heap[larger];
 		heap[larger] = temp;
 		heapify(larger);

 	}



 }
 void Heap::swap(int i, int j) {
 	Player temp = heap[i];
 	heap[i] = heap[j];
 	heap[j] = temp;
 	return;

 }



void Heap::addPlayer(Player newPlayer) {

	heap.push_back(newPlayer);
	buildHeap();
	//updateArray();

}
