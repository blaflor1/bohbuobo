#ifndef _LinkedList_H
#define _LinkedList_H
//template <class type> class Node;
//template<class type> class LinkedList;
#include <iostream>
#include <cstdlib>


template <class type> 
class Node{
private:
	
	type data;
	Node<type> * next;
	

public:
	
	Node(){
		next = NULL;
	}
	~Node() {
		//delete data;
		//delete next;
	}
	Node(const Node<type> & n){
		type temp = n.data;
		Node<type> * temp2 = n.next;
		this->setNext(temp2);
		this->setData(temp);
	}
	Node(type t) {
		this->data = t;
		next = NULL;
	}
	void setNext(Node<type> * a) {
		this->next = a;
	}
	void setNextNull() {
		this->next = NULL;
	}
	void setData(type a){
		this->data = a;
		next = NULL;
	}
	type getData() {
		return data;
	}

	Node<type> * getNext() {
		return next;
	}

};
//for(temp = head; temp->next != NULL; temp = temp->next);
template <class type> 
class LinkedList {
   template <class type2> friend class Queue;

private:
	Node<type> * head;
	Node<type> * next_iterator;
	//bool iterate;
	type ret_val;
	int size;
public:

	LinkedList() {
	   this->head = NULL;
	   next_iterator = NULL;
	   int size = 0;
	}
	~LinkedList(){
		Node<type> * temp = head;
		while(temp) {
		   Node<type> * n = temp->getNext();
		   delete temp;
		   temp = n;
		}
	}
	//void display();
	LinkedList(const LinkedList<type> & list) {
	   Node<type> * temp = list.head;
	   this->head = NULL;
	   Node<type> * copy;
	   Node<type> * temp2 = NULL;
	   size = list.size;
	   while(temp != NULL) {
		copy = new Node<type>(*temp);
		if(temp2 == NULL) head = copy;
		else {
			temp2->next = copy;
		}
		temp2 = copy;
		temp = temp->next;
	   }
        }
	
	void insert(type t) {

		Node<type> * add = new Node<type>(t);
		if(this->head == NULL) {
		  this->head = add;
		  readStart();
		  size++;
		}

		else {
		   Node<type> * temp = head;
		   while(temp->getNext() != NULL) {
			temp = temp->getNext();
		   }
		   temp->setNext(add);
		   size++;
		  }
	   }

	type & read() {	
		//std::cout << next_iterator->getData() << std::endl;
		ret_val = next_iterator->getData();
		next_iterator = next_iterator->getNext();
		return ret_val;
	 	}
	     
	 
	
	bool empty() {
	   return head == NULL;
	}

	bool remove(type & data) {
	   bool remove = false;
	   Node<type> * temp = head;
	   Node<type> * previous;
	   while(temp != NULL) {
	   	   std::cout << temp->getData() << std::endl;
	   	   std::cout << data << std::endl;
	   	   //if(size == 1 && temp->getData() == data) {
	   	   	//delete temp;
	   	   	//size--;
	   	   	///head = NULL;
	   	   	//readStart();
	   	   	//remove = true;
	   	   	//break;
	   	   //}
	   	   if(head->getData() == data) {
	   	   	head = head->getNext();
	   	   	delete temp;
	   	   	remove = true;
	   	   	size--;
	   	   	break;
	   	   }
	   	   else if(temp->getNext()->getData() == data) {
	   	   	previous = temp;
	   	   }
	   	   else if(temp->getData() == data) {
	   	   	previous->setNext(temp->getNext());
	   	   	delete temp;
	   	   	remove = true;
	   	   	size--;
	   	   	break;
	   	   }
	   	   else if(temp->getData() == data && temp->getNext() == NULL) {
	   	   	previous->setNextNull();
	   	   	delete temp;
	   	   	remove = true;
	   	   	size--;
	   	   	break;
	   	   }
	   	   temp = temp->getNext();
	   	}

	   return remove;
	   }

	//void removeHead() {//

	//}//
	   
	
	//void insertNode(Node * n);
	//void operator<<(type * a);
	//Node getNodeID(int ID);
	//bool getNode(){ 
	//bool remove(int ID);
	Node<type> * getHead() {
		return head;
	}

	void readStart() {
		next_iterator = head;
	}
};

#endif
