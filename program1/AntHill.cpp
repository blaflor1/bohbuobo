#include "AntHill.h"
#include "Ant.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;


AntHill::AntHill() {
	ants = LinkedList();
	Ant * ant1 = new Ant(1);
	Ant * ant2 = new Ant(2);
	Ant * ant3 = new Ant(3);
	food = 0;
	ants.insert(ant1);
	ants.insert(ant2);
	ants.insert(ant3);
	gridX = 20;
	gridY = 20;
	current_ants = 3;
	next_id = 4;
	turnNum = 1;
	hillAttackNum = 0;
	defended = 0;
	defeated = 0;

}



AntHill::~AntHill() {
   //delete ants;
   //while(ants->head != NULL)
   //{	delete ants->head;
   	//	ants->head = ants->next;	
   //}
   
}

void AntHill::turn() {
	ofstream myfile;
	myfile.open("anthill.log", iostream::out | iostream::app);
	myfile << "================ TURN #" << turnNum << "=================" << endl;
	myfile << "Hill currently has " << current_ants << " ants and " << food << "food rations." << endl;
	myfile << "Hill has been attacked " << hillAttackNum << "times." << endl;
	myfile << "Defended: " << defended << "  Defeated: " << defeated << endl;
	ants.display();
	cout << "================ TURN #" << turnNum << "=================" << endl;
	Node * temp = ants.getHead();
	deleted = 0;
	while(food > 0) {
		Ant * temp2 = new Ant(next_id);
		next_id++;
		ants.insert(temp2);
		current_ants++;
		food--;
	}
	while(temp != NULL) {

		temp->data.move();
		int event1 = rand() % 4;
		int event2 = rand() % 6;
		
		if(event1 == 0) {
			//cout << "Food" << endl;
			food++;
		}
		
		else if(event2 == 1) {
			cout << "Fight!" << endl;
			int antID = temp->data.fight(); 
			myfile << "Ant #" << antID << " encountered a rival" << endl;
			bool fight_result = temp->data.fight();
			if(fight_result == false) {
				myfile << "Ant #" << antID << " is dead." << endl;
				int remID = temp->data.getID();
				ants.remove(remID);
				current_ants--;
				deleted++;
			}
			//What should I do here? Should only the defending ant be deleted?
		}
		temp = temp->next;
		
	}
	int hillAttack = rand() & 8;
	if(hillAttack == 0) {
		cout << "Hill attacked" << endl;
		hillAttackNum++;
		bool hill_result = antHillFight();
		if(hill_result == false) defeated++;
		else {
			defended++;
		}
	}
	//REMEMBER THIS needs to write to a file!
	turnNum++;
	myfile.close();
	cout << "Current Num Ants: " << current_ants << endl;

}

bool AntHill::antHillFight() {
	bool result;
	attackNum = rand() % current_ants + 1;
	Node * temp = ants.getHead();
	int defend_ants = 0;
	while(temp != NULL) {
		//int x_abs = abs(temp->data.getX());
		//int y_abs = abs(temp->data.getY());
		if(temp->data.getX() <= 10 && temp->data.getX() >= -10){
			defend_ants++;
		}
		else if(temp->data.getY() <= 10 && temp->data.getY() >= -10){
			defend_ants++;
		}
		temp = temp->next; 
	}
	if(defend_ants > attackNum) {
		result = true;
	}else {
		result = false;
		temp = ants.getHead();
		while(temp != NULL) {
			//int x_abs = abs(temp->data.getX());
			//int y_abs = abs(temp->data.getY());
			if((temp->data.getX() <= 10 && temp->data.getX() >= -10) || (temp->data.getY() <= 10 && temp->data.getY() >= -10)) {
				ants.remove(temp->data.getID());
				current_ants--;
				deleted++;
			}
			temp = temp->next; 
		}
    }
    return result;
}




int AntHill::getCurrentNumAnts() {
	return current_ants;
}
	

















