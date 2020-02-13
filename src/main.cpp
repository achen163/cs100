#include "../header/tokenizer.h"
#include "../header/cmdargToken.h"
#include <iostream>

using namespace std;

int main() {
	cout << "$ ";
	string input;
	getline(cin, input);
	Tokenizer* t1 = new CmdArgToken();
	Tokenizer* t2 = new CmdArgToken(input, t1);

return 0;
}
