all: mono

mono: mono.o
	g++ -g  mono.o -o mono


mono.o: mono.cpp
	g++ -g -c mono.cpp -o mono.o

run: mono
	./mono