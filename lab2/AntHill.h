#ifndef _AntHill_H
#define _AntHill_H
class Ant;
class AntHill;


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Ant {
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

class AntHill {
	private:
	   int max_ants;
	   int current_ants;
	   Ant ants[100];
	   int next_id;
	  // int last_id;
	public:
	   AntHill(int i);
	   bool addAnt();
	   Ant getAnt(int);
	   void move();
	   bool changeMax(int);
	   void printHillInfo();
	   int getMaxAnts();
	   int getCurrentNumAnts();
};
#endif	   
