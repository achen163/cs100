#ifndef __CMDARGTOKEN_H__
#define __CMDARGTOKEN_H__

#include "tokenizer.h"
#include "connectorToken.h"

class CmdArgToken : public Tokenizer {
	public:
		CmdArgToken() : Tokenizer() {} //parameters?	
		virtual char* stringify(string token);
		//maybe more functions?
	private:
		Tokenizer* tokenPtr;
};
#endif
