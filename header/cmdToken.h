#ifndef __CMDTOKEN_H__
#define __CMDTOKEN_H__

#include "tokenizer.h"

class CmdToken : public Tokenizer {
	public:
		CmdToken() : Tokenizer() {} //parameters?
		virtual char* const* stringify(const char*);
		virtual bool evalute();
		//maybe more functions 
};
#endif
