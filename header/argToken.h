#ifndef __ARGTOKEN_H__
#define __ARGTOKEN_H__

#include "tokenizer.h"

class ArgToken : public Tokenizer {
	public:
		ArgToken() : Tokenizer() {} //parameters?	
		virtual char const* stringify(string);
		virtual void evaluate();
		//maybe more functions?
};
#endif
