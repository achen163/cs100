#include <iostream>
#include "../header/tokenizer.h"
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>

using namespace std;
using namespace boost;


void Tokenizer::tokenizer(Tokenizer* token){
	string userString = token->getStr();
	for (int i=0; i < userString.size(); i++) {
		if (userString.at(i) == '#')
			userString.resize(i);
	}
	
	vector<string> tokenvec; 

	//tokenize with space as dilmeter 
	char_separator<char> sep1(" ");
	tokenizer<char_separator<char>> semitokens(userString, sep1);
	for (const auto& tk : semitokens){
		tokenvec.push_back(tk);		
		
	}
	//ArgToken args = new ArgToken(tokenvec);
}

	


	
