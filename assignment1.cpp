#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <deque>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int sigint(int a) {
	
}

void clearScreen() {
	printf("\033[2J\033[1;1H");
}

int excuteCommand() {

	int child_pid;
	int status;
	pid_t thisChPID;


	child_pid = fork();
	if(child_pid < 0 ) {
		fprintf(stderr, "Fork fails: \n");
		return 1;
	}
	else if(child_pid==0) {
		/* CHILD */
		execve(command.name, command.argv,0);
		printf("Child process failed\n");
		return 1;
	}
	else if(child_pid > 0) {
		/* PARENT */

		do {
			thisChPID = waitpid(child_pid, &status, WUNTRACED | WCONTINUED);
            if (thisChPID == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                //printf("exited, status=%d\n", WEXITSTATUS(status));
                return 0;
            } else if (WIFSIGNALED(status)) {
                printf("killed by signal %d\n", WTERMSIG(status));
            } else if (WIFSTOPPED(status)) {
                printf("stopped by signal %d\n", WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
                printf("continued\n");
            }
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		return 0;
	}

}

int checkInternalCommand() {

	if(strcmp("cd", command.argv[0]) == 0) {
		changeDir();
		return 1;
	}
	if(strcmp("clear", command.argv[0]) == 0) {
		clearScreen();
		return 1;
	}
	if(strcmp("self", command.argv[0]) == 0) {
		clearScreen();
		return 1;
	}

	return 0;
}



int main(int argc, char const *argv[])
{
	std::cerr "something \n ";
	std::string input; 
	getline(cin, input);
	string test;
	//cerr << input;
	stringstream ss;
	stringstream stream(input);
	deque input1;
	while(stream >> test) {
		input1.push_back(test)
	}
	while(1) {
		std::cerr "minish> ";
		//std::cout << input1[0]
		string test;
		string input;
		string app;
		char cmd  = getchar();
		getline(cin, input);
		app = cmd;
		test.append(app);
		test.append(input);
		if(cmd = '\n') continue;
		else {
			if((strcmp(test, "exit") == 0) || (strcmp(test, "quit") == 0))
				break;
			else if()
				//exit(0);
			//check input

		}
	}
	
	return 0;
}