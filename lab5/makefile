all: lab5

lab5: lab5.o Deck.o Card.o
	g++ -g  lab5.o Deck.o Card.o -o lab5

lab5.o: lab5.cpp Card.o Deck.o Queue.h LinkedList.h
	g++ -g -c lab5.cpp -o lab5.o


Deck.o: Deck.cpp Card.cpp Queue.h LinkedList.h
	g++ -g -c Deck.cpp -o Deck.o

Card.o: Card.cpp Card.h
	g++ -g -c Card.cpp -o Card.o

run: lab5
	./lab5

checkmem: lab5
	valgrind ./lab5

clean:
	rm -f *.o lab5
