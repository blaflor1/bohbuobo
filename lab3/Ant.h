#ifndef _Ant_H
#define _Ant_H

class Ant;

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
	   ~Ant();
	   Ant(int i); //Constructor w/ unique id
	   void move();
	   int getID() {
		return id;
	}
	   int getX() {
		return x;
		}
	   int getY() {
	return y;
}
	   //void setID(int);
	   //void setX(int);
	   //void setY(int);
	   
};
#endif

