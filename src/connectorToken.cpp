#include "../header/connectorToken.h"
#include <boost/tokenizer.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>

bool ConnectorToken::evaluate() {
	Executioner exe;
	char* array [v3.size() + 1];
	for(unsigned i = 0; i < v3.size(); ++i) {
		array[i] = v3.at(i);
	}

	array[v3.size()] = NULL;

	if(exe.execute(array) == 1)
		return false;
	return true;
}

void ConnectorToken::stringify() {
	for(unsigned i = 0; i < v2.size(); i++) 
		v3.at(i) = (char*)v2.at(i).c_str();
}


void ConnectorToken::parser() {
	int qIndex = 0;
	int pIndex = 0;
	for(unsigned i = 0; i < userinput.size(); i++) {
		if(userinput.at(i) == '\"') {
			qIndex = i;
			break;
		}
	}
	for(unsigned j = 0; j < userinput.size(); j++) {
		if(userinput.at(j) == '#') 
			pIndex = j;
	}
	if(pIndex < qIndex) 
		userinput.resize(pIndex); 	
	
	//boost
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep(" ");
	tokenizer tok(userinput, sep);
	for(const auto& tk : userinput){
		v1.push_back((char*)tk);
	}
	
	//parsing
	for(unsigned i = 0; i < v1.size(); i++) {
		int numCmdArgs = 0;
		string connector = "";
		while(v1.at(i) != ";" || v1.at(i) != "||" || v1.at(i) != "&&") {
			v2.push_back(v1.at(i));
			numCmdArgs++;
			if(i == v1.size() - 1) 
				break; //if last element of the string.		
		i++;
		}
		

		connector = v1.at(i); 
		
		stringify();
		
		if(connector == "&&") {
			if(!(evaluate())) 
				break;
		}
		else if(connector == "||") {
			if(evaluate())
				break;
		}
		else if(connector == ";")
			evaluate();
		else 
			evaluate();
	
	//clear vectors 
	v2.clear();
	v3.clear();				
	}
}
