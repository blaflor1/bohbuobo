all: program3

program3: program3.o City.o Map.o
	g++ -std=c++14 -g program3.o Map.o City.o -o program3 

program3.o: program3.cpp City.o Map.o
	g++ -std=c++14 -g -c program3.cpp -o program3.o

Map.o: City.o Map.h Map.cpp
	g++ -std=c++14 -g -c Map.cpp -o Map.o

City.o: City.h City.cpp
	g++ -std=c++14 -g -c City.cpp -o City.o


run: all
	./program3

checkmem: all
	valgrind ./program3

clean: program3
	rm *.o program3