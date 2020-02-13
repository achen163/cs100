#ifndef __CMDARGTOKEN_H__
#define __CMDARGTOKEN_H__

#include "tokenizer.h"

class CmdArgToken : public Tokenizer {
	public:
		
		CmdArgToken(string line, Tokenizer* t) : Tokenizer() { this->userInput = line; tokenPtr = t; }
		
		virtual char* stringify(string, Tokenizer*);
		void tokenizer(CmdArgToken*);
		string getStr() { return userInput; }
                vector<string> getTokens() { return tokens; }
                string setElement(string element) { this->element = element; }

        private:
                vector<string> tokens;
                string userInput;   
                string element;
		Tokenizer* tokenPtr;
};
#endif
