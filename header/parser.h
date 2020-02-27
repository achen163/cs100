#ifndef __PARSER_H__
#define __PARSER_H__

#include <vector>
#include <stack>
#include <queue>
#include "cmd.h"
#include <iostream>
#include <cstring>
#include "connector.h"
#include "andConnector.h"
#include "semiConnector.h"
#include "orConnector.h"
#include "token.h"
#include "parser.h"
#include <boost/tokenizer.hpp>
#include <iterator>

class Parser {
	public:
		Parser() {};
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



