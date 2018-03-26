#include "AntHill.h"
#include "Ant.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;


AntHill::AntHill() {
	ants = NULL;
	current_ants = 0;
	next_id = 0;
}

AntHill::AntHill(int ant_num){
	ants = NULL;
	current_ants = 0;
	next_id = 0;

}

AntHill::~AntHill() {
   
   for (int i = 0; i < current_ants; ++i)
   {
   		delete ants[i];
   		
   }
   delete [] ants;
}


int AntHill::addAnt() {
	//bool add;
	/*
	current_ants += 1;
	Ant ** temp =  new Ant*[current_ants];
	for(int i = 0; i < current_ants - 1; i++) {
	   if(ants[i] != NULL) {
	      temp[i] = ants[i]; 
	   }
	}
	//~AntHill();
	delete [] ants;
	ants = new_array;
	next_id = rand() % 1000;
	cout << "ID: " << next_id << endl;
	Ant add_ant = new Ant(next_id);
	cout << "Check to see if updated : " << add_ant.getID() << endl;
	ants[current_ants - 1] = add_ant;	
        //add = true;	
	
	*/
	//int next_id;
	if(ants == NULL) {
		next_id = 1;
		current_ants = 1;
		ants = new Ant*[current_ants];
		Ant * first_ant = new Ant(next_id++);
		ants[current_ants - 1] = first_ant;
		
	} else {
		Ant ** temp = new Ant*[current_ants + 1];
		for(int i = 0; i < current_ants; i++) {
	   		//if(ants[i] != NULL) {
	      		temp[i] = ants[i]; 
	   		//}
		}
		
		
		//next_id = rand() % 111567 + 3;
		Ant * add_ant = new Ant(next_id++);
		temp[current_ants] = add_ant;
		current_ants++;
		delete [] ants;
		ants = temp;
		//next_id++;

	}
	cout << "Current Num Ants: " << current_ants << "with ID: " << ants[current_ants - 1]->getID() <<  endl;
	return next_id;
}

bool AntHill::removeAnt(int id) {
	bool remove = false;
	int index;
	
	

	for(int i = 0; i < current_ants; i++) {
	   if(ants[i]->getID() == id) {

	     
		remove = true;
		index = i;
		
		break;
	   }
	}
	//use mem copy twice?
	
	if(remove == true) {
		Ant ** temp = new Ant * [current_ants - 1];
		
		for(int j = 0; j < index; j++) {
			if(ants[j] != NULL) {
				temp[j] = ants[j];
			}

		}
		for(int x = index + 1; x < current_ants; x++ ) {
			if(ants[x] != NULL) {
				temp[x] = ants[x];
			}
		}
		current_ants--;
		delete ants[index];
		delete [] ants;
		ants = NULL;
		cout << "Free ants array" << endl;
		ants = temp;
	}
	cout << "Current Num Deleted Ants: " << current_ants << endl;
	return remove;
}
	

Ant * AntHill::getAnt(int id) {
	for(int i = 0; i < current_ants; i++) {
	   if(ants[i]->getID() == id) return ants[i];
	}	 
}

bool AntHill::checkAntID(int id) {
	bool ret_val = false;
	for (int i = 0; i < current_ants; ++i)
	{
		if(ants[i]->getID() == id){
			ret_val = true;
		}
		
	}
	return ret_val;

}

void AntHill::move() {
	cout << "In move function" << endl;
	for(int i = 0; i < current_ants; i++) {
		//cout << "Entered for loop at index: " << i << endl;
	   if (ants[i] != NULL)
	   {
	   	ants[i]->move();
	   }
	
	}
	cout << "Done with move " << endl;
}



void AntHill::printHillInfo() {
        
	for(int i = 0; i < current_ants; i++) {
	   cout << "Ant #" << ants[i]->getID() << " [" << ants[i]->getX() << "," << ants[i]->getY() << "]" << endl;
	}
}

int AntHill::getMaxAnts() {
	return max_ants;
}

int AntHill::getCurrentNumAnts() {
	return current_ants;
}
	

















