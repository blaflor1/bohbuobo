all: lab7

lab7: lab7.o BSTree.o
	g++ -std=c++14 -g  lab7.o BSTree.o -o lab7

lab7.o: lab7.cpp BSTree.o
	g++ -std=c++14 -g -c lab7.cpp -o lab7.o

BSTree.o: BSTree.cpp BSTree.h
	g++ -std=c++14 -g -c BSTree.cpp -o BSTree.o

run: lab7
	./lab7

clean: lab7
	rm *.o lab7

checkmem: lab7
	valgrind ./lab7
