#ifndef __ARGTOKEN_H__
#define __ARGTOKEN_H__

#include "../header/tokenizer.h"

char* const* ArgToken::stringify(Tokenizer* token) {	
	int numArgs = 0;	
	if(token->tokencouner == 2) {
		int i = 1;
		while(token->tokens.at(i) != ";" && 
		      token->tokens.at(i) != "||" &&
		      token->tokens.at(i) != "&&") {
			if(i != tokens.size()-1) 
				numArgs++;
		i++;
		}
	}
	char* const* args[numArgs];
	int argIndex = 0;
	int argBegin = 1; //needs to update after each connector somehow
	for(unsigned i = argBegin; i < numArgs + argBegin; i++) {
		args[argIndex] = token->stringify(token->tokens.at(i)); //fill the array
	}
	token->evaluate(args);
	return args; //don't  know what to do with this really..
}		
		
	

#endif
