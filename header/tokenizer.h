#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <vector>
#include <string>
#include "executioner.h"

using namespace std; 

class Tokenizer : public Executioner {
	public:
		Tokenizer() {} 
		Tokenizer(string input) { userInput = input; }
		
		virtual string stringify(Tokenizer*) = 0; 
		virtual bool evaluate(Tokenizer*, char* arr[]) = 0; 
		void tokenizer(Tokenizer*);
		string getStr() { return userInput; } 
	protected:		  
		vector<string> tokens;
		string userInput;
		string element;
//initialize this in the constructor as an array (this array holds arguments)
};

#endif
