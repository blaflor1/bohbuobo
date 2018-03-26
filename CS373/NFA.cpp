#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include "NFA.h"
using namespace std;




void NFA::addNode(Node n) {
	if (nodeList.empty())
	{
		nodeList.push_back(n);
	}
	else {
		if(!(this->inList(n.id))) {
			nodeList.push_back(n);
		}
	}
}

bool NFA::inList(int nodeId) {
	bool ret_val = false;
	for (int i = 0; i < nodeList.size(); i++)  {
		if(nodeList[i].id == nodeId) {
			//cout << "printing node id: " << nodeList[i].id << "\n";
			ret_val = true;
			break;
		}
	}
	return ret_val;
}

int NFA::findNode(int nodeId) {
	int ret_val = -1;
	for (int i = 0; i < nodeList.size(); i++)  {
		if(nodeList[i].id == nodeId) {
			ret_val = i;
			break;
		}
	}
	return ret_val;
}

bool NFA::inStartList(int nodeId) {
	bool ret_val = false;
	for (int i = 0; i < startList.size(); i++)  {
		if(startList[i].id == nodeId) {
			ret_val = true;
			break;
		}
	}
	return ret_val;
}

bool NFA::inAccList(int nodeId) {
	bool ret_val = false;
	for (int i = 0; i < acceptedEndStates.size(); i++)  {
		if(acceptedEndStates[i] == nodeId) {
			ret_val = true;
			break;
		}
	}
	return ret_val;
}

void NFA::printAutomata() {
	for (int i = 0; i < nodeList.size(); i++)
	{
		nodeList[i].printNode();
	}
}

void NFA::updateNodes() {
	for(int i = 0; i < startList.size(); i++){
		for(int j = 0; j < nodeList.size(); j++) {
			if(startList[i].id == nodeList[j].id){
				startList[i] = nodeList[j];
			}
		}
	}
	for(int i = 0; i < acceptList.size(); i++){
	  for(int j = 0; j < nodeList.size(); j++) {
		if(acceptList[i].id == nodeList[j].id){
		  acceptList[i] = nodeList[j];
		}
	  }
	}
}

void NFA::execute(string inputNum) {
	deque<string> inputs;
	for (int i = 0; i < inputNum.length(); i++)
	{	stringstream ss;
		string s;
		ss << inputNum[i];
		ss >> s;
		inputs.push_back(s);
	}
	//inputs.push_back("END")
	//cout << inputs.size() << "\n";
	for (int i = 0; i < startList.size(); i++)  {
		explore(startList[i], inputs);
	}

}

void NFA::explore(Node n, deque<string> input) {
	
	if(input.empty() && n.accept == true) {
		//cout << "Node ID accept = " << n.id << "\n";
		if (inAccList(n.id) == false)
		{
			acceptedEndStates.push_back(n.id);
		}
		
		inputAccepted = true;
		return;
	}
	else if(input.empty() && n.accept == false) {
		//cout << "Node ID reject = " << n.id << "\n";
		rejectedEndStates.push_back(n.id);
		return;
	}
	deque<pair<int, string>> tempList = n.adjList;
	
	for(int j = 0; j < tempList.size(); j++) {
		if (tempList[j].second == input[0]) {
			int index = findNode(tempList[j].first);
			//cout << "aT NODE ID: " << n.id << " with adj Node ID = " << tempList[j].first << " input num " << tempList[j].second << "\n";
			if(!input.empty()) input.pop_front();
			explore(nodeList[index], input);

		}
		
	}
}

void NFA::printResults() {
	if(inputAccepted == true) {
		cout << "accept ";
		for (int i = 0; i < acceptedEndStates.size(); i++)
		{
			cout << acceptedEndStates[i] << " ";
		}
	}
	else if(inputAccepted == false) {
		cout << "reject ";
		for (int i = 0; i < rejectedEndStates.size(); i++)
		{
			cout << rejectedEndStates[i] << " ";
		}
	}
}