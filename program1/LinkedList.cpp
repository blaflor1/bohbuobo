#include "LinkedList.h"
//#include "Ant.h"
#include <iostream>
#include <cstdlib>

using namespace std;

LinkedList::LinkedList() {
	head = NULL;

}

LinkedList::~LinkedList() {
	Node * temp = head;
	while(temp) {
		Node * n = temp->next;
		delete temp;
		temp = n;
	}
}

LinkedList::LinkedList(const LinkedList & list) {
	Node * temp = list.head;
	head = NULL;
	Node * copy;
	Node * temp2 = NULL;
	while(temp != NULL) {
		copy = new Node(*temp);
		if(temp2 == NULL) head = copy;
		else {
			temp2->next = copy;
		}
		temp2 = copy;
		temp = temp->next;
	}

}


void LinkedList::insert(Ant * insert_ant) {

	Node * add = new Node(insert_ant);

	if(head == NULL) {
		head = new Node(insert_ant);
	}
	else {

		//da
		Node * temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = add;
		//head = temp;
	}
}

void LinkedList::operator<<(Ant * insert_ant) {

	Node * add = new Node(insert_ant);

	if(head == NULL) {
		head = new Node(insert_ant);
	}
	else {

		//da
		Node * temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = add;	

	}
}

bool LinkedList::getNode(int id) {
	Node * temp = head;
	bool ret_node = false; 
	while(temp->next != NULL) {
		if(temp->getData().getID() == id) {
		ret_node = true;
		cout << "Found Node!" << endl;
		break;
	} else{
		temp->next = head->next;
		}
	}
	if(ret_node == false) cout << "Couldn't find node" << endl;
	return ret_node;
}

bool LinkedList::remove(int id) {
	bool remove = false;
	Node * temp = head;
	Node * previous;
	while(temp->data.getID() != id) {
		if(temp->next->data.getID() == id) { 
			previous = temp;
			remove = true;
		}
		temp = temp->next;
		
	}
	if(remove == true) {
		previous->setNext(temp->next);
		delete temp;
	}
	return remove;

}

void LinkedList::display() {
	Node * temp = head;
	while(temp) {
		int print = temp->data.getID();
		int printX = temp->data.getX();
		int printY = temp->data.getY();
		cout << "Ant ID: " << print << "at location X: " << printX << "and y: " << printY << endl; 
		temp = temp->next;
	}
}



Node::Node(){
	
}

Node::Node(const Node & n) {
	Ant temp = n.data;
	Node * temp2 = n.next; 
	this->setData(temp);
	this->setNext(temp2);
}

Node::Node(Ant * a) {
	this->data = *a;
	this->next = NULL;
}



