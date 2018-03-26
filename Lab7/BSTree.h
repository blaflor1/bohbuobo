#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
#include <iostream>
#include <vector>
using namespace std;

class Node {
		//friend class BSTree;
		public:
		Node();
		Node(int i);
		//Node(const Node & old_node);
		//~Node();
		int data;
		Node * parent;
		Node * left;
		Node * right;
		void setLeft(Node * n);
		void setRight(Node * n);
		void setParent(Node * n);
		void setRightNull() {
			right = NULL;
		}
		void setLeftNull() {
			left = NULL;
		}
		void setParentNull() {
			parent = NULL;
		}

		void setData(int i) {
			data = i;
		}
		
		int getData(){
			return data;
		}

		Node * getRight();
		Node * getLeft();
		Node * getParent();
	};


class BSTree {
	//class Node;
	//friend class Node;
private:
	

	Node * root;

public:

	BSTree();
	~BSTree();	
	bool empty();
	Node * getRoot() {
		return root;
	}
	bool insert(int val);

	void insertAdd();
	void inOrder(Node * n);
	bool find(int val);
	bool remove(int num) {
		bool ret_val;
		//if(root->getData() == num) {
		//	cout << "Root is to be deleted" << endl;
		//	int test = findMax(root->getLeft());
		//	root->setData(test);
		//	ret_val = true;

		//}
		//else {
		 ret_val = removeNode(num, root);
		
		//}
		return ret_val;
	}
	bool removeNode(int num, Node * n);
	int findMax(Node * n);
	int findMin(Node * n);
	void copyConstructor(Node * n);
	void sortedArray(vector<int> &list);
	void deleteTree(Node *n);
	void sortedArrayNode(Node * n, vector<int> &list);
	BSTree(const BSTree &old_tree);
	void display();
	//void inOrder(Node * n);
	



};

#endif