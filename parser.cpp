#include <iostream>
#include <string>


using namespace std;



//this function is written to check if valid command or not
bool validfunction(string argv, char *list[] ) {
	bool valid = false;
	for(int i =0; i < 5; i++) { //will change number of i's to number of commands
		if(argv == list[i]){
			valid == true;
			break;
		}							
       }
		return valid;
}



int main () {

char* listofcommands[5];
listofcommands[0] = "ls";
listofcommands[1] = "echo";
//assuming 5 commands, each max string size 10 


string command;
cin >> command;


if(validfunction(command, listofcommands))
{
	if (command == "echo") {
		//code out what echo supposed to do

	
	}	
}


return;

}

