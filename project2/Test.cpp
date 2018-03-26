#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <cstring>
#include <vector>
#include "Test.h"
#include <deque>
using namespace std;

Test::Test() {
	hit1 = 0;
	total1 = 0;

}

class LRUclass{
public:
    deque<int> array;
};

void Test::preFetch(string s, int size){
int cacheSize = 512;
int sets_num = cacheSize/size; 
vector<LRUclass> LRUvec;
int addr;
ifstream infile(s.c_str());
LRUclass LRU;
string behavior, line;
int total = 0;
int hit = 0;
int tableSize = (16 * 1024) / (32 * size);
int original_addr;
//int cacheSize = 512;
for (int i = 0; i < size; i++) {
    LRU.array.push_back(0);
}



for (int i = 0; i < tableSize; i++) {
    LRUvec.push_back(LRU);
}



while(getline(infile,line)) {
    stringstream s(line);
   	s >> behavior >> std::hex >> addr;
    bool location = false;
    int tag = addr / 32;
    original_addr = addr;
   // int index = tag % tableSize;
   
   	addr = addr >> 5;
   	int index = addr & sets_num - 1;
   	addr = addr >> (unsigned long long) log2(sets_num);
   	//tag = addr;
    for(int i = 0 ; i < size ; i++){
        if(LRUvec[index].array[i] == tag){
            hit++;
            location = true;
            LRUvec[index].array.erase(LRUvec[index].array.begin() + i);
            LRUvec[index].array.push_front(tag);
            
            break;
        }
    }
    if(location == false) {
            LRUvec[index].array.push_front(tag);
            LRUvec[index].array.pop_back();
            int new_addr = original_addr + 32;
            location = false;
            tag = new_addr / 32 ;
            index = tag % tableSize;
            for(int i = 0 ; i < size; i++){
                if(LRUvec[index].array[i] == tag){
                    LRUvec[index].array.erase(LRUvec[index].array.begin() + i);
                    LRUvec[index].array.push_front(tag);
                
                    location = true;
                    break;
                }
            }
            if(location == false) {
                LRUvec[index].array.push_front(tag);
                LRUvec[index].array.pop_back();
            }
        }
        total ++ ;
    }
    cout << " " << hit << ", " << total << "; " ;
    w = " ";
    string hitString = to_string(hit);
    w = w + hitString;
    w += ", ";
    string total_string = to_string(total);
    w = w + total_string;
    w+= "; ";

}

void Test::setAssociative3(string s, int size){
int cacheSize = 512;
int sets_num = cacheSize/size; 
int addr;
ifstream infile(s.c_str());
LRUclass LRU;
string behavior, line ;

int tableSize = (1024 * 16) / (32 * size);


vector<LRUclass> LRUvec;
//int cacheSize = 512;
for (int i = 0; i < size; i++) {
    LRU.array.push_back(0);
}

for (int i = 0; i < tableSize; i++) {
    LRUvec.push_back(LRU);
}

int total = 0;
int hit = 0;

while(getline(infile,line)) {
    stringstream s(line);
   	s >> behavior >> std::hex >> addr;
    bool location = false;
    int original_addr = addr;
    int tag = addr / 32;
    int setNum = tag % tableSize;
   
   	addr = addr >> 5;
   	int index = addr & sets_num - 1;
   	addr = addr >> (unsigned long long) log2(sets_num);
   	//tag = addr;
    for(int i = 0 ; i < size ; i++){
        if(LRUvec[index].array[i] == tag){
            hit++;
            location = true;
            LRUvec[index].array.erase(LRUvec[index].array.begin() + i);
            LRUvec[index].array.push_front(tag);
            
            break;
        }
    }
    if(location == false) {
        LRUvec[index].array.push_front(tag);
        LRUvec[index].array.pop_back();
    }
    int new_addr = original_addr + 32;
    bool location2 = false;
    int new_tag = new_addr / 32;
    int new_index = new_tag & sets_num - 1;
    for(int i = 0 ; i < size ; i++){
        if(LRUvec[new_index].array[i] == new_tag){
           // hit++;
            location2 = true;
            LRUvec[new_index].array.erase(LRUvec[new_index].array.begin() + i);
            LRUvec[new_index].array.push_front(new_tag);
            
            break;
        }
        if (location2 == false) {
        	LRUvec[new_index].array.push_front(new_tag);
        	LRUvec[new_index].array.pop_back();
        }
    }
    total++;
}//cout << " " << hit << ", " << total << "; " ;
    w = " ";
    string hitString = to_string(hit);
    w = w + hitString;
    w += ", ";
    string total_string = to_string(total);
    w = w + total_string;
    w+= "; ";

cout << " " << hit << ", " << total << "; " ;
}




void Test::setAssociative(string s, int size){
int cacheSize = 512;
int sets_num = cacheSize/size; 
int addr;
ifstream infile(s.c_str());
LRUclass LRU;

//int cacheSize = 512;
for (int i = 0; i < size; i++) {
    LRU.array.push_back(0);
}
string behavior, line;

int tableSize = (16 * 1024) / (32 * size);


vector<LRUclass> LRUvec;
for (int i = 0; i < tableSize; i++) {
    LRUvec.push_back(LRU);
}

int total = 0;
int hit = 0;

while(getline(infile,line)) {
    stringstream s(line);
   	s >> behavior >> std::hex >> addr;
    bool location = false;
    int tag = addr / 32;
    int setNum = tag % tableSize;
   
   	addr = addr >> 5;
   	int index = addr & sets_num - 1;
   	addr = addr >> (unsigned long long) log2(sets_num);
   	//tag = addr;
    for(int i = 0 ; i < size ; i++){
        if(LRUvec[index].array[i] == tag){
            hit++;
            location = true;
            LRUvec[index].array.erase(LRUvec[index].array.begin() + i);
            LRUvec[index].array.push_front(tag);
            
            break;
        }
    }
    if(location == false) {
        LRUvec[index].array.push_front(tag);
        LRUvec[index].array.pop_back();
    }
    total++;
}

cout << " " << hit << ", " << total << "; " ;
 w = " ";
    string hitString = to_string(hit);
    w = w + hitString;
    w += ", ";
    string total_string = to_string(total);
    w = w + total_string;
    w+= "; ";
}



void Test::setAssociative2(string s, int size){
int cacheSize = 512;
int sets_num = cacheSize/size; 
int addr;
ifstream infile(s.c_str());
vector<LRUclass> LRUvec;
LRUclass LRU;
int total = 0;
int hit = 0;

//int cacheSize = 512;

string behavior, line ;

int tableSize = (16 * 1024) / (32 * size);

for (int i = 0; i < size; i++) {
    LRU.array.push_back(0);
}

for (int i = 0; i < tableSize; i++) {
    LRUvec.push_back(LRU);
}



while(getline(infile,line)) {
    stringstream s(line);
   	s >> behavior >> std::hex >> addr;
    bool location = false;
    int tag = addr / 32;
    int setNum = tag % tableSize;
   
   	addr = addr >> 5;
   	int index = addr & sets_num - 1;
   	addr = addr >> (unsigned long long) log2(sets_num);
   	//tag = addr;
    for(int i = 0 ; i < size ; i++){
        if(LRUvec[index].array[i] == tag){
            hit++;
            location = true;
            LRUvec[index].array.erase(LRUvec[index].array.begin() + i);
            LRUvec[index].array.push_front(tag);
            
            break;
        }
    }
    if(location == false && behavior != "S") {
        LRUvec[index].array.push_front(tag);
        LRUvec[index].array.pop_back();
    }
    total++;
}

cout << " " << hit << ", " << total << "; " ;
 w = " ";
    string hitString = to_string(hit);
    w = w + hitString;
    w += ", ";
    string total_string = to_string(total);
    w = w + total_string;
    w+= "; ";
}


void Test::directMapped(string s, int size) {
unsigned long long addr;
string behavior, line;
int entries = size * 1024;
//if(size == 1) entries = 1024;
//else if(size == 2) entries = 2048;
//else if (size == 4) entries = 1024 * 4;
//else if (size == 16) entries = 1024 * 16;
//else if (size == 32) entries = 1024 * 32;
int cacheSize = entries / 32;
int table[cacheSize];
for(int i = 0; i < cacheSize; i++) {
   table[i] = 0;
}
int hit = 0;
int total = 0;
//int n = log(32);


ifstream infile(s.c_str());
while(getline(infile,line)) {
   stringstream s(line);
   s >> behavior >> std::hex >> addr;
   int tag;
   addr = addr >> 5;
   int index = addr & cacheSize-1;
   addr = addr >> 5;
   tag = addr;
   int cacheLocation = addr % cacheSize;
   if(table[index] == tag) {
   	hit++;
   	table[index] = tag;
   }
   else {
   	table[index] = tag;
   }
   total++; 
    
}
cout << " " << hit << ", " << total << "; " ;
 w = " ";
    string hitString = to_string(hit);
    w = w + hitString;
    w += ", ";
    string total_string = to_string(total);
    w = w + total_string;
    w+= "; ";
infile.close();

}



void Test::fullyAssociative(string s, int size) {
	deque<int> LRU; 
	int entries = 1024 * size;
	int cacheSize = entries / 32;
	int table[cacheSize];
	bool valid[cacheSize];
	unsigned long long addr;
	string behavior, line;
	int hit = 0;
	int total = 0;

	bool allValid = false;
//int num_sets = 32 / 
	for(int i = 0; i < cacheSize; i++) {
      table[i] = 0;
      valid[i] = 0;
}
	ifstream infile(s.c_str());
   while(getline(infile,line)) {
   		stringstream s(line);
   		s >> behavior >> std::hex >> addr;
   		unsigned long long tag;
  // 		addr = addr >> 5;
  // 		int index = addr & cacheSize-1;
  // 		addr = addr >> 5;
   		tag = addr >> 5;
   		bool located = false;

   		//int cacheLocation = addr % cacheSize;
   		for(int y = 0; y < cacheSize; y++) {
   			if(table[y] == tag) {
   				hit++;
	   			located = true;

	   			for(int z = 0; z < LRU.size(); z++) {
	   				if(LRU[z] == y) {
	   					LRU.push_back(y);
	   					LRU.erase(LRU.begin() + z);
	   					break;
	   				}
	   			}
	   			break;
   		 	}
   		}
   		if(located == false){


   			if(allValid == false){

	  			for(int x = 0; x < cacheSize; x++) {
	   				if(valid[x] == 0) {
	   					valid[x] =1;
	   					table[x] = tag;
	   					LRU.push_back(x);
	   					break;
	   				}

	   				if(x == cacheSize - 1) {
	   					allValid = true;
	   				}
	   			}
	   		}
   			else  {
   					int use_index = LRU.front();
   					table[use_index] = tag;
   					LRU.push_back(use_index);
   					LRU.pop_front();
   				}

   		}
   		
   		
   		total++;

   	}
   	cout << " " << hit << ", " << total << "; " ;
   	 w = " ";
    string hitString = to_string(hit);
    w = w + hitString;
    w += ", ";
    string total_string = to_string(total);
    w = w + total_string;
    w+= "; ";

	
}
