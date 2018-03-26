#ifndef _Sorter_H
#define _Sorter_H
#include <cstdlib>
#include <vector>
#include <list>
#include <iostream> 

using namespace std;

template <class type> class Sorter {

	private:
	   type list1;
	   unsigned int size1;

	public:

		Sorter() {
		  size1 = 0; 			
		}
		void clear() {
			list1.clear();
		}

		unsigned int size() {
		   return (unsigned int) list1.size();			
		}
		void insert(int i) {
		   list1.push_back(i);
		   size1++;			
		}



		void shuffleFalse(){
		   //type copy = list1;
			int listSize = list1.size() - 1;
			int copyArray[listSize];
			bool randVal = true;
		   for(unsigned int i = 0; i < list1.size(); i++)  {
			   int shuffle = rand() % (listSize);
			   //for(int j = 0; j < listSize; j++) {
			   	//if(copyArray[j] == shuffle) randVal = false;
			   //}

			   cout << "Print shuffle result: " << shuffle << " " << endl;
			  // if(randVal == true) {
			   	//copyArray.erase(shuffle + 1);
			   	unsigned int temp =  *((*this)[i]);
			   	(*this)[i] = (*this)[shuffle];
		 	   	(*this)[shuffle] = (*this)[i];
		 	   	copyArray[i] = shuffle;
		 	  // }	
			
			}

		}

		void shuffle() {
			unsigned int j;
			for(unsigned int i = 1; i < list1.size(); i++) {
				j = rand() % i;
				typename type::iterator temp; 
   				temp = *(*this)[i]; 
   				(*this)[i] = (*this)[j];
   				(*this)[j] = temp;

			}
		}


	 	typename type::iterator operator[] (int index){
	 		int index1 = 0;
	 		typename type::iterator it = list1.begin();
		   for(; index1 < index && it != list1.end(); it++){
		     index1++;

		   }	
			return it;
		  
		}

		void insertionSort() {
   			typename type::iterator i, j;
   			//int index = 0;
   			//int index2 = 0;
   			int i2, j2;
   			i2 = 0;
   			for (i = this->list1.begin()++; i != this->list1.end(); i++) {
				typename type::iterator currentNumToInsert = (*this)[i2];
				j2 = i2;
				//index2 = index1
				while( j2 > 0 && j2 > *currentNumToInsert)
				{
					this[j2] = this[j2-1];
					j2 = j2 - 1;
				}
				i2++;

       		 	(*this)[j2] = currentNumToInsert;
   			}
  
		}

		void bubbleSort() {
   			typename type::iterator i, j;
   			int index = list1.size() - 1;
   			int index2 = 1;
   			for(i = this->list1.end(); i != this->list1.begin(); i--) {
				for (j = this->list1.begin()++; *j <= *i; j++) {
					if(*((*this)[index2-1]) > *((*this)[index]))  {
						typename type::iterator temp; 
   						temp = (*this)[index2-1]; 
   						this[index2-1] = this[index2];
   						(*this)[index2] = temp;
					}
    			}  

   			}
		}

		void selectionSort() {
   			typename type::iterator i, j, min;
   			int i2, j2, min2;
   			i2 = 0;
   			for(i = this->list1.begin(); i != this->list1.end(); i++) {
				min = i;
				min2 = i2;
				for(j2 = i2+1; j2 < list1.size(); j2++) {
					if (*((*this)[j2]) < *((*this)[min2])) min2 = j2;
			}
				typename type::iterator temp; 
   				temp = (*this)[j2-1]; 
   				(*this)[j2-1] = (*this)[j2];
   				(*this)[j2] = temp;
   			}
   
   
		}

void swap(int i, int j) {
   typename type::iterator tmp; 
   *(tmp) = this[i]; 
   *(list1[i]) = *(this[j]);
   *(this[j]) = tmp; 
   return; 
}

void display() {
	for(int i = 0; i < list1.size(); i++) {
		cout << "Num at index: " << *((*this)[i]) << endl;
	}
}


};

#endif
