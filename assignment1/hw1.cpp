#include <iostream>
#include <deque>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string> 
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

pid_t glob_pid;
vector<pair<string, pid_t> > pidArray;

void  runForeground(char ** rgs, deque<char*> d) {
     pid_t pid;
     pid_t wait_pid;
     int   status;
     pid = fork();
     if (pid < 0) {     
          perror("Fork failed!!! \n");
          exit(1);
     }
     else if (pid == 0) {
     	  //char *argv[d.size()];
     	         
          if (execvp(*rgs, rgs) < 0) {    
               perror("ERROR!!!!\n");
               exit(1);
          }
     }
     else {
     	  if(strcmp(d.back(), "&") == 0) {
     	  	string str(*rgs);
     	  	pair<string, pid_t> add_pair (str, pid);
          	pidArray.push_back(add_pair);
          	wait_pid = waitpid(pid, &status, WNOHANG);
     	  }
     	  else{
          while (wait(&status) != pid);
       }
     }

}

void  runBackground(char ** rgs)
{
     pid_t pid;
     pid_t wait_pid;
     int   status;
     pid = fork();
     if (pid < 0) {   
          perror("Fork failed!!! \n");
          exit(1);
     }
     else if (pid == 0) {
     	  
     	  
     	  int compare = execvp(*rgs, rgs);
          if (compare < 0) {     
               perror("execvp failed!!!\n");
               exit(1);
          }
          else if(compare >= 0) {
          	
          }
     }
     else {                                 
       
               
     }

}
 
void back2fore(int id) {
	int status;
	pid_t wait_pid;
	pid_t pid;
	for (int i = 0; i < pidArray.size(); ++i)
	{	cout << "IN PID FOOR LOOP \n";
		cout << pidArray[i].second << " || " << id << "\n";
		if(pidArray[i].second == id) {
			cout << "PID MATCH FOUND \n";
			pidArray[i].first = pidArray[i].first + " FINISHED ";
			pid = pidArray[i].second;
			do {
      		wait_pid = waitpid(pid, &status, WUNTRACED);
    	  } while (!WIFEXITED(status) && !WIFSIGNALED(status));//wait_pid = waitpid(pidArray[i].second, &status, WNOHANG)       
               
		}
	}
}


void interruptCatch(int a) {
	kill(a,9);
}

int main() {
	signal(SIGINT, interruptCatch);
	while (1) {
		char** args = new char*[512];
		
		//cerr << "---------CHECK args BEFORE--------"<<endl;
		/*for(int j = 0; j < args.length() +1; j++) {
			//delete [] args;
				cout << args[j] << "\n";
		}*/
		deque<char*> cmdLine;
		
		printf("minish>");
		fflush(NULL);
 		string input;
 		string reciever;
		
		getline(cin, input);
 
		int input1 = 0;
		int first = 1;
		stringstream ss(input);
		while(ss >> reciever) {
			//cout << reciever << endl;
			char * adder = new char(reciever.length() + 1);
			strcpy(adder, reciever.c_str());
			cmdLine.push_back(adder);
		}
		
			
		if (cmdLine[0] != NULL) { 
			
			if (strcmp(cmdLine[0], "exit") == 0) {
				exit(0);
			}
			
			else if(strcmp(cmdLine[0], "cd") == 0) {
				//cout << "CD COMMAND \n";
				char * directory = cmdLine[1];
				if(chdir(const_cast<char*>(directory)) == -1) {
					perror("invalid directory!!! ");
				}
			}
			
			else if(strcmp(cmdLine[0], "listjobs") == 0) {
				for (int i = 0; i < pidArray.size(); ++i)
				{
					cout << "command: "<< pidArray[i].first<< " PID: " << pidArray[i].second<< "\n";
				}
			}
			else if(strcmp(cmdLine[0], "fg") == 0) {
				string num_string(cmdLine[1]);
				//string::size_type sz;
				istringstream buffer(num_string);
				int real_pid;
				buffer >> real_pid;
				cout << "PID IS:  " << cmdLine[1] << "  OTHER IS: " << real_pid << "\n";
				back2fore(real_pid);
			}
			else {
				              
     	 		if(strcmp(cmdLine.back(), "&") == 0) {
     	 			//cout << "in & comparison \n";
     	 			for(int i = 0; i < cmdLine.size()-1; i++) {
     	  				args[i] = cmdLine[i];
     	 			}
     	 		}
     	 		else {
     	 			//cout << "in non & thing!!!! \n";
     	 			for(int i = 0; i < cmdLine.size(); i++) {
     	  				args[i] = cmdLine[i];
     	 			}    
     	 		} 	
     	 		
        		runForeground(args, cmdLine);
        	}
        		

		}
		cmdLine.clear();
			
	}
	
		
		
	
	return 0;
}
	
 
