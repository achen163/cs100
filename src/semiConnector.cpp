#include "../header/semiConnector.h"

string semiConnector::item() {
        return ";";
}

bool semiConnector::evaluate() {
		//semicolon evaluates both sides regardless
       left->evaluate();       //evaluate left side
       return right->evaluate(); //evaluate then right side in case of chain
}

void semiConnector::setLeft(Token* token){
        left = token;
}

void semiConnector::setRight(Token* token ){
        right = token; 
}


