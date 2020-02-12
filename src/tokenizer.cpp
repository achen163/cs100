#include <iostream>
#include "../header/tokenizer.h"
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>

using namespace std;
using namespace boost;


void Tokenizer::tokenizer(Tokenizer* token){
	string userString = token->getStr();
	int qIndex = 0;
	int pIndex = 0;
	for (int i=0; i < userString.size(); i++) {
		if(userString.at(i) == '\"') {
			qIndex = i;
			break;
		}
	}
	for (int j =0; j < userString.size(); j++){
		if (userString.at(j) == '#');
			pIndex = j;
	}			
		if (pIndex < qIndex) {
			 
			userString.resize(pIndex);
		}
	
	vector<string> tokenvec; 

	//tokenize with space as dilmeter 
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep(" ");
	tokenizer tok(userString, sep);
	for (const auto& tk : tokens){
		tokenvec.push_back(tk);		
		
	}
	//ArgToken args = new ArgToken(tokenvec);
}

	


	
