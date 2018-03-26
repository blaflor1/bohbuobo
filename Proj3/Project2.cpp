#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <sstream>
#include <algorithm>
#include "Node.h"
#include "Project2.h"

using namespace std;

struct mycomparison {
	bool operator() (const Node& node1, const Node& node2) {
		return node2.bound > node1.bound;
	}
};
//Make tree (probably array form?) of graph... then use priority queue method to find

float Project2::bound(Node start,  deque<Item> item_graph)  {
    float find_bound = 0;
    if (start.weight >= this->capacity) {
        return 0;
    }
    else {
    
    find_bound = start.profit;
    int item_index = start.depth + 1;
    int total_weight = start.weight;
    int check_weight = total_weight + item_graph[item_index].weight;
    while ((item_index < this->size) && (check_weight <= this->capacity))  {
        total_weight += item_graph[item_index].weight;
        find_bound += item_graph[item_index].amount;
        item_index++;
    }
    if (item_index < this->size) {
    	float ratio = (item_graph[item_index].amount) / (item_graph[item_index].weight);
        find_bound = find_bound + (this->capacity - total_weight) * ratio;
    }
   }
 
    return find_bound;
}

deque<Item> Project2::createPriorityQueue(vector<Item> unsorted_vec) {
	deque<Item> priority;
	deque<float> ratios;
	//sort(unsorted_vec.rbegin(), unsorted_vec.rend());
	int max = 0;
	for (int i = 0; i < unsorted_vec.size(); ++i)
	{	
		if(i = 0) {
			priority.push_back(unsorted_vec[i]);
			ratios.push_back((float)unsorted_vec[i].weight/unsorted_vec[i].amount);

		}
		else {
			if((unsorted_vec[i].weight/unsorted_vec[i].amount) > (unsorted_vec[max].weight/unsorted_vec[max].amount)) {
				ratios.push_front(unsorted_vec[i].weight/unsorted_vec[i].amount);
				i = max;
			}
			else {
				ratios.push_back((float)unsorted_vec[i].weight/unsorted_vec[i].amount);
			}
		}
	}
	sort(ratios.rbegin(), ratios.rend());
	for (int i = ratios.size() - 1; i >= 0; ++i)
	{
		for(int j = 0; j < unsorted_vec.size(); j++) {
			if(ratios[i] == ((float)unsorted_vec[j].weight/unsorted_vec[j].amount)) {
				priority.push_front(unsorted_vec[j]);
			}
		}
	}
	
	return priority;
}

int Project2::knapsack01(deque<Item> items_list, int depth)  {
    //for (int i = 0; i < items.length; ++i)
    //{
    	
    //}
 	
 	// = createPriorityQueue(items_list);
   
    priority_queue<Node, vector<Node>, mycomparison> PQ;
    deque<Item> solutions;
    Node x; 
    Node y;
    x.depth = -1;
    x.bound = bound(x, items_list);
    PQ.push(x);
    int best_profit = 0;
    while (!PQ.empty())  {
        x = PQ.top();
        PQ.pop();
        if(x.bound > best_profit) {
	        if (x.depth < 0){
	            y.depth = x.depth + 1;
	        }      
	        else if (x.depth == (depth - 1)) {
	        	this->leaf_nodes++;
	        }
	        y.depth = x.depth + 1;
	        y.profit = x.profit + items_list[y.depth].amount;
	        y.weight = x.weight + items_list[y.depth].weight;
	        this->visited++;
	        y.included_items = x.included_items;
	        y.addItem(items_list[y.depth]);
	        if (y.weight <= this->capacity && y.profit > best_profit) {
	            best_profit = y.profit;
	            this->solution = y.included_items;
	        }
	        y.bound = bound(y, items_list);
	        if (y.bound > best_profit){
	            PQ.push(y);
	        } 
	        else {
	        	this->leaf_nodes++;
	        }
	        y.profit = x.profit;
	        y.weight = x.weight;
	        y.bound = bound(y, items_list);
	        this->visited++;
	        y.included_items = x.included_items;
	        if (y.bound > best_profit){
	            PQ.push(y);
	        } else {
	        	this->leaf_nodes++;
	        }
        }
        else {
        	this->leaf_nodes++;
        }
    }
 	this->visited = this->visited + 1;
    return best_profit;
}



