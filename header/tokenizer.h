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

};

#endif
