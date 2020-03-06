#include "../header/orConnector.h"
string orConnector::item(){
        return "||";
}

bool orConnector::evaluate(int inputFile, int outputFile) {
	if (left->evaluate(0,1)) {
		return true;
	}
	
	else if (left->evaluate(0,1) == false) {
		return right->evaluate(0,1);
	}

}

bool orConnector::evaluate2(){
        if (left->evaluate2()) {
                return true;
        }
        else if (left->evaluate2() == false) {
                return right->evaluate2(); //if left fails, all depends on right
        }
}


void orConnector::setLeft(Token* token){
        left = token; //just setter helper function that sets left child
}

void orConnector::setRight(Token* token){
        right = token; // sets our righttoken
}



