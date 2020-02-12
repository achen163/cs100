#include "../header/connectorToken.h"
#include <iostream>

string ConnectorToken::stringify(Tokenizer* t) {
	return (char*)t->element.c_str();
}

bool ConnectorToken::evaluate(char* arr[]) {
	Executioner e = Executioner();
	if(e.execute(char* arr[]) == 1)
		return false;
	return true;
}

