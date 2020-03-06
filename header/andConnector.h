#ifndef __ANDCONNECTOR_H__
#define __ANDCONNECTOR_H__

#include "connector.h"

class andConnector : public Connector {

public:
        andConnector() : Connector() {left = NULL; right = NULL;}
        string item();
        bool evaluate(int, int);
	bool evaluate2();
        void setLeft(Token*);
        void setRight(Token*);

private:
Token* right;
Token* left;

};
#endif


