#ifndef __ARGTOKEN_H__
#define __ARGTOKEN_H__

#include "../header/tokenizer.h"

string  ArgToken::stringify(Tokenizer* token) {	
	for (unsigned i =0; i < token->tokens.size();i++ ) {
	int numArgs = 0;
	string connector = " ";	

		while(token->tokens.at(i) != ";" && 
		      token->tokens.at(i) != "||" &&
		      token->tokens.at(i) != "&&") {
			if(i != token->tokens.size()-1) 
				numArgs++;
		i++;
		}
		
		connector = token->tokens.at(i);

	char* array[numArgs+1] ;
		int j = 0;
		int index = numArgs+1;
		while(numArgs > 1) {
			token->element = tokens.at(j);
			array[j] == tokens.at(j)->stringify(token);
			j++;
			numArgs--;
		}
		array[index] = NULL;
		
	if (connector == "&&" }{
		if (!token->evalate(array)){	
		break;	
		}

	}
	else if (connector == "||") {
		if (token->evaluate(array)){
			break;
		}	
	}
	else if(connector == ";"){
		token->evaluate(array);	
	}
	else {
		token->evaluate(array);
	}
	
}
	

#endif
