#include "../header/cmd.h"
#include "fstream"

#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

Cmd::Cmd(vector<string> t) {
        for(unsigned i = 0; i < t.size(); ++i) {
                commands.push_back(t.at(i));
        }
}

bool Cmd::execute() { //helper for evaluate
        int status = 0;
	pid_t pid = fork();
	pid_t wait;
	if(pid < 0) {
		perror("forking child process failed");
	}
	else if(pid == 0) {
		unsigned arraySize = commands.size() + 1;
		char* args[arraySize];
		for(unsigned i = 0; i < arraySize - 1; ++i) {
			args[i] = (char*)(commands.at(i).c_str());
		}
		args[arraySize - 1] = NULL;
		
		if(execvp(args[0], args) < 0) {
			cout << "execvp failed" << endl;
			exit(1);
		}
	}
	else {
		wait = waitpid(pid, &status, 0);
		if(wait == -1) {
			cout << "waitpid error" << endl;
			exit(EXIT_FAILURE);
		}
		if(WEXITSTATUS(status) == 0) {
			return true;
		}
	}
}

        /*char* args[commands.size() + 1];
        for(unsigned i = 0; i < commands.size(); ++i) {
                args[i] = (char*)(commands.at(i).c_str());
        }

        args[commands.size()] = NULL;

        if(pid < 0)
                perror("forking failed");
        else if(pid == 0) { //child
                if(execvp(args[0], args) == -1) { //not sure if args[0] is the only command
                        const char* temp = "";
                        const char* var = args[0];
                        string cmdString(var);
                        cout << "-bash: " + cmdString + ": command not found" << endl;
                        exit(1);
                }
        }
        else { //parent
                int status = 0;
                int *statusPtr = &status;
                if(waitpid(pid, statusPtr, 0) == -1) {
                        perror("wait for child to finish");
                }
                if(WIFEXITED(status) == 0) {
 		   	    return true ; //basically 1
                }
               
        }
	return false;*/	



bool Cmd::evaluate() {
        if(commands.at(0) == "exit")  exit(0); //take care of exit

        if(commands.at(0) == "test" || commands.at(0) == "[") {
                if(commands.at(0) == "[") { //check for brackets first since it's ta the beginning
                        if(commands.at(commands.size()-1) != "]") { //if there's no brackets. it's incorrect
                                cout << "The brackets are incorrect!" << endl;
                                return false;
                        }
                }

                if(commands.at(1) == "-f") {
                        struct stat i;
                        const char* cmd = commands.at(2).c_str();
                        if(i.st_mode & S_IFREG) {
                                cout << "(True)" << endl;
                                return true;
                        }

                        else if(stat((char*)(cmd), &i) != 0) { //if path is false
				
        cout << "(False)" << endl;
                                return false;
                        }

                        else {
                                cout << "(False)" << endl;
                                return false;
                        }
                }
  else if(commands.at(1) == "-e") {
                        struct stat i;
                        const char* cmd = commands.at(2).c_str();

                        if(stat((char*)(cmd), &i) != 0) { //if path is false
                                cout << "(False)" << endl;
                                return false;
                        }

                        else {
                                cout << "(True)" << endl;
                                return true;
                        }
                }

                else if(commands.at(1) == "-d") {
                        struct stat i;
                        const char* cmd = commands.at(2).c_str();
                        if(i.st_mode & S_IFDIR) {
                                cout << "(True)" << endl;
                                return true;
                        }
                        else if(stat((char*)(cmd), &i) != 0) {
                                cout << "(False)" << endl;
                                return false;
                        }
                        else {
                                cout << "(False)" << endl;
                                return false;
                        }
                }
                else {
                        struct stat i;
                        const char* cmd = commands.at(1).c_str();
                        if(stat((char*)(cmd), &i) != 0) {
                                cout << "(False)" << endl;
                                return false;
                        }
                        else {
                                cout << "(True)" << endl;
                                return true;
                        }
                }
        }
	return execute();    
}

string Cmd::item() {
        string ele = "";
        for(unsigned i = 0; i < commands.size() - 1; ++i)
                ele = ele + commands.at(i) + " ";
        ele = ele + commands.at(commands.size() - 1);
        return ele;
}

void Cmd::setLeft(Token* leftNode) {} //set empty. not gonna use here
void Cmd::setRight(Token* rightNode) {}

void Cmd::setInput(string in) { input = in; }
void Cmd:: setOutput(string out) { output = out; }

