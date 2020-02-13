#ifndef __CMDARGTOKEN_H__
#define __CMDARGTOKEN_H__

#include "tokenizer.h"

class CmdArgToken : public Tokenizer {
	public:
		CmdArgToken() : Tokenizer() {} //parameters?	
		virtual string stringify(Tokenizer*);
		//maybe more functions?
};
#endif
