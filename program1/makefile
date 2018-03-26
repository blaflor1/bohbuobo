all: project1

project1: project1.o Ant.o AntHill.o LinkedList.o
	g++ project1.o Ant.o AntHill.o LinkedList.o  -o project1

project1.o: project1.cpp Ant.cpp AntHill.cpp LinkedList.cpp
	g++ -c project1.cpp -o project1.o

LinkedList.o: LinkedList.cpp Ant.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

AntHill.o: AntHill.cpp Ant.cpp
	g++ -c AntHill.cpp -o AntHill.o

Ant.o: Ant.cpp
	g++ -c Ant.cpp -o Ant.o

run: project1
	./project1

checkmem: project1
	valgrind ./project1

clean:
	rm -f *.o project1
