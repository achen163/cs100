#ifndef __CMD_H__
#define __CMD_H__

#include <string>
#include <vector>

#include "token.h"

class Cmd : public Token {
        public:
                Cmd() : Token() {}
                Cmd(vector<string>);
               
                void setLeft(Token*);
                void setRight(Token*);
                bool evaluate(int inputFile, int outputFile);
		bool evaluate2();
                string item();
		void setInput(string);
		void setOutput(string);
		bool isRedirector(string);
         private:
                string cmdName;
                vector<string> commands;
                string input;
                string output;

};
#endif

