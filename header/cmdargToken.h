#ifndef __CMDARGTOKEN_H__
#define __CMDARGTOKEN_H__

#include "tokenizer.h"

class CmdArgToken : public Tokenizer {
	public:
		CmdArgToken(Tokenizer* tokenPtr) : Tokenizer() { this->tokenPtr = tokenPtr; }
		virtual bool evaluate() { return tokenPtr->evaluate(); }
		virtual char* stringify() { return 

        private:
		Tokenizer* tokenPtr;
};
#endif
