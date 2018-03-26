
#include <iostream>
#include <ofstream>
using namespace std;


class DogShelter {
public:
	Dog dog_array[max_dogs];
	int max_dogs;
	int current_dogs;
	DogShelter(int);
	bool addDog(Dog d);
	bool adopt(int id);

};