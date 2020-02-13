#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <vector>
#include <string>
#include "executioner.h"

using namespace std; 

class Tokenizer {
	public:
		Tokenizer() {} 
		
		virtual string stringify(string token) = 0; 
		virtual bool evaluate(char* arr[]) = 0; 

//initialize this in the constructor as an array (this array holds arguments)
};

#endif
