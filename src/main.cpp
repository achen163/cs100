#include "../header/tokenizer.h"
#include "../header/connectorToken.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string input;
	getline(cin, input);
	whlie(input != "exit") {
		cout << "$ "; 
		Tokenizer* t1 = new ConnectorToken(input);
		t1->parser();
	}

return 0;
}
