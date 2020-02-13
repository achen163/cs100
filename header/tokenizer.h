#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <vector>
#include <string>
#include "executioner.h"

using namespace std; 

class Tokenizer : Executioner {
	public:
		Tokenizer() {} 
		
		virtual char* stringify(string token) = 0; 
		virtual bool evaluate(char* arr[]) = 0; 

};

#endif
