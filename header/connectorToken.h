#ifndef __CONNECTORTOKEN_H__
#define __CONNECTORTOKEN_H__

#include <iostream>
#include "tokenizer.h"

class ConnectorToken: public Tokenizer {
	public:
		ConnectorToken(string userinput) : Tokenizer(){ this->userinput = userinput; } 
		virtual void stringify();
		virtual bool evaluate();
		void parser(string);
		 
	private:
	vector<char*> v1;
	vector<string>v2;
	vector<char*>v3;
	string userinput;               
};
#endif
