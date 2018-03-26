all: BestFirstSearch

BestFirstSearch: main.o Project2.o 
	g++ -std=c++14 -g main.o Project2.o -o BestFirstSearch

main.o: main.cpp Project2.o 
	g++ -std=c++14 -g -c main.cpp -o main.o

Project2.o: Node.h Project2.h Project2.cpp
	g++ -std=c++14 -g -c Project2.cpp -o Project2.o


run: all
	./BestFirstSearch

checkmem: all
	valgrind ./BestFirstSearch

clean: BestFirstSearch
	rm *.o BestFirstSearch