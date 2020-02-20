#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "command.h"
#include "string"

class Connector : public Base {
        public:
                virtual string item() = 0;
                virtual void setLeft(Base*) = 0;
                virtual void setRight(Base*) = 0;
                virtual bool evaluate() = 0;


};
#endif

