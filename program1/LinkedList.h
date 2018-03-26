#ifndef _LinkedList_H
#define _LinkedList_H
#include "Ant.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class Node;
class LinkedList;
class Node {
private:
	
	
	

public:
	Ant data;
	Node * next;
	Node();
	Node(const Node & n);
	Node(Ant * a);
	void setNext(Node * a) {
		next = a;
	}
	void setData(Ant a){
		data = a;
	}
	Ant getData() {
		return data;
	}
	//get(int id);
	Node * getNext() {
		return next;
	}


};
//for(temp = head; temp->next != NULL; temp = temp->next);
class LinkedList {
private:
	Node * head;
public:

	LinkedList();
	~LinkedList();
	void display();
	LinkedList(const LinkedList & list);
	void insert(Ant * a);
	void insertNode(Node * n);
	void operator<<(Ant * a);
	//Node getNodeID(int ID);
	bool getNode(int id);
	bool remove(int ID);
	Node * getHead() {
		return head;
	}
};

#endif