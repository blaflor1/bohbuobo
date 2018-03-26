#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include <algorithm>
#include "Node.h"
#ifndef _Project2_H
#define _Project2_H
using namespace std;


class Project2 {
public: 
	Project2() {
		size = 0;
		optimal_size = 0;
		visited = 0;
		leaf_nodes = 0;
		capacity = 0;
	}
	int size;
	int capacity;
	int optimal_size;
	int visited;
	int leaf_nodes;
	deque<Item> items_visited;
	deque<Item> solution;
	deque<Item> item_list;	
	float bound(Node start, deque<Item> item_graph);
	deque<Item> createPriorityQueue(vector<Item> unsorted_vec);
	int knapsack01(deque<Item> items_list, int depth); 
};
#endif