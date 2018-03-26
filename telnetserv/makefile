all: telnetserv

telnetserv: ser.o
	gcc -g  ser.o -o telnetserv

ser.o: ser.c
	gcc -g -c ser.c -o ser.o

run: telnetserv
	./telnetserv