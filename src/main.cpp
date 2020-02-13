#include "../header/tokenizer.h"
#include "../header/cmdargToken.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string input;
	getline(cin, input);
	Tokenizer* tk = new CmdArgToken(input);

return 0;
}
