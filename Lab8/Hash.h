#ifndef _Hash_H
#define _Hash_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Hash {
private:
	string key;
	string value;
	vector<string> val_array;
	string<string> key_array;
	vector<pair<string, string>> array;
	int max_size;



public:
	Hash(unsigned int size);
	bool insert(string key, string value) {
		bool retval = false;
		if(size() == true) return false;
		else {
			retval = true;
			key_array.push_back(key);
			val_array.push_back(value);
			pair<string, string> inPair(key, value);
			array.push_back(inPair);

		}
		return retval;
	}
	bool remove(string key) {
		bool ret_val = false;
		for(int i = 0; i < array.size(); i++) {
			if(array[i].get<0> == key) {
				ret_val = true;
				array[i].get<0> = "";
				array[i].get<1> = "";
				break;
			}

		}
		return ret_val;
	}
	string find(string key) {

	}
	bool empty();
	bool size() {
		if(array.size() == max_size) return true;
		return false;
	}
	void printHash();
	int hasher(string key) {
		int hashIndex = 5;
		for(int i = 0; i < key.length(); i++) {
			hashIndex = hashIndex
		}
	}


}