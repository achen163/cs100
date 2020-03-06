#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "cmd.h"
#include "string"

class Connector : public Token {
        public:
                virtual string item() = 0;
                virtual void setLeft(Token*) = 0;
                virtual void setRight(Token*) = 0;
                virtual bool evaluate(int inputFile, int outputFile) = 0;
		virtual bool evaluate2() = 0;
	

};
#endif

