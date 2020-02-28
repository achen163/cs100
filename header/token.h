#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>

using namespace std;

class Token {
        public:
                Token() { left = nullptr; right = nullptr; }
               
                virtual void setLeft(Token*) = 0;
                virtual void setRight(Token*) = 0;
                virtual string item() = 0;
                virtual bool evaluate() = 0;
        private:
                Token* left;
                Token* right;
};
#endif

