#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
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

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Snsertion Sort
void Sorter::insertionSortI() {
   int i, j;
   for (i = 1; i< numElements; i++) {
	int currentNumToInsert = array[i];
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

void Sorter::outerLoopI(int i) {
   if(i == numElements) return;
   else {
   	int insertNum = array[i];
   	int j = i;
   	j = innerLoopI(insertNum, j);
	array[j] = insertNum;
	outerLoopI(i+1);
	}
}

int Sorter::innerLoopI(int insert, int j) {
	if( j <= 0 || array[j-1] <= insert) return j;
	else {
	   array[j] = array[j-1];
	   j = j-1;
	   
	   return innerLoopI(insert, j);

	}
}
// Iterative Selection Sort
void Sorter::selectionSortI() {
   int i, j, min;
   for(i = 0; i < numElements-1; i++) {
	min = i;
	for(j = i+1; j < numElements; j++) {
		if (array[j] < array[min]) min = j;
	}
	swap(i, min);
   }
   
   //cout << "Sorter::selectionSortI()." << endl << endl;
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
   int i, j;
   for(i = (numElements - 1); i >=0; i--) {
	for (j = 1; j <= i; j++) {
		if(array[j-1] > array[j]) swap(j-1, j);
	}
   }  
 //  cout << "Sorter::bubbleSortI()." << endl << endl;
}
     
void Sorter::outerLoopB(int i) {
   
   if(i <= 0) return;
   else {
	innerLoopB(i);
	outerLoopB(i-1);
   }
}

void Sorter::innerLoopB(int i) {
   int j = 1;
   if(j >= i) return;
   else {
      if(array[j-1] > array[j]) swap(j-1, j);
      innerLoopB(j+1);
   }
}

// Recursive Insertion Sort
void Sorter::insertionSortR() {
   int i = 1;
   outerLoopI(i);
   cout << "Sorter::insertionSortR() not implemented yet." << endl << endl;
}
 
// Recursive Selection Sort
void Sorter::selectionSortR() {
   cout << "Sorter::selectionSortR() implemented." << endl << endl;
   int i = 0;
   outerLoopS(i);
   
}
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
   int i = numElements - 1;
   outerLoopB(i);
   cout << "Sorter::bubbleSortR() not implemented yet." << endl << endl;
}

void Sorter::outerLoopS(int i) {
   int j = i+1;
   int min = i;
   if(array[i] == array[numElements - 1]) return;
   else {
	min = innerLoopS(j, min);
	swap(i, min);
   	outerLoopS(i +1);
  }
   
}	

int Sorter::innerLoopS(int j, int min) {
   if(array[j] == array[numElements]) return min;
   else {
	if (array[j] < array[min]) min = j;
	return innerLoopS(j + 1, min);
	
	}
   }

