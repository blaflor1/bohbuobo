#include <iostream>
using namespace std;


int testProblem(int * fuck) {
	*fuck = ((*fuck) + 1) * (*fuck);

	return *fuck;
}

int main(int argc, char const *argv[])
{
	int x = 10;
	int * p;
	p = &x;
	cout << "value of x: " << x << " value of p: " << p << " P dereferenced: " << *p << endl;
	*p = 12;
	cout << "value of x: " << x << " value of p: " << p << " P dereferenced: " << *p << endl;
	int something = 10;
	testProblem(&something);
	cout << "Value of something: " << something << endl;
	return 0;
}