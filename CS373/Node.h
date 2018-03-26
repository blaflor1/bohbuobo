#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#ifndef _Node_H
#define _Node_H

using namespace std;

class Node
{
public:
	Node() {
		start = 0;
		accept = 0;
		id = -1;

	}
	//~Node();
	Node(bool acc, bool st, int idNum) {
		accept = acc;
		start = st;
		id = idNum;
	}
	Node(int idNum) {
		accept = false;
		start = false;
		id = idNum;
	}
	
	bool start;
	bool accept;
	int id;
	deque<pair<int, string>> adjList;
	void addAdj(int n, string inputNum);
	bool inAdjList( int nodeName, string inputNum);
	void printNode();
};

#endif