#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <cstring>
#include <vector>
#include "Test.h"
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
	Test tester;
	string s2;
  	string s1;
  	stringstream ss;
  	ss << argv[1];
  	ss >> s1;
  	ss << argv[2];
  	ss >> s2;
  	ofstream myfile;
 	myfile.open(s2.c_str());
	tester.directMapped(s1, 1);

	//
  
  	myfile << tester.w <<" ";
  	//tester.hit = 0;
	//tester.total = 0;
	tester.directMapped(s1, 4);
	
  
  	myfile << tester.w <<" ";
  	//tester.hit = 0;
	//tester.total = 0;
	tester.directMapped(s1, 16);
	//cout << " " << tester.hit << ", " << tester.total << "; " << endl;
  
  	myfile << tester.w <<" ";
  	//	tester.hit = 0;
	//tester.total = 0;
	tester.directMapped(s1, 32);
	//cout << " " << tester.hit << ", " << tester.total << "; " << endl;
  
  	myfile << tester.w <<" ";
	//tester.hit = 0;
	//tester.total = 0;
		cout << " "  << endl;

	
	tester.setAssociative(s1, 2);
	myfile << tester.w <<" ";
	tester.setAssociative(s1, 4);
	myfile << tester.w <<" ";
	tester.setAssociative(s1, 8);
	myfile << tester.w <<" ";
	tester.setAssociative(s1, 16);
	myfile << tester.w << endl;
		cout << " "  << endl;
	tester.fullyAssociative(s1, 16);
	myfile << tester.w << endl;
	cout << " "  << endl;
	tester.setAssociative2(s1, 2);
	myfile << tester.w <<" ";
	tester.setAssociative2(s1, 4);
	myfile << tester.w <<" ";
	tester.setAssociative2(s1, 8);
	myfile << tester.w <<" ";
	tester.setAssociative2(s1, 16);
	myfile << tester.w <<endl;
		cout << " "  << endl;
	tester.setAssociative3(s1, 2);
	myfile << tester.w <<" ";
	tester.setAssociative3(s1, 4);
	myfile << tester.w <<" ";
	tester.setAssociative3(s1, 8);
	myfile << tester.w <<" ";
	tester.setAssociative3(s1, 16);
	myfile << tester.w <<endl;
	cout << " "  << endl;
	tester.preFetch(s1, 2);
	myfile << tester.w <<" ";
	tester.preFetch(s1, 4);
	myfile << tester.w <<" ";
	tester.preFetch(s1, 8);
	myfile << tester.w <<" ";
	tester.preFetch(s1, 16);
	myfile << tester.w <<" ";
	myfile.close();
	return 0;
}