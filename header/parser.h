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
#include "pipeConnector.h"
#include "token.h"
#include "parser.h"
#include <boost/tokenizer.hpp>
#include <iterator>

class Parser {
	public:
		Parser() {};
		void execute();
		bool isConnector(string);
		bool isSemiColon(string);
		bool hasMatch(vector<string>);
		bool leftParen(string);
		bool rightParen(string);
		Token* connector(string);

};
#endif



