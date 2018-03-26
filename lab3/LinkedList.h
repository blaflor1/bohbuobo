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
	Ant * next;
	Ant * data;
	

public:
	Node(Ant * a);
	bool setNext(Ant * a);

};
//for(temp = head; temp->next != NULL; temp = temp->next);
class LinkedList {
	void insert(Ant * insert_ant);

	Node getNode(int ID);
	bool remove(int ID);
}