#include "../header/semiConnector.h"

string semiConnector::item() {
        return ";";
}
bool semiConnector::evaluate(int inputFile, int ouputFile) {
	left->evaluate(0,1);
	return right->evaluate(0,1);	

}

bool semiConnector::evaluate2() {
		//semicolon evaluates both sides regardless
       left->evaluate2();       //evaluate left side
       return right->evaluate2(); //evaluate then right side in case of chain
}

void semiConnector::setLeft(Token* token){
        left = token;
}

void semiConnector::setRight(Token* token ){
        right = token; 
}


