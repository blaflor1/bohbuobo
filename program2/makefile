all: program2

program2: program2.o Heap.o Deck.o Card.o Player.o Table.o
	g++ -std=c++14 -g program2.o Heap.o Player.o Card.o Deck.o Table.o -o program2 

program2.o: program2.cpp Heap.o Deck.o Table.o
	g++ -std=c++14 -g -c program2.cpp -o program2.o

Table.o: Table.cpp Table.h Heap.o Deck.o Player.o
	g++ -std=c++14 -g -c Table.cpp -o Table.o

Deck.o: Deck.cpp Card.o
	g++ -std=c++14 -g -c Deck.cpp -o Deck.o


Heap.o: Heap.cpp Heap.h Player.o
	g++ -std=c++14 -g -c Heap.cpp -o Heap.o

Player.o: Player.cpp Player.h Card.o
	g++ -std=c++14 -g -c Player.cpp -o Player.o

Card.o: Card.cpp 
	g++ -std=c++14 -g -c Card.cpp -o Card.o

run: all
	./program2

checkmem: all
	valgrind ./program2

clean: program2
	rm *.o program2
