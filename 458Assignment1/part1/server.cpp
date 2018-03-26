#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  int listenfd, connfd, clilen;
  struct sockaddr_in servaddr, cliaddr;
  char buff[100];
  time_t ticks;

  /* Create a TCP socket */
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Initialize server's address and well-known port */
	bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family      = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  int foo = atoi(argv[1]);
  servaddr.sin_port        = htons(foo);   /* daytime server */

	/* Bind server’s address and port to the socket */
  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	/* Convert socket to a listening socket – max 100 pending clients*/
  listen(listenfd, 100); 
   
  struct directory {
      string name;
      directory preDir;
      vector<directory> dirList;
  };

  directory rootDir;
  rootDir->name = "root"; // Mark root directory

  directory currentDir;
  for ( ; ; ) {
      /* Wait for client connections and accept them */
    	clilen = sizeof(cliaddr);
      connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (unsigned int*) &clilen);

      //printf("hello1\n");

      /* Retrieve system time */
      ticks = time(NULL);
      
      snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
      printf("%s\r\n", ctime(&ticks));
      //printf("hello\n");

      string input = read(connfd, buff);
      istringstream ss(input);
      string command;
      ss >> command;
      if (command == "ls") {
          for (int i = 0; i < (int) currentDir->dirList.size()) {
              cout << currentDir->dirList[i]->name << " "; // Print directory content
          }
      } else if (command == "mkdir") {
          string newDirName;
          ss >> newDirName; // Get name for new directory
          directory newDir; // Create new directory
          newDir->name = newDirName; // Set name of new directory
          currentDir->dirList.push_back(newDir); // Add new directory to current directory list
      } else if (command == "rmdir") {
          string rmDir;
          ss >> rmDir; // Get directory name to remove
          vector<int> it = find(currentDir->dirList.begin(), currentDir->dirList.end(), rmDir); // Find directory in list
          currentDir->dirList.erase(it); // Remove directory from list
      } else if (command == "cd") {
          string cdDir;
          ss >> cdDir;
          if (cd == "..") { // Go up one directory
              currentDir = currentDir->preDir;
          } else {
              vectory<int> it;
              if (it = find(currentDir->dirList.begin(), currentDir->dirList.end(), cdDir) != currentDir->dirList.end()) { // Find if directory exists
                  currentDir->preDir = currentDir; // Set previous directory
                  currentDir = currentDir->dirList[it];
              } else {
                  cout << "Directory does not exist." << endl;
              }                
          }            
      } else if (command == "pwd") {
          string pwd = "/";
          directory temp = currentDir;
          while (temp != rootDir) {
              pwd = "/" + temp->name + pwd;
              temp = temp->preDir;
          }
          pwd = "/" + rootDir + pwd;
          cout << pwd << endl;
      } else if (command == "exit") {
          cout << "Exiting telnet..." << endl;
          checkRunning = true;
      } else {
          cout << "Invalid command" << endl;
      }

      /* Write to socket */
      write(connfd, buff, strlen(buff));

      //fprintf(stdout, "hello");

      /* Close the connection */
      close(connfd);
   }
}
