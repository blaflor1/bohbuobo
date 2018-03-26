#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include "NFA.h"
using namespace std;

int main(int argc, char const *argv[])
{
	string full_text;
	ifstream inputFile;
	//cout << argc << "\n";
	if (argc > 3)
	{	cout << "U F'd Up!!!" << "\n";
		return -1;
	}
	inputFile.open(argv[1]);
	string inputString = argv[2];
	NFA automata;
	while(getline(inputFile, full_text)) {
		int count = 0;
		int id;
		int id2;
		string inputNum;
		bool start = false;
		bool accept = false;
		stringstream ss(full_text);
		string placeHolder;
		ss >> placeHolder;
		string realVals;
		while(ss >> realVals) {
			if(count == 0) {
				if(placeHolder == "state") {
					stringstream convertId(realVals);
					convertId >> id;
				}
				else if(placeHolder == "transition") {
					stringstream convertId(realVals);
					convertId >> id;
				}
				count++;
			}
			else if(count > 0) {
				if (placeHolder == "state")  {
					if(realVals == "start") {
					  start = true;
					}
					else if(realVals == "accept") {
                      accept = true;
					}
					else if(realVals == "acceptstart") {
						accept = true;
						start = true;
					}
				}
				else if(placeHolder == "transition") {
					if(count == 1) {
						stringstream convertInput(realVals);
						convertInput >> inputNum;
					}
					else if(count == 2) {
						stringstream convertId2(realVals);
						convertId2 >> id2;
					}
				}
				count++;
			}	
		}
		Node nodeToAdd(accept, start, id);
		if(placeHolder == "state") {
			if(!(automata.inList(nodeToAdd.id))) {
				automata.addNode(nodeToAdd);
				if (nodeToAdd.accept == true) automata.acceptList.push_back(nodeToAdd);
				if(nodeToAdd.start == true) automata.startList.push_back(nodeToAdd);
			}
		}
		else if(placeHolder == "transition") {
          Node nodeToAdd2(id);

          if ((automata.inList(id)) == false)
          {
          	//cout << "in if" << " ID Num before add " << id << " " << nodeToAdd2.id << "\n";

            pair<int, string> adjNode(id2, inputNum);
            nodeToAdd2.addAdj(id2, inputNum);
            automata.addNode(nodeToAdd2);

          }
          else if(automata.inList(nodeToAdd2.id) == true) {
          	//cout << "in else if" << "\n";
          	int index = automata.findNode(nodeToAdd2.id);
          	if(automata.nodeList[index].inAdjList(id2, inputNum) == false) {
          		automata.nodeList[index].addAdj(id2, inputNum);
          	}
          }
		}
	}
	automata.updateNodes();
	//automata.printAutomata();
	automata.execute(inputString);
	automata.printResults();
	return 0;
}