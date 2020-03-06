#ifndef __SEMICONNECTOR_H__
#define __SEMICONNECTOR_H__

#include "connector.h"

class semiConnector: public Connector {

public:
        semiConnector() : Connector() {left = NULL; right = NULL; }
        string item();
        bool evaluate(int,int);
	bool evaluate2();
        void setLeft(Token* );
        void setRight(Token* );

private:
Token* left;
Token* right;



};
#endif


