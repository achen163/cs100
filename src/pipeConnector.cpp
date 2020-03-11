#include "../header/pipeConnector.h"

string pipeConnector::item() {
	return "|";
}

void pipeConnector::setLeft(Token* token) {
	left = token;
}

void pipeConnector::setRight(Token* token) {
	right = token;	
}

bool pipeConnector::evaluate(int inputfile, int outputfile) {
	int fileDescriptor[2];
	pipe(fileDescriptor);
	
	left->evaluate(inputfile, fileDescriptor[1]);
	close(fileDescriptor[1]);
	right->evaluate(fileDescriptor[0], outputfile);
	close(fileDescriptor[0]);

	return true;
}

bool pipeConnector::evaluate2() {

}
