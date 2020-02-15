#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <vector>
#include <string>
#include "executioner.h"

using namespace std; 

class Tokenizer {
	public:
		Tokenizer() {} 
		
		virtual void stringify() = 0; 
		virtual bool evaluate() = 0; 
		virtual void parser() = 0;
		virtual string returnv1String() = 0; //just for unit tests
		virtual string returnv2String() = 0; 
		
};

#endif
