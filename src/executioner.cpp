#include <iostream>
#include "../header/executioner.h"

int Executioner::execute(char* args[]) {
	pid_t pid = fork();
	if(pid < 0) {
		perror("forking failed");
	}
	if(pid == 0) {
		cout << "running child process" << pid << endl;
		if(execvp(args[0], args) == -1) {
			perror("execution error. command not found");
			exit(1);
		}
	} 
	if(pid > 0) {
		if(waitpid(-1, NULL, 0) == -1) 
			perror("wait for child to finish");
		else {
			cout << "-bash: " + args[0] + ": command not found" << endl;
			return 1;
		}
	}
	return 0; // execvp is sucessful
}
