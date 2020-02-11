#include "connectorToken.h"
#include <iostream>

validFunction (connectorToken command) {
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

