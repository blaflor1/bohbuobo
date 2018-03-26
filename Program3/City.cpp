#include "City.h"
#include <vector>
#include <list>
using namespace std;

City::City(string c, int x, int y ) {
	cityName = c;
	xCoor = x;
	yCoor = y;
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

void City::display() {
	cout << cityName << " with adjs of: " << endl;
	for(int i = 0; i < adjList.size(); i++) {
		cout << " " << adjList[i]->getName() << " x: " << adjList[i]->getXCoor() << " y: " << adjList[i]->getYCoor()<< endl;
	}
}

void City::displayPairs() {
	cout << cityName << " with adjs of: " << endl;
	for(int i = 0; i < pairList.size(); i++) {
		cout << " " << pairList[i].first->getName() << " distance: " << pairList[i].second << endl;
	}
}


City::~City() {

	delete north;
	delete south;
	delete east;
	delete west;

}

void City::calculateDistances() {
	for (int i = 0; i < adjList.size(); ++i)
	{
		int dist;
		if(getYCoor() == adjList[i]->getYCoor()) {

			dist = getXCoor() - (adjList[i]->getXCoor());
			if(dist < 0) dist = dist * -1; 
			//cout << dist << endl;
			pair<City*, int> newPair(adjList[i], dist);
			pairList.push_back(newPair);
		} 
		else if(getXCoor()==adjList[i]->getXCoor()) {
			dist = getYCoor() - (adjList[i]->getYCoor());
			if(dist < 0) dist = dist * -1; 
			//cout << dist << endl;
			pair<City*, int> newPair(adjList[i], dist);
			pairList.push_back(newPair);
		}
	}
}

bool City::isAdj(City* c) {
	bool ret_val = false;
	for(int i = 0; i < adjList.size(); i++) {
		if(adjList[i]->getName() == c->getName()) {
			return true;
		}
	}
	return ret_val;
}

void City::removeAdj(string name) {
	for(int i = 0; i<adjList.size(); i++) {
		if(adjList[i]->getName() == name) {
			adjList.erase(adjList.begin() + i);
		}
	}
}


void City::correctAdjXN() {
	vector<City*> removeVec;
	for(int i = 0; i <adjList.size(); i++) {
		if(getXCoor() == adjList[i]->getXCoor() && getYCoor() < adjList[i]->getYCoor()) {
			removeVec.push_back(adjList[i]);
		}
	}
	if(removeVec.size() == 0 || removeVec.size() == 1) return;
	vector<City*> correctVec;
	int smallest = removeVec[0]->getYCoor() - getYCoor();
	int small_index = 0;
	for (int i = 0; i < removeVec.size(); i++)
	{	int small_compare = removeVec[i]->getYCoor() - getYCoor();
		if(small_compare < smallest) {
			smallest = small_compare;
			small_index = i;
		}
	}
	//pair<City*,int> add_pair(removeVec[small_index], smallest); 
	//pairList.push_back(add_pair);
	removeVec.erase(removeVec.begin() + small_index);
	for (int i = 0; i < removeVec.size(); ++i)
	{
		removeAdj(removeVec[i]->getName());
	}

}

void City::correctAdjXS() {
	vector<City*> removeVec;
	for(int i = 0; i < adjList.size(); i++) {
		if(getXCoor() == adjList[i]->getXCoor() && getYCoor() > adjList[i]->getYCoor()) {
			removeVec.push_back(adjList[i]);
		}
	}
	if(removeVec.size() == 0 || removeVec.size() == 1) return;
	
	//vector<string> 
	int smallest = getYCoor() - (removeVec[0]->getYCoor());
	int small_index = 0;
	for (int i = 0; i < removeVec.size(); i++)
	{	int small_compare = getYCoor() - (removeVec[i]->getYCoor());
		if(small_compare < smallest) {
			smallest = small_compare;
			small_index = i;
		}

	}
	//pair<City*,int> add_pair(removeVec[small_index], smallest); 
	//pairList.push_back(add_pair);
	removeVec.erase(removeVec.begin() + small_index);
	for (int i = 0; i < removeVec.size(); ++i)
	{
		removeAdj(removeVec[i]->getName());
	}
	
	
}

void City::correctAdjYW() {
	vector<City*> removeVec;
	for(int i = 0; i <adjList.size(); i++) {
		if(getYCoor() == adjList[i]->getYCoor() && getXCoor() > adjList[i]->getXCoor()) {
			removeVec.push_back(adjList[i]);
		}
	}
	if(removeVec.size() == 0 || removeVec.size() == 1) return;
	
	unsigned int smallest = (removeVec[0]->getXCoor()) - getXCoor();
	int small_index = 0;
	for (int i = 0; i < removeVec.size(); i++)
	{	unsigned int small_compare = getXCoor() - (removeVec[i]->getXCoor());
		if(small_compare < smallest) {
			smallest = small_compare;
			small_index = i;
		}
	}
	//pair<City*,int> add_pair(removeVec[small_index], smallest); 
	//pairList.push_back(add_pair);
	removeVec.erase(removeVec.begin() + small_index);
	for (int i = 0; i < removeVec.size(); ++i)
	{
		removeAdj(removeVec[i]->getName());
	}
	
}

void City::correctAdjYE() {
	vector<City*> removeVec;
	for(int i = 0; i < adjList.size(); i++) {
		if(getYCoor() == adjList[i]->getYCoor() && getXCoor() < adjList[i]->getXCoor()) {
			removeVec.push_back(adjList[i]);
		}
	}
	if(removeVec.size() == 0 || removeVec.size() == 1) return;
	vector<City*> correctVec;
	int smallest = removeVec[0]->getXCoor() - getXCoor();
	int small_index = 0;
	for (int i = 0; i < removeVec.size(); i++)
	{	int small_compare = removeVec[i]->getXCoor() - getXCoor();
		if(small_compare < smallest) {
			smallest = small_compare;
			small_index = i;
		}
	}
	//pair<City*,int> add_pair(removeVec[small_index], smallest); 
	//pairList.push_back(add_pair);
	removeVec.erase(removeVec.begin() + small_index);
	for (int i = 0; i < removeVec.size(); ++i)
	{
		removeAdj(removeVec[i]->getName());
	}

}



