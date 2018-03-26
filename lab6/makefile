all: lab6

lab6: lab6.o
	g++ -g lab6.o -o lab6

lab6.o: lab6.cpp Sorter.h
	g++ -g -c lab6.cpp -o lab6.o


run: lab6
	./lab6

checkmem: lab6
	valgrind ./lab6

clean:
	rm -f *.o lab6
