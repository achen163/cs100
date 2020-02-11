#include "../header/connectorToken.h"
#include <iostream>

/*validFunction (connectorToken command) {
	for( int i=1; i < command.size(); i++) {
		if (command.at(i) == '&' || command.at(i) == '|') {
			char temp == command.at(i);
			if (command.at(i+1) == temp) {
				return true;
			}
		
		}
	
	}
	return false;
}
*/

char* const* ConnectorToken::stringify(const char* t) {
	t = (char* const*)t;
	return t;
}

bool ConnectorToken::evaluate() {
	if(execute(command, arg) == 1) {
		cout << "invalid command" << endl;
		return false; //this is for main.cpp
	}
	else 
		return true;
return true; // if the above if-else logic doesn't work.
}

