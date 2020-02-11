#ifndef __connectorToken_h__
#define __connectorToken_h__

#include <iostream>
#include "tokenizer.h"

class Connector: public Tokenizer{
	public:
		Connector() : Tokenizer() { }
		virtual char* const* stringify(const char*);
		virtual bool evaluate();
		 			
};



#endif
