#include "Ant.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

Ant::Ant() {
	id = -1;
	x = 0;
	y = 0;
	//hjhj
}

Ant::Ant(int number) {
	id = number;
	x = 0;
	y = 0;
}

bool Ant::fight() {
	bool result;
	int win = rand() % 3;
	if(win == 0 || win == 1) result = true;
	else {
		result = false;
	}
	return result;
}

Ant::~Ant() {

	//cout << "Ant Destructor" << endl;
}
void Ant::move() {
	//cout << "old Coordinates: X = " << x << " Y = " << y << endl;
	int random = rand() % 4;
	if(random == 1) y = y - 1;
	else if(random == 2) y = y + 1;
	else if(random == 3) x = x - 1;
	else if(random == 0) x = x + 1;
	else{
		x = x+2;
		y = y - 2;
	}
	if(x > abs(20) || y > abs(20)) {
		x = 10;
		y = -10;
	}
	//cout << "new Coordinates: X = " << x << " Y = " << y << endl;
}

/*int Ant::getID() {
	return id;
}

//Ant getAnt(int ant_id)

int Ant::getX(){
	return x;
}

int Ant::getY() {
	return y;
}*/
