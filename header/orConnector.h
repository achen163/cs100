#ifndef __ORCONNECTOR_H__
#define __ORCONNECTOR_H__

#include "connector.h"

class orConnector : public Connector {
public:
        orConnector() : Connector() {left = NULL; right = NULL;}
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

