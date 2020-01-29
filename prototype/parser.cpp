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

bool isconnector(string argv) {
	
if (argv == "&" || argv == "|"){
		return true;
	}
else return false;
}
//this is my function to check if the string passed in has an &. need to combine with stuff written in main where i checked the first & and if there is a second &

bool issemicolon(string argv){

	if (argv == ";") {
		return true;
	}	
else {
return false;
}
}

int main () {

//planning to match each command entered to the list of commands
char* listofcommands[5];
listofcommands[0] = "ls";
listofcommands[1] = "echo";
//assuming 5 command will add rest in later


string command;
cin >> command;


//made a list to match for connectors
char* listofconnectors[2];
listofconnectors[0] = "&&";
listofconnectors[1] = "||";
listofconnectors[2] = ";";

validfunction(command, listofcommands);

//make function is connector, is semicolon
//checks if is && or is ||
if (isconnector) {
	string uptoconnector;
	
}


for(int i =1; i < command.size(); i++){
	if (command.at(i) == '&' || command.at(i) == '|' ) {
		char temp = command.at(i);
		if(command.at(i+1)== temp){
			//code out what the and or or is supposed to do
		} 
}


}


return 0 ;

}

