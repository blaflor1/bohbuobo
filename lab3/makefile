all: lab3

lab3: lab3.o AntHill.o Ant.o
	g++ lab3.o AntHill.o Ant.o  -o lab3

lab3.o: lab3.cpp AntHill.cpp Ant.cpp
	g++ -c lab3.cpp

AntHill.o: AntHill.cpp Ant.cpp
	g++ -c AntHill.cpp

Ant.o: Ant.cpp
	g++ -c Ant.cpp

run: lab3
	./lab3
checkmem: lab3
	valgrind ./lab3

clean:
	rm *.o AntHill Ant
