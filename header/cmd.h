#ifndef __CMD_H__
#define __CMD_H__

#include <string>
#include <vector>

#include "token.h"

class Cmd : public Token {
        public:
                Cmd() : Token() {}
                Cmd(vector<string>);
                bool execute();
                void setLeft(Token*);
                void setRight(Token*);
                void setInput(string);
                void setOutput(string);
                bool evaluate();
                string item();
         private:
                string cmdName;
                vector<string> commands;
                string input;
                string output;

};
#endif

