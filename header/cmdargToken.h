#ifndef __ARGTOKEN_H__
#define __ARGTOKEN_H__

#include "tokenizer.h"

class CmdArgToken : public Tokenizer {
	public:
		CmdArgToken() : Tokenizer() {} //parameters?	
		virtual string stringify(Tokenizer*);
		virtual bool evaluate();
		//maybe more functions?
};
#endif
