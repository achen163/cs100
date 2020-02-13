#include "../header/connectorToken.h"
#include <iostream>

bool ConnectorToken::evaluate() {
	Executioner exe;
	char* array [v3.size()];
	for(unsigned i = 0; i < v3.size(); ++i) {
		array[i] = v3.at(i);
	}
	if(exe.execute(array) == 1)
		return false;
	return true;
}

char* ConnectorToken::stringify() {
	for(unsigned i = 0; i < v2.size(); i++) {
		v3.at(i) = (char*)v2.at(i).c_str();

	
}
