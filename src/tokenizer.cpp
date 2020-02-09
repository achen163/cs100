#include <iostream>
#include "tokenizer.h"
#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

//maybe this is main ???

int main() {
	string line;  
	cin >> line; //takes in whole line entered
	char_separator<char> sep(" "); //delimeter of space
	tokenizer<char_separator<char>> tokens(line, sep);
	 
	



}




