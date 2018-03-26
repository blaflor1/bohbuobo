#include <iostream>
using namespace std;
#include <vector>
#include "TSorter.h"

void TSorter::swap(iterator i, iterator j) {
   a_type tmp; 
   tmp = v[i]; 
   v[i] = v[j];
   v[j] = tmp; 
   return; 
}


TSorter::TSorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

TSorter::TSorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int TSorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void TSorter::clear() {
   numElements = 0;
   return; 
}

bool TSorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~TSorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void TSorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void TSorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Snsertion Sort
void TSorter::insertionSortI() {
   iterator i, j;
   for (i = v.begin() + 1; i != v.end(); i++) {
	a_type currentNumToInsert = array[i];
	j = i;
	while( (j >0) && (array[j-1] > currentNumToInsert))
	{
		array[j] = array[j-1];
		j = j-1;
	}
        array[j] = currentNumToInsert;
   }
  // cout << "Sorter::insertionSortI()." << endl << endl;
}

void TSorter::outerLoopI(int i) {
   if(i == numElements) return;
   else {
   	int insertNum = array[i];
   	int j = i;
   	j = innerLoopI(insertNum, j);
	array[j] = insertNum;
	outerLoopI(i+1);
	}
}

int TSorter::innerLoopI(int insert, int j) {
	if( j <= 0 || array[j-1] <= insert) return j;
	else {
	   array[j] = array[j-1];
	   j = j-1;
	   
	   return innerLoopI(insert, j);

	}
}
// Iterative Selection Sort
void TSorter::selectionSortI() {
   iterator i, j, min;
   for(i = v.begin(); i != v.end(); i++) {
	min = i;
	for(j = i+1; j < numElements; j++) {
		if (v[j] < v[min]) min = j;
	}
	swap(i, min);
   }
   
   //cout << "Sorter::selectionSortI()." << endl << endl;
}

// Iterative Bubble Sort
void TSorter::bubbleSortI() {
   iterator i, j;
   for(i = v.end(); i != v.begin(); i--) {
	for (j = v.begin()+1; j <= i; j++) {
		if(array[j-1] > array[j]) swap(j-1, j);
	}
   }  
 //  cout << "Sorter::bubbleSortI()." << endl << endl;
}
     
void TSorter::outerLoopB(int i) {
   
   if(i <= 0) return;
   else {
	innerLoopB(i);
	outerLoopB(i-1);
   }
}

void TSorter::innerLoopB(int i) {
   int j = 1;
   if(j >= i) return;
   else {
      if(array[j-1] > array[j]) swap(j-1, j);
      innerLoopB(j+1);
   }
}

// Recursive Insertion Sort
void TSorter::insertionSortR() {
   int i = 1;
   outerLoopI(i);
   cout << "Sorter::insertionSortR() not implemented yet." << endl << endl;
}
 
// Recursive Selection Sort
void TSorter::selectionSortR() {
   cout << "Sorter::selectionSortR() implemented." << endl << endl;
   int i = 0;
   outerLoopS(i);
   
}
	
// Recursive Bubble Sort
void TSorter::bubbleSortR() {
   int i = numElements - 1;
   outerLoopB(i);
   cout << "Sorter::bubbleSortR() not implemented yet." << endl << endl;
}

