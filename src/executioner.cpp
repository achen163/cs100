#include <iostream>
#include "../header/executioner.h"

int Executioner::execute(char* args[]) {
	pid_t pid = fork();

	if(pid < 0) {
		perror("forking failed");
	}
	if(pid == 0) {
		//cout << "running child process" << pid << endl;
		//if (args[0] == "exit"){ exit(1);}

		if(execvp(args[0], args) == -1) {
			const char* temp = "";
			const char* var = args[0];
   	                string cmdString(var);
        	        string errorMsg = "-bash: " + cmdString + ": command not found";
			cout << errorMsg << endl;
			exit(1);
			
		}
	} 
	if(pid > 0) {
		int status = 0;
		int *statusPtr = &status;
		if(waitpid(pid, statusPtr, 0) == -1) 	perror("wait for child to finish"); 		 
		
		if(WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
		return 0;
	}
	
}
