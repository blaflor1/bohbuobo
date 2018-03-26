
#include <iostream>
using namespace std;

#include <cstdlib>

template <class a_type>class TSorter {
   private:
      vector<a_type> v;
      unsigned int numElements;
      unsigned int capacity;

      void swap(int i, int j); 

  public:
      Sorter();
      Sorter(unsigned int initialCapacity);
      ~Sorter();

      void clear(); 
      bool insert(int value); 

      // Make sure the array contains at least newCapacity elements.
      // If not, grow it to that size and copy in old values
      unsigned int makeSpace(unsigned int newCapacity); 

      // Show the first n elements, k per line using << 
      void show(unsigned int n, unsigned int k); 

      // "Shuffle" the array elements
      void shuffle(); 

      // These are the functions you should implement for Lab 5
      // You should keep these interfaces the same, but you may add
      // other "helper" functions if necessary.
      void insertionSortI();
      void selectionSortI();
      void bubbleSortI();     
      void insertionSortR(); 
      void selectionSortR();	
      void bubbleSortR();
      void outerLoopS(int i);
      int innerLoopS(int j, int min);
      void outerLoopI(int i);
      int innerLoopI(int insert, int j);
      void outerLoopB(int i);
      void innerLoopB(int i); 
};


