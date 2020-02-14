#include <iostream>
#include "../header/executioner.h"

int Executioner::execute(char* args[]) {
	pid_t pid = fork();
	int isValid = 0;
	if(pid < 0) {
		perror("forking failed");
	}
	if(pid == 0) {
		cout << "running child process" << pid << endl;
		if(execvp(args[0], args) == -1) {
			const char* e = "";
			perror(e);
			isValid = 1;
			exit(1);
		}
	} 
	if(pid > 0) {
		if(waitpid(-1, NULL, 0) == -1) 	perror("wait for child to finish"); 
		if(isValid == 1) {		
			const char* var = args[0];
                	string cmdString(var);
                	string errorMsg = "-bash: " + cmdString + ": command not found";
			return 1;
		}
		return 0;
	}	
	 // execvp is sucessful
	
}
