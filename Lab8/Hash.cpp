#include "Hash.h"


Hash::Hash(unsigned int size) {
	max_size = size;
	for (int i = 0; i < size; ++i)
	{
		array.push_back("");
	}

	string * new_key_array = new string[size];
	key_array = new_key_array;
	val_array = new string[size];
}

bool Hash::remove(string key) {
	for(vector<pair<string, string>>::iterator it = array.begin(); it != array.end(); it++) {
		
	}
}