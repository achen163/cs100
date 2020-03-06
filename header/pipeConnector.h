#ifndef __PIPE_CONNECTOR__
#define __PIPE_CONNECTOR__

#include "conncector.h"


class pipeConnector: public Connector {

public: 
	pipeConnector() : Connector() {left = NULL; right = NULL;}
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
