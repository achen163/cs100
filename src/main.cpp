#include "../header/tokenizer.h"
#include "../header/connectorToken.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string input;
	getline(cin, input);
	Tokenizer* t1 = new ConnectorToken(input);

return 0;
}
