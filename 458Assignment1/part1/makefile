flags = -g -Wall -std=c++11

all: telnetcli telnetserv

telnetcli: client.o
	g++ $(flags) client.o -o telnetcli

client.o: client.cpp
	g++ -c $(flags) client.cpp -o client.o

telnetserv: server.o
	g++ $(flags) server.o -o telnetserv

server.o: server.cpp
	g++ -c $(flags) server.cpp -o server.o

clean:
	rm -f *.o client server