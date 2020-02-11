#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <vector>

using namespace std; 

class Tokenizer : public Executioner {
	public:
		Tokenizer(vector<const char*> tokens) {this->tokens = tokens; }

		virtual const char* stringify(string) = 0; //convert to const char* (this is for the first parameter in the execute function)
		virtual void evaluate() = 0; //not sure about the return type 
	protected:
		char* const* arg;
		const char* command;		  
		vector<const char*> tokens;
		int tokencounter = 0; 
//initialize this in the constructor as an array (this array holds arguments)
};

#endif
