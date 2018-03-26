#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Ant::Ant() {
	id = -1;
	x = 0;
	y = 0;
}

Ant::Ant(int number) {
	id = number;
	x = 0;
	y = 0;
}

void Ant::move() {
	int random = rand() % 4;
	if(random == 1) random = 1;
	else if(random == 2) random = -2;
	else if(random == 3) random = 3;
	else if(random == 0) random = -1;
	int select = rand() % 4;
	if(select == 1) x += random;
	else  { 
	   y += random;
	}
}

int Ant::getID() {
	return id;
}

//Ant getAnt(int ant_id)

int Ant::getX(){
	return x;
}

int Ant::getY() {
	return y;
}




AntHill::AntHill(int maxNum) {
	max_ants = maxNum;
	current_ants = 0;
}

bool AntHill::addAnt() {
	bool add;
	int check = current_ants;
	check += 1;
	if(check <= max_ants) {
	   current_ants += 1;
	   next_id = rand() % 1000;
	   cout << "ID: " << next_id << endl;
	   Ant add_ant = Ant(next_id);
	   cout << "Check to see if updated : " << add_ant.getID() << endl;
	   ants[current_ants - 1] = add_ant;	
           add = true;	
	}
	else {
	   add = false;
	}
	return add;
}

Ant AntHill::getAnt(int id) {
	
	       return ants[id];
	 
}

void AntHill::move() {
	for(int i = 0; i < current_ants; i++) {
	   if(ants[i].getID() != -1) {
		ants[i].move();
	   }
	}
}

bool AntHill::changeMax(int new_max) {
   bool change;
   if(new_max < 100 && new_max > 0) {
	max_ants = new_max;
	change = true;
   }
   else {
	change = false;
   }
   return change;
}

void AntHill::printHillInfo() {
        
	for(int i = 0; i < current_ants; i++) {
	   cout << "Ant #" << ants[i].getID() << " [" << ants[i].getX() << "," << ants[i].getY() << "]" << endl;
	}
}

int AntHill::getMaxAnts() {
	return max_ants;
}

int AntHill::getCurrentNumAnts() {
	return current_ants;
}
	

















