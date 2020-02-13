#ifndef __CONNECTORTOKEN_H__
#define __CONNECTORTOKEN_H__

#include <iostream>
#include "tokenizer.h"

class ConnectorToken: public Tokenizer {
	public:
		ConnectorToken(string line) : Tokenizer() { this->userInput = line; }
		virtual char* stringify(sting token) { return (char*)token.c_str(); }
		virtual bool evaluate(char* arr[]) {}; 
		void tokenizer(ConnectorToken*);
                string getStr() { return userInput; }
        protected:
                vector<string> tokens;
                string userInput;
                string element;
	
		 			
};



#endif
