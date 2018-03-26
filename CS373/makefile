all: laflore_p1

laflore_p1: driver.o NFA.o Node.o
	g++ -std=c++14 -g driver.o NFA.o Node.o -o laflore_p1

driver.o: driver.cpp NFA.o Node.o
	g++ -std=c++14 -g -c driver.cpp -o driver.o

NFA.o: NFA.h NFA.cpp Node.o
	g++ -std=c++14 -g -c NFA.cpp -o NFA.o

Node.o: Node.h Node.cpp
	g++ -std=c++14 -g -c Node.cpp -o Node.o

run: all
	./laflore_p1

checkmem: all
	valgrind ./laflore_p1

clean: laflore_p1
	rm *.o laflore_p1