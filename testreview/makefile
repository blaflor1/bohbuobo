all: test

test: test.o
	g++ test.o   -o test

test.o: test.cpp 
	g++ -c test.cpp -o test.o


run: test
	./test

checkmem: test
	valgrind ./test

clean:
	rm -f *.o test
