#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include "Node.h"
#include "Project2.h"
using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2, test;
	string full_text;
	ifstream readfile;
	readfile.open(argv[1]);
	ofstream myfile;
	myfile.open(argv[2]);
 	
 	if(!readfile.is_open()) {
		return -1;
	}
	int count = 0;
	int cap;
	int probSize;
	int test_int;
	deque<Item> item_list;
	Project2 test_proj;
	while(getline(readfile, full_text)) {
		int index = full_text.find_first_of(',');
		string first_num = full_text.substr(0, index);
		string second_num = full_text.substr(index+1);
		if(count == 0) {
			count++;
			stringstream convertSize(first_num);
			stringstream convertCapacity(second_num);
			int z, b;
			convertSize >> z;
			convertCapacity >> b;
			test_proj.size = z;
			test_proj.capacity = b;

		}
		else {
			stringstream convertWeight(first_num);
			stringstream convertProfit(second_num);
			int v, u;
			convertWeight >> v;
			convertProfit >> u;
			//cout << "v: " << v << "\n";	
			//cout << "u: " << u << "\n";
			count++;
			Item i(v, u);
			item_list.push_back(i);
		}
	
	}
	//cout << "out of loop!!! " << "\n";
	//test_proj.size = probSize;
	int optimal = test_proj.knapsack01(item_list, probSize);
	myfile << item_list.size();
	myfile << ",";
	myfile << optimal;
	myfile <<",";
	myfile << test_proj.solution.size();
	myfile << "\n";
	myfile << test_proj.visited;
	myfile << ",";
	myfile << test_proj.leaf_nodes;
	myfile << "\n";
	for (int i = 0; i < test_proj.solution.size(); ++i)
	{
		myfile << test_proj.solution[i].weight;
		myfile << ",";
		myfile << test_proj.solution[i].amount;
		myfile << "\n";
	}
	readfile.close();
	myfile.close();

	return 0;
}