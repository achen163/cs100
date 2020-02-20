#include "../header/andConnector.h"
string andConnector::item() {
        return "&&";
}
bool andConnector::evaluate(){
        if (left->evaluate() == false) { //left doesnt evaluate, fails
                return false;
        }
        else {
                return right->evaluate(); //if left evaluated check right
        }
}

void andConnector::setLeft(Token* token) {
        left = token; //sets Left child
}

void andConnector::setRight(Token* token) {
        right = token; //sets Right child
}

