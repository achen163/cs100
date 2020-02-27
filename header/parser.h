#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "token.h"
#include "connector.h"

class parser {
	public:
		parser() {};
		void execute();
		void outputVector(vector<string>);
		void outputQueue(queue<Token*>);
		void outputPreorder(Token*);
		void outputInorder(Token*);
		void outputPostorder(Token*);
		void isConnector(string);
		bool hasMatch(vector<string>);
		bool leftParen(string);
		bool rightParen(string);
		Token* connector(string);

};
#endif



