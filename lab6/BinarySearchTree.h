#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
#include <iostream>

class BinarySearchTree {
private:
	Node * root;

public:
	BSTree();
	bool empty();
	bool insert(int val);
	bool find(int val);

}