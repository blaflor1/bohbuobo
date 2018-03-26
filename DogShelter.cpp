#include "DogShelter.h"
#include <iostream>
#include <ofstream>
using namespace std;




DogShelter::DogShelter(int max) {
	max_dogs = i;
	Dog array[max_dogs];
	dog_array = array;
}

DogShelter::addDog(Dog doge) {
	bool add;
	int check = current_dogs + 1;
	if(check > current_dogs) {
		dog_array[current_dogs - 1] = doge;
		current_dogs += 1;
		add = true;
	}
	else {
		add = false;
	}
	return add;
}

bool DogShelter::adopt(int id) {
	//Need Dog ID and Breed
	bool adopted = false;
	ofstream myfile;
	myfile.open("adopted.log");
	for (int i = 0; i < current_dogs; ++i)
	{
		if(dog_array[i].getID() == id) {
			myfile << "Dog ID: " << dog_array[i].getID() << "\n" << "Breed: " << dog_array[i].getBreed() << endl;
			bool adopted = true;
		}
	}
	myfile.close();
	return adopted;

}