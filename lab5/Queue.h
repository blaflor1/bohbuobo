#ifndef _Queue_H
#define _Queue_H
template <class type> class Queue;
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>
using namespace std;


template <class type>
class Queue {
   private:
	LinkedList<type> * list;
   

   public:
   	Queue() {
   		list = new LinkedList<type>();
   	}


	bool enqueue(type d) {
	   list->insert(d);
	  }
	type dequeue() {
	   Node<type> *temp = new Node<type>(*(list->getHead()));
	   Node<type> * temp2 = list->getHead();
	   list->head = list->head->getNext();
	   delete temp2;
	   return temp->getData();
	}
	type  peek() {
	   Node<type> * ret_val = list->getHead();
	   return ret_val->getData();
	}
	bool empty() {
	   bool empty = false;
	   if(list->getHead() == NULL) empty = true;
	   return empty;
	} 
	void clear() {
	   Node<type> * temp = list->head;
	   while(temp) {
		Node<type> * n = temp->next;
		delete temp;
		temp = n;
	}
}
	LinkedList<type> getList(){
		return list;
	}
	~Queue() {
		delete list;
	}

};
#endif

