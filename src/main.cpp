#include "../header/tokenizer.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string input;
	getline(cin, input);
	Tokenizer tk = new Tokenizer(input);

return 0;
}
