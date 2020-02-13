#ifndef __CONNECTORTOKEN_H__
#define __CONNECTORTOKEN_H__

#include <iostream>
#include "tokenizer.h"

class ConnectorToken: public Tokenizer {
	public:

		ConnectorToken(string userinput) : Tokenizer(){this->userinput = userinput};  
		virtual char* stringify();
		virtual bool evaluate();
		char* parser(string userinput);
		 


	private:
	vector<string> v1;
	vector<string>v2;
	vector<char*const*>v3;
	string userinput;               
};
#endif
