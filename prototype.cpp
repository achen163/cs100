#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

void prototype(char*);

int main() {
   char* args[2];
   string ls = "ls";
   args[0] = (char*)ls.c_str();
   args[1] = NULL;
   pid_t pid = fork();
   if(pid < 0) {
	perror("Fork failed");
   }
   if(pid == 0) {
	cout << "child:" << pid << endl;
	if(execvp(args[0], args) == -1) {
		perror("exec");
	}
   }
   if(pid > 0) {
	if(waitpid(-1, NULL, 0) == -1) {
		perror("wait");
	}
	cout << "parent:" << pid << endl;
   }
 	
   return 0;
}
