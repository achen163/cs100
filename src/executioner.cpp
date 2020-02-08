#include <iostream>
#include "executioner.h"

int Executioner::execute(const char* args) {
	pid_t pid = fork();
	if(pid < 0) {
		perror("forking failed");
	}
	if(pid == 0) {
		cout << "running child process" << pid << endl;
		value = execvp(args[0], args);
		if(execvp(args[0], args == -1)) 
			return 0;  // invalid command
	} 
	if(pid > 0) {
		if(waitpid(-1, NULL, 0) == -1) 
			perror("wait for child to finish");
		cout << "running parent process: " << pid << endl;
	}
	return 1; // execvp is sucessful
}
