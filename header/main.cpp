#include "tokenizer.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string line;
	getline(cin, line);
	Tokenizer token = new Tokenizer(line);

return 0;
}
