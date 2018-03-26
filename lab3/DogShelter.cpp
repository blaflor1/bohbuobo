void addDog(Dog *d) {
	if(dogs == null) {
	dogs = new Dog*[1];
	} else {
		Dog ** temp = new Dog*[current+1];
		memcpy(temp, dogs, current*sizeof(Dog)); //works in terms of bytes
		delete[] dogs;
		dogs = temp;
	}
	dogs[current] = d;
	current++;
}