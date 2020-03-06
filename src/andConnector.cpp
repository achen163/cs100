#include "../header/andConnector.h"
string andConnector::item() {
        return "&&";
}
bool andConnector::evaluate(int inputfile, int outputfile){
        if (left->evaluate(0,1) == false) { //left doesnt evaluate, fails
                return false;
        }
        else {
                return right->evaluate(0,1); //if left evaluated check right
        }
}

bool andConnector::evaluate2() {
	if (left->evaluate2() == false) {
		return false;
	}
	else {
		return right->evaluate2();
	}

}

void andConnector::setLeft(Token* token) {
        left = token; //sets Left child
}

void andConnector::setRight(Token* token) {
        right = token; //sets Right child
}

