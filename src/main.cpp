#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "../header/cmd.h"
#include <iostream>
#include <cstring>
#include "../header/connector.h" 
#include "../header/andConnector.h"
#include "../header/semiConnector.h"
#include "../header/orConnector.h"
#include "../header/token.h"
using namespace std;
		
void execute();
void outputVector(vector<string>);
void outputQueue(queue<Token*>);
void outputPreorder(Token*);
void outputInorder(Token*);
void outputPostorder(Token*);
bool isConnector(string);
bool hasMatch(vector<string>);
bool leftParen(string);
bool rightParen(string);
Token* connector(string);

int main() {
	while(1) execute;
return 0;
	
}

/*void execute() {
	string input;
	vector<string> userInput;
	stack<string> connector;
	queue<Token*> tokens;
	
	cout << "$ ";
	getline(cin, input);

	for(unsigned i = 0; i < userInput.size(); ++i) {
		if(userInput.at(i) == '#') {
			userInput.resize(i);
		}
	}
	
	if(userInput.size() == 0) { return; }


        typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
        boost::char_separator<char> sep(" ");
        tokenizer tok(userinput, sep);

        for(tokenizer::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter){
        userInput.push_back(static_cast<std::string>(*tok_iter));
        }

        for(unsigned i = 0; i < userInput.size(); ++i) {
	
		while(userInput.at(i).find('\"') != string::npos) {
			userInput.at(i).erase(userInput.at(i).find('\"'), 1);
		}
                if(userInput.at(i) == "(" || userInput.at(i) == ")" || userInput.at(i) == "[" || userInput.at(i) == "]") {
                        continue;
                }
                else if(userInput.at(i).at(0) == '(') {
                        string temp = userInput.at(i).substr(1, userInput.at(i).size() - 1);
			userInput.at(i) = "(";
*/

bool hasMatch(vector<string> v) {
	stack<string> p;
	for(unsigned i = 0; i < v.size(); ++i) {
		if(leftParen(v.at(i)) == true) 
			p.push(v.at(i));
		else if(rightParen(v.at(i)) == true) {
			if(p.empty() == true) return false;
			else {
				string t = p.top();
				p.pop();
				if(leftParen(t) == true) continue;
				else return false;
			}
		}
	}
	return p.empty(); //returns if the queue is empty or not
}			

bool isConnector(string i) {
	if(i == ";" || i == "||" || i == "&&") return true;
	return false; 
}

bool leftParen(string i) {
	if(i == "(") return true;
	return false;
}

bool rightParen(string i ) {
	if(i == ")") return true;
	return false;
}

Token* connector(string c) {
	if(c == ";") return new semiConnector();
	else if(c == "||") return new orConnector();
	else if(c == "&&") return new andConnector();
}

void outputVector(vector<string> v) {
	for(unsigned i = 0; i < v.size(); ++i) {
		cout << v.at(i) << endl;
	}
}

void outputQueue(queue<Token*> q) {
	while(q.empty() == false) {
		cout << q.front()->item() << endl;
		q.pop();
	}
}

void outputPreorder(Token* t) {
	if(t == nullptr) return;
	cout << t->item() << " ";
	outputPreorder(t->getLeft());
	outputPreorder(t->getRight());
}

void outputInorder(Token* t) {
	if(t == nullptr) return;
	outputInorder(t->getLeft());
	cout << t->item() << " ";
	outputInorder(t->getRight());
}

void outputPostorder(Token* t) {
	if(t == nullptr) return;
	outputPostorder(t->getLeft());
	outputPostorder(t->getRight());
	cout << t->item() << " ";
}
