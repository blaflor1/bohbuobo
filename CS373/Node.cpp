#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include "Node.h"
using namespace std;

bool Node::inAdjList(int nodeName, string inputNum) {
	bool ret_val = false;
	for (int i = 0; i < adjList.size(); i++)  {
		if(adjList[i].first == nodeName && adjList[i].second == inputNum) {
			ret_val = true;
			break;
		}
	}
	return ret_val;
}

void Node::addAdj(int n, string inputNum) {
	if (adjList.empty())
	{   pair<int, string> foo(n, inputNum);
		adjList.push_back(foo);
	}
	else {
		if(!(this->inAdjList(n, inputNum))) {
			pair<int, string> foo(n, inputNum);
		    adjList.push_back(foo);
		}
	}

}

void Node::printNode() {
	if(accept == true) {
		cout << "Accept "; 
	}
	if(start == true) {
		cout << " Start ";
	}
	cout << "ID Num: " << id << " with adjacencies " << "\n";
	for (int i = 0; i < adjList.size(); i++)
	{
		cout << "node num: " << adjList[i].first <<" with input " << adjList[i].second << "\n";
	}
}