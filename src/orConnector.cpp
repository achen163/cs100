#include "../header/orConnector.h"
string orConnector::item(){
        return "||";
}

bool orConnector::evaluate(){
        if (left->evaluate()) {
                return true;
        }
        else if (left->evaluate() == false) {
                return right->evaluate(); //if left fails, all depends on right
        }
}

void orConnector::setLeft(Token* token){
        left = token; //just setter helper function that sets left child
}

void orConnector::setRight(Token* token){
        right = token; // sets our righttoken
}



