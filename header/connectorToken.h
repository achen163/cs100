#ifndef __connectorToken_h__
#define __connectorToken_h__

#include <iostream>
#include "tokenizer.h"

class Connector: public Tokenizer{
	public:
		Connector() : Tokenizer() { }
		virtual string stringify(Tokenizer*);
		virtual bool evaluate(Tokenizer*, char* arr[]);
		 			
};



#endif
