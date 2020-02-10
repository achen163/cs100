#ifndef __CMDTOKEN_H__
#define __CMDTOKEN_H__

#include "tokenizer.h"

class CmdToken : public Tokenizer {
	public:
		CmdToken() : Tokenizer() {} //parameters?
		virtual const char* stringify(string);
		virtual void evalute();
		//maybe more functions 
};
#endif
