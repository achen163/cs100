#ifndef __CONNECTORTOKEN_H__
#define __CONNECTORTOKEN_H__

#include <iostream>
#include "tokenizer.h"

class ConnectorToken: public Tokenizer {
	public:
		ConnectorToken(string line) : Tokenizer() { this->userInput = line; }
		//ConnectorToken(vector<string> t) { tokens = t; }
		virtual char* stringify(string token) { return (char*)token.c_str(); }
		virtual bool evaluate(char* arr[]) {}; 
		void tokenizer(ConnectorToken*);
                string getStr() { return userInput; }
		vector<string> getTokens() { return tokens; }
		string setElement(string element) { this->element = element; }
	
        //protected:
                vector<string> tokens;
                string userInput;
                string element;
	
		 			
};



#endif
