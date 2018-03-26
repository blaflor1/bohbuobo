#include "LinkedList.h"
#include "Ant.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void LinkedList::insert(Ant * insert_ant) {
	if(head == NULL) head = insert_ant;
	else {


		Node * temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = insert_ant;
		head = temp;
	}
}

Node LinkedList::getNode(Ant * ant) {
	temp = head;
	Ant ret_ant = NULL; 
	while(temp->getData() != *ant) {
		temp->next = head->next;
	}
	if(temp->getData() == *ant) return temp->getData();
	else {
		return NULL;
	}
	return ret_ant;
}