#ifndef _AntHill_H
#define _AntHill_H
//class Ant;
class AntHill;

#include "Ant.h"
#include "LinkedList.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


/*class Ant {
	private:
	   int id;
	   int x;
	   int y;
	public:
	   Ant(); //Default constructor
	   Ant(int); //Constructor w/ unique id
	   void move();
	   int getID();
	   int getX();
	   int getY();
	   //void setID(int);
	   //void setX(int);
	   //void setY(int);
	   
};
//#endif
*/
class AntHill {
	private:
		int gridX;
		int gridY;
	   //int max_ants;
	   int current_ants;
	   LinkedList ants;
	   int next_id;
	   int food;
	   int hillAttackNum;
	   int defeated;
	  // int antIdCounter;
	   int defended;
	   int deleted;
	   //int failedDefend;
	   int attackNum;
	   int turnNum;
	  // int last_id;
	public:
		AntHill();
		~AntHill();
	   AntHill(int i);
	   bool antHillFight();
	   void turn();
	   //int addAnt();
	   //bool removeAnt(int i);
	   //Ant * getAnt(int i);
	   //bool checkAntID(int i);
	   //void move();
	   //bool changeMax(int i);
	   //void printHillInfo();
	   int getCurrentNumAnts();
};
#endif	   
