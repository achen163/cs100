#include <iostream>
#include "../header/executioner.h"

int Executioner::execute(const char* cmd, char* const* args) {
	pid_t pid = fork();
	if(pid < 0) {
		perror("forking failed");
	}
	if(pid == 0) {
		cout << "running child process" << pid << endl;
		if(execvp(cmd, args) == -1) 
			return 1;  // invalid command
	} 
	if(pid > 0) {
		if(waitpid(-1, NULL, 0) == -1) 
			perror("wait for child to finish");
		cout << "running parent process: " << pid << endl;
	}
	return 0; // execvp is sucessful
}
