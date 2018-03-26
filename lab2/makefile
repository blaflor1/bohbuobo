all: lab2

lab2: lab2.o AntHill.o
	g++ lab2.o AntHill.o -o lab2

lab2.o: lab2.cpp AntHill.cpp
	g++ -c lab2.cpp

AntHill.o: AntHill.cpp
	g++ -c AntHill.cpp

run: lab2
	./lab2
checkmem: lab2
	valgrind ./lab2

clean:
	rm *.o AntHill
