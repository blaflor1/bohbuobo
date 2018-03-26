#include "Sorter.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<class type>
void Sorter<type>::insertionSort() {
   typename type::iterator i, j;
   for (i = this->list1.begin() + 1; i != this->list1.end(); i++) {
	type currentNumToInsert = list1[i];
	j = i;
	while( (j >0) && (this->list1[j-1] > currentNumToInsert))
	{
		this->list1[j] = this->list1[j-1];
		j = j-1;
	}
        this->list1[j] = currentNumToInsert;
   }
  
}

//template<class type>
void Sorter<type>::bubbleSort() {
   typename type::iterator i, j;
   for(i = this->list1.end(); i != this->list1.begin(); i--) {
	for (j = this->list1.begin()+1; j <= i; j++) {
		if(this->list1[j-1] > this->list1[j])  {
			type temp; 
   			temp = list1[j-1]; 
   			list1[j-1] = list1[j];
   			list1[j] = temp;
		}
    }  

   }
}

template<class type>
void Sorter<type>::selectionSort() {
   typename type::iterator i, j, min;
   for(i = this->list1.begin(); i != this->list1.end(); i++) {
	min = i;
	for(j = i+1; j < list1.size(); j++) {
		if (this->list1[j] < this->list1[min]) min = j;
	}
	type temp; 
   	temp = list1[j-1]; 
   	list1[j-1] = list1[j];
   	list1[j] = temp;
   }
   
   
}
template<class type>
void Sorter<type>::shuffle(){
		   vector<type> copy = list1;
		   for(unsigned int i = 0; i < list1.size(); i++)  {
			   int shuffle = rand() % (copy.size() - 1);
			   copy.erase(copy.begin() + (shuffle + 1));
			   unsigned int temp = list1[i];
			   list1[i] = list1[shuffle];
		 	   list1[shuffle] = list1[i];		
			
			}

		}
template<class type>
void Sorter<type>::clear() {

	list1.clear();

}

