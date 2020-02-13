#ifndef __CONNECTORTOKEN_H__
#define __CONNECTORTOKEN_H__

#include <iostream>
#include "tokenizer.h"

class ConnectorToken: public Tokenizer {
	public:
		virtual char* stringify(string token) { return (char*)token.c_str(); }
		virtual bool evaluate(char* arr[]); 
               
};
#endif
