#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include "Node.h"
#ifndef _NFA_H
#define _NFA_H


using namespace std;



class NFA
{
public:
	//NFA();
	//~NFA();
	deque<Node> nodeList;
	deque<Node> startList;
	deque<Node> acceptList;
	deque<int> acceptedEndStates;
	deque<int> rejectedEndStates;
	bool inputAccepted = false;
	void addNode(Node n);
	bool inList(int nodeId);
	bool inStartList(int nodeId);
	bool inAccList(int nodeId);
	int findNode(int nodeId);
	void printAutomata();
	void execute(string inputNum);
	void updateNodes();
	void printResults(); 
	void explore(Node n, deque<string> input);
};
#endif