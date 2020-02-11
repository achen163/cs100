#include <iostream>
#include "../header/tokenizer.h"
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>

using namespace std;
using namespace boost;

//maybe this is main ???

int main() {
	string line;  
	getline(cin, line); //takes in whole line entered
	for (int i=0; i < line.length() ;i++) {
		if (line.at(i) == '#')
			line.resize(i);
	}//this will be my pound checker, deletes everything after pound
	
	//string templine = line; //might need cause im using tokenizer twice?
	
	vector<const char*> tokenvec; 

	 //count the total amount of tokens
	char_separator<char> sep1(" ");
	tokenizer<char_separator<char>> semitokens(line, sep1);
	for (const auto& tk : semitokens){
		tokenvec.pushback(tk);		
		
	}
	Tokenizer token(tokenvec);
	
	
return 0;	
}
		


/*
	char_separator<char> sep(" "); //delimeter of space
	tokenizer<char_separator<char>> tokens(line, sep);
	for (const auto& t : tokens) {
		countertoken++;
		if (tokencounter ==1) {
			cmdToken command(t);
		}
		if (validConnector) {
			countertoken == 0;
		}	
		else 
		argToken argument(t);
	}

} 
	
*/



	
