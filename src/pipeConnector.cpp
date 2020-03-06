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
	int fds[2];
	pipe(fds);
	
	left->evaluate(inputfile, fds[1]);
	close(fds[1]);
	
	right->evaluate(fds[0], outputfile);
	close(fds[0]);

	return true;
}

bool pipeConnector::evaluate2() {

}
