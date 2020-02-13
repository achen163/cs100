#include "../header/tokenizer.h"
#include "../header/connectorToken.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string input;
	getline(cin, input);

	while(input != "exit") {
		Tokenizer* t1 = new ConnectorToken(input);
                t1->parser();
		cout << "$ ";
		getline(cin, input);
	}

return 0;
}
