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

        
bool Cmd::evaluate(int inputBit, int outputBit) {
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

                        if(stat((char*)(cmd), &i) != 0) { //if path is false
        			cout << "(False)" << endl;
                                return false;
                        }
			else if(i.st_mode & S_IFREG) {
                                cout << "(True)" << endl;
                                return true;
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
                        
                        if(stat((char*)(cmd), &i) != 0) {
                                cout << "(False)" << endl;
                                return false;
                        }
			else if(i.st_mode & S_IFDIR) {
                                cout << "(True)" << endl;
                                return true;
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
	else {
	int status = 0;
        pid_t pid = fork();
        pid_t wait;
        if(pid < 0) {
                perror("forking failed");
		exit(1);
        }
        else if(pid == 0) {
		
		//add piping and redirection here
		//first check if redirector is at the end, this is not valid
		if(isRedirector(commands.at(commands.size()-1))) { 
			cout << "Error when trying to use a redirector\n";
			return false;
		}
	
		vector<string> theCommands; //vector without redirectors
		unsigned z = 0;
		for(z = 0; z < commands.size(); ++z) {
			if(isRedirector(commands.at(z)) == false) {
				theCommands.push_back(commands.at(z));
			}
			else break;
		}
		
		for(unsigned i = 0; i < commands.size(); ++i) {
			if(isRedirector(commands.at(i))) { 
				if(commands.at(i) == ">") setOutput(commands.at(i+1)); 
				else if(commands.at(i) == ">>") {
					setOutput(commands.at(i+1));
				}
				else if(commands.at(i) == "<") {
					setInput(commands.at(i+1));
				}
				else {
					cout << "Error when trying to use a redirector\n";
				}
			}
		}

		char* arguments[theCommands.size()+1];
		
		for(unsigned x = 0; x < theCommands.size(); ++x) 
			arguments[x] = (char*)(theCommands.at(x).c_str());

		

		//set last char to nullptr
		arguments[theCommands.size()] = nullptr;

		//checks if input and outpufiles are empty
		//if not empty then we check which redirector is being used
		if(input.empty() == false && output.empty() == false) {
			bool isInput = false;
			for(unsigned i = 0; i < commands.size(); ++i) {
				if(commands.at(i) == ">") 
					isInput = true;
			}
			if(isInput) {
				int ifDetail = open(input.c_str(), O_RDONLY);
				int ofDetail = open(output.c_str(), O_TRUNC | O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
				
				if(ofDetail < 0) { 
					cout << "Error. Cannot open the output file" << endl;
					return false;
				}
				else if(ifDetail < 0) {
					cout << "Error. Cannot open the input file" << endl;
					return false;
				}
				dup2(ifDetail, STDIN_FILENO);
				dup2(ofDetail, STDOUT_FILENO);
				close(ifDetail); 
				close(ofDetail); 
				dup2(inputBit, 0); //put input in memory 0
				dup2(outputBit, 1); //put output in memory 1
				if(inputBit != 0) 
					close(inputBit); //close input since it's not 0
				else if(outputBit != 1)
					close(outputBit);
				if(execvp(*arguments, arguments) < 0) {
					cout << "Error: execvp failed" << endl;
					exit(1);
				}
			}
			else { 
				int ifDetail = open(input.c_str(), O_RDONLY);
				int ofDetail = open(output.c_str(), O_APPEND | O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
			
				if(ofDetail < 0) {
                                        cout << "Error. Cannot open the output file" << endl;
					return false;
                                }
                                else if(ifDetail < 0) {
                                        cout << "Error. Cannot open the input file" << endl;
                                        return false;
                                }

				
				dup2(ifDetail, STDIN_FILENO); 
				dup2(ofDetail, STDOUT_FILENO);
				close(ifDetail);
				close(ofDetail);
				dup2(inputBit, 0);
				dup2(outputBit, 1);
				if(inputBit != 0) close(inputBit); 
				else if(outputBit != 1) close(outputBit);
				
				if(execvp(*arguments, arguments) < 0) {
					cout << "Error: execvp failed" << endl;
					exit(1);
				}
			}
		}
    	        else if(output.empty() == false) {
                	bool isInput = false;
                	for(unsigned i = 0; i < commands.size(); ++i) {
                        	if(commands.at(i) == ">") //takes case of the '>' redirector
                                isInput = true;
                 	}
                	if(isInput) {
				int fileDetail = open(output.c_str(), O_TRUNC | O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
				if (fileDetail < 0) {
					cout << "Error. Cannot open the file" << endl;
					return false;
				}
				dup2(fileDetail, STDOUT_FILENO);
				close(fileDetail);
				dup2(inputBit, 0);
				dup2(outputBit, 1);
				
				if(inputBit != 0) close(inputBit);
				else if(outputBit != 1) close(outputBit);
				
				if(execvp(*arguments, arguments) < 0) {
					cout << "Error: execvp failed" << endl;
					exit(1);
				}	
			}
			else {	//this takes care of ">>" redirector
				int fileDetail = open(output.c_str(), O_APPEND | O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
				if (fileDetail < 0) {
					cout << "Error. Cannot open the file" << endl;
					return false;
				}
				dup2(fileDetail, STDOUT_FILENO);
				close(fileDetail);
				dup2(inputBit, 0);
				dup2(outputBit, 1);
				
				if(inputBit != 0) close(inputBit);
				else if(outputBit != 1) close(outputBit);
				
				if(execvp(*arguments, arguments) < 0) {
					cout << "Error: execvp failed" << endl;
					exit(1);
				}
			}	
			
		} //this takes care of '<' redirector
		else if(input.empty() == false) {
			int fileDetail = open(input.c_str(), O_RDONLY);
			if(fileDetail < 0) {
 
				cout << "Error. Cannot open the file" << endl;
				return false;

			}
			dup2(fileDetail, STDIN_FILENO);
                         close(fileDetail);
                         dup2(inputBit, 0);
                         dup2(outputBit, 1);


                                if(inputBit != 0) close(inputBit);
                                else if(outputBit != 1) close(outputBit);

                                if(execvp(*arguments, arguments) < 0) {
   
                                        cout << "Error: execvp failed" << endl;
                                        exit(1);
   
                                 }
               	}
		//this else statement is for userinput but with no redirector			
                else {
			unsigned arraySize = commands.size() + 1;
                	char* args[arraySize];
                	for(unsigned i = 0; i < arraySize - 1; ++i) {
        
	                	args[i] = (char*)(commands.at(i).c_str());
        
	        	}
        
	        	args[arraySize - 1] = nullptr;

			if(inputBit != 0) close(inputBit);
			else if(outputBit != 1) close(outputBit);

               		if(execvp(args[0], args) < 0) {
                        	cout << "-bash: " + static_cast<string>(args[0]) + ": command not found" << endl;
                        	exit(1);
                	}
		}
        }

        else {
                wait = waitpid(pid, &status, 0);
                if(wait == -1) {
                        cout << "waitpid error" << endl;
                        exit(1);
                }
                if(WEXITSTATUS(status) == 0) {
                        return true;
                }
        }

	}
	
	return false;    
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

void Cmd::setInput(string inputFile) { 
	input = inputFile;
}

void Cmd::setOutput(string outputFile) {
	output = outputFile;
}

bool Cmd::isRedirector(string inputFromUser) {
	if(inputFromUser == ">" || inputFromUser == ">>" || inputFromUser == "<")
                return true;
        return false;
}

bool Cmd::evaluate2() {
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

                        if(stat((char*)(cmd), &i) != 0) { //if path is false
                                cout << "(False)" << endl;
                                return false;
                        }
                        else if(i.st_mode & S_IFREG) {
                                cout << "(True)" << endl;
                                return true;
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

                        if(stat((char*)(cmd), &i) != 0) {
                                cout << "(False)" << endl;
                                return false;
                        }
                        else if(i.st_mode & S_IFDIR) {
                                cout << "(True)" << endl;
                                return true;
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
	else {
        int status = 0;
        pid_t pid = fork();
        pid_t wait;
        if(pid < 0) {
                perror("forking failed");
		exit(1);
        }
	else if(pid == 0) {
	         unsigned arraySize = commands.size() + 1;
                 char* args[arraySize];
                 for(unsigned i = 0; i < arraySize - 1; ++i) {
       		          args[i] = (char*)(commands.at(i).c_str());
                 }
                        args[arraySize - 1] = nullptr;

              

                        if(execvp(args[0], args) < 0) {
                                cout << "-bash: " + static_cast<string>(args[0]) + ": command not found" << endl;
                                exit(1);
                        }
        }
	  else {
                wait = waitpid(pid, &status, 0);
                if(wait == -1) {
                        cout << "waitpid error" << endl;
                        exit(1);
                }
                if(WEXITSTATUS(status) == 0) {
                        return true;
                }
        }

        }

        return false;
}



		
		

