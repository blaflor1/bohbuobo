#include <iostream>
#include "BSTree.h"
using namespace std;

BSTree::BSTree() {
		root = NULL;
	}

BSTree::BSTree(const BSTree &old_tree) {
	if(old_tree.root == NULL) {
		root = NULL;
		return;
	}
	else {
		root = NULL;
		Node * temp = old_tree.root;
		//BSTree copy = old_tree;
		//Node * temp = copy.root;
		//cout << "printing data of root: " << old_tree.root->getData() << endl; 
		//root = new Node(old_tree.root->getData());
		copyConstructor(temp);
		//temp = temp->getLeft();
		//temp2 = root;
		
	}

}



void BSTree::copyConstructor(Node * n) {
	if(n == NULL) return;
	//cout << "in copy copyConstructor" << endl;
	if(n->getData() == 0) {
		//cout << "Found 0" << endl;
	}
	insert(n->getData());
	copyConstructor(n->getLeft());
	copyConstructor(n->getRight());
}

BSTree::~BSTree() {
		//cout << "in destructor" << endl;
		deleteTree(root);
		
		//delete root;
	
	
}

void BSTree::deleteTree(Node * n) {
	if(n == NULL) return;
	//cout << "in delete" << endl;
	deleteTree(n->getLeft());
	deleteTree(n->getRight());
	delete n;
	
}




bool BSTree::empty() {
	bool ret_val = false;
	if(root == NULL) ret_val = true;
	return ret_val;

}



bool BSTree::find(int val) {
	Node * temp = root;
	bool ret_val = false;
	while(temp != NULL) {
		//cout << "In while loop" << endl;
		if (temp->getData() == val) {
			ret_val = true;
			return ret_val;
		}
		else if(val < temp->getData()) {
			temp = temp->getLeft();
		}
		else {
			temp = temp->getRight();
		}
	}
	return ret_val;

}



bool BSTree::insert(int val) {
		bool ret_val;
		Node * temp = root;
		if(temp == NULL) {
			root = new Node(val);
			ret_val = true;
			return ret_val;
}
	else {
		while(temp != NULL) {
		if(temp->getData() > val ) { 
			ret_val = true; // Adding lesser value, add left
			if(temp->getLeft() == NULL) {
				Node * addNode = new Node(val);
				addNode->setParent(temp);
				temp->setLeft(addNode);

			}

			else {
				temp = temp->getLeft();
			}
		}




		else if(temp->getData() < val) {
			ret_val = true;
			if(temp->getRight() == NULL) {
				Node * addRightNode = new Node(val);
				addRightNode->setParent(temp);
				temp->setRight(addRightNode);
			}
			else {
				temp = temp->getRight();
			}
		}
		else {
			ret_val = false;
			return ret_val;
		} 
	}
}
		return ret_val;
	}



//	NODE FUNCTIONS	

	


Node::Node() {
	parent = NULL;
	left = NULL; 
	right = NULL;
}

Node::Node(int i) {
	data = i;
	parent = NULL;
	left = NULL;
	right = NULL;
}

void Node::setLeft(Node * n) {
	left = n;
}

void Node::setRight(Node * n) {
	right = n;
}

void Node::setParent(Node * n) {
	parent = n;
}

Node * Node::getRight() {
	return right;
}

Node * Node::getLeft() {
	return left;
}

Node * Node::getParent() {
	return parent;
}


bool BSTree::removeNode(int e, Node * root){
    Node *parent1 = root; 
	Node *child_l;
	Node *child_r;
	while(parent1)
		{
			child_l = parent1->getLeft();
			child_r = parent1->getRight();
			if(parent1->getData() == e) {
				if(parent1->getLeft()) {
					int d = findMax(parent1->getLeft());
					parent1->setData(d);
					return true;
				}
				else if(!parent1->getLeft() && parent1->getRight()) {
					//cout << "where am i ? " << endl;
					int add_val = findMin(parent1->getRight());
					parent1->setData(add_val);
					return true;
				}
				else {
					delete(parent1);
					this->root = NULL;
					return true;
				}
			}
			
			//Left subtree has element
			else if(child_l && child_l->getData() == e)
				{
					//No children
					if(!child_l->getLeft() && !child_l->getRight())
						{
							parent1->setLeftNull();
							delete child_l;
						}
					//One Child: Left
					else if (child_l->left && !child_l->right)
						{
							parent1->setLeft(child_l->getLeft());
							parent1->getLeft()->setParent(parent1);
							delete child_l;
						}
					//One Child: Right
					else if (child_l->right && !child_l->left)
						{
							parent1->setLeft(child_l->getRight());
							child_l->getRight()->setParent(parent1);
							delete child_l;
						}
					//Two Children
					else if (child_l->getRight() && child_l->getLeft())
					   {
						 parent1->getLeft()->setData(findMin(parent1->getRight()));
						
					   }
					return true;
				}
			// Right subtree has element
			else if(child_r && child_r->getData() == e)
				{
					//No children
					if(!child_r->getLeft() && !child_r->getRight())
						{
							parent1->setRightNull();
							delete child_r;
						}
					//One Child: Left
					else if (child_r->getLeft() && !child_r->getRight())
						{
							parent1->setRight(child_r->getLeft());
							parent1->getRight()->setParent(parent1);
							delete child_r;
						}
					//One Child: Right
					else if (child_r->getRight() && !child_r->getLeft())
						{
							parent1->setRight(child_r->getRight());
							parent1->getRight()->setParent(parent1);
							delete child_r;
						}
					//Two Children
					else if (child_r->getRight() && child_r->getLeft())
					   {
					   	//cout << "Parent : " << parent1->getData() << endl;
					   	//cout << child_r->getData() << endl;
					   	//cout << "printing val of right: " << parent1->getRight()->getData() << endl;
					   //	cout << "print left: " << child_l->getData() << endl;

					 //  	cout << "print children : " << parent1->getRight()->getRight()->getData() << " " << parent1->getLeft()->getLeft()->getData() << endl;
					   	//cout << "print next: " << child_r->getRight()->getData() << endl;
					   	//cout << "print next: " << child_r->getRight()->getRight()->getData() << endl;
					   	//cout << " " << child_r->getLeft()->getLeft()->getRight()->getData() << " " << child_r->getLeft()->getRight()->getData() << endl;

					   	int test = findMax(child_r->getLeft());
					   	//cout << "Printing max value: " << test << endl;
						 parent1->getRight()->setData(test);
						
					   }
					return true;
				}
			
			//Checking left subtree for element
			else if(parent1->getData() > e)
				{					
					parent1 = parent1->getLeft();
				}
			//Checking right subtree for element
			else 
				{
					parent1  = parent1->getRight();
				}
		}
   return false; 

}

int BSTree::findMin(Node * r) {
	Node * temp = r;
	//cout << "in find min " << endl;
	int data = r->getData();
	Node * leftChild;
	if(temp->getLeft() == NULL) {
		if(temp->getRight() == NULL) {
			temp->getParent()->setRightNull();
			data = temp->getData();
			delete temp;
			return data;
		}
		else {
			temp->getParent()->setRight(temp->getRight());
			temp->getRight()->setParent(temp->getParent());
			data = temp->getData();
			delete temp;
			return data;
		}
	}
	while(temp->getLeft()) {
		leftChild = temp->getLeft();
		if(leftChild->getLeft() == NULL && leftChild->getRight() != NULL) {
	//		cout << " In right child not null" << endl;
			leftChild->getRight()->setParent(temp);
			temp->setLeft(leftChild->getRight());
			data = leftChild->getData();
			delete leftChild;
			return data;

		}
		else if(!(leftChild->getLeft()) && !(leftChild->getRight())) {
	//		cout << "in no children" << endl;
			data = leftChild->getData();
			temp->setLeftNull();
			delete leftChild;
			return data;
		}
		else {
			temp = temp->getLeft();
		}
	}
	return data;
}


int BSTree::findMax(Node * node) {
	//cout << "In find max" << endl;
	Node *temp = node;
	Node *child_r;
	int data = node->getData();
	if(temp->getRight() == NULL) {
		if(temp->getLeft() == NULL) {
			temp->getParent()->setLeftNull();
			data = temp->getData();
			delete temp;
			return data;
		}
		else {
		temp->getParent()->setLeft(temp->getLeft());
		temp->getLeft()->setParent(temp->getParent());
		data = temp->getData();
		delete temp;
		return data;
	  }
	}
	while(temp->getRight())
	{	
		child_r = temp->getRight();		
		if(!child_r->getRight() && child_r->getLeft())
		{	child_r->getLeft()->setParent(temp);
			temp->setRight(child_r->getLeft());
			data = child_r->getData();
			delete child_r;
			return data;
		}
		else if(!child_r->getRight() && !child_r->getLeft())
		{
			data = child_r->getData();
			temp->setRightNull();
			delete child_r;
		}
		else	
		{
			temp = temp->getRight();
		}
	}
	return data;
}

void BSTree::sortedArray(vector<int> &list) {
	Node *temp = root;
	if(root == NULL){
		list.clear();
		return;
	}
	else {
		sortedArrayNode(temp, list);
		//if(list.front() == 0) list.erase(list.begin());
	}

}

void BSTree::sortedArrayNode(Node * n, vector<int> &list) {
		if(n == NULL) return;
		sortedArrayNode(n->getLeft(), list);
		list.push_back(n->getData());
		//cout << n->getData() << "  ";
		sortedArrayNode(n->getRight(), list);

}

void BSTree::display() {
	inOrder(root);
}

void BSTree::inOrder(Node * n) {
	if(n == NULL) return;
	inOrder(n->getLeft());
	cout << n->getData() << " ";
	inOrder(n->getRight());
}