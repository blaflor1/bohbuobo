#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
    int sockfd, n; 
    char recvline[100];
    struct sockaddr_in servaddr;

	if (argc != 2) {
		printf("Usage : gettime <IP address>");
		exit(1); 
	}

    /* Create a TCP socket */
	if ((sockfd = socket(AF_INET,SOCK_STREAM, 0)) < 0) {
		perror("socket");
        exit(2);
    }
	    
    /* Specify server’s IP address and port */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(argv[2]); /* daytime server port */

    if (inet_pton(AF_INET, gethostbyname(argv[1]), &servaddr.sin_addr) <= 0) {
		perror("inet_pton"); exit(3);
    }

	/* Connect to the server */
    if (connect(sockfd, (struct sockaddr *) &servaddr,sizeof(servaddr)) < 0 ) {
         perror("Connection failed."); 
         exit(4); 
    }

    bool checkRunning = false; // Check if exit was entered
    string input; // User input

    while (checkRunning == false) {
        cout << "telnet > ";
        getline(cin, input);
        char* input2;
        input2 = input;
        send(sockfd, input2);
    }

    /* Read the date/time from socket */
    while ((n = read(sockfd, recvline, 100)) > 0) {
        recvline[n] = '\0';        /* null terminate */
        printf("%s", recvline); 
    }               
        
	if (n < 0) { 
        perror("read");
        exit(5);
    }

    close(sockfd);
} 