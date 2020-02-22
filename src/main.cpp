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
#include <boost/tokenizer.hpp>
#include <iterator> 
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
	while(1) execute();
return 0;
	
}

void execute() {
	string input;
	vector<string> userInput;
	stack<string> connectors;
	queue<Token*> tokens;
	
	cout << "$ ";
	getline(cin, input);
	
	for(unsigned i = 0; i < input.size(); ++i) {
		if(input.at(i) == '#') {
			input.resize(i);
		}
	}
	
	if(input.size() == 0) { return; }
	

        /*typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
        boost::char_separator<char> sep(" ");
        tokenizer tok(input, sep);

        for(tokenizer::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter){
        	userInput.push_back(static_cast<string>(*tok_iter));
        }*/


	char * c = new char[input.size() + 1];
	strcpy(c, input.c_str());
	char * t = strtok(c, " ");
	while(t != NULL) {
		userInput.push_back(t);
		t = strtok(NULL, " ");
	}
	
        for(vector<string>::iterator i = userInput.begin(); i != userInput.end(); ++i) {
	
		while(i->find("\"") != string::npos) {
			i->erase(i->find("\""), 1);
		}
                if(*i == "[" || *i == "]" || *i == "(" || *i == ")") {
                        continue;
                }
                else if(i->at(0) == '(') {
                        string temp = i->substr(1, i->size() - 1);
			*i = "(";
			i = userInput.insert(i + 1, temp) - 1;
		}
		else if(i->at(i->size() - 1) == ';') {
			i->pop_back();
			i = userInput.insert(i + 1, ";");
		}
		else if(i->find(")") != string::npos) {
			int freq = 0;
			for(unsigned j = 0; j < i->size(); ++j) {
				if(i->at(j) == ')') {
					++freq;
				}
			}

			*i = i->substr(0, i->find(")"));
			for(unsigned k = 0; k < freq; ++k) {
				i = userInput.insert(i + 1, ")");
			}
		}
		else if(i->at(0) == '[') {
			string neg = i->substr(1, i->size() - 1);
			*i = "[";
			i = userInput.insert(i + 1, neg) - 1;
		}
		else if(i->at(i->size() - 1) == ']') {
			*i = i->substr(0, i->size() - 1);
			i = userInput.insert(i + 1, "]") - 1;
		}
	}

	if(isConnector(userInput.at(userInput.size() - 1))) {
		userInput.pop_back();
	} 

//shunting yard
vector<string> cmds; //vector of commands. 

int i = 0;
while( i < userInput.size()) {
	string item = userInput.at(i);
	
	if(isConnector(item) == false && leftParen(item) == false && rightParen(item) == false) {
		cmds.push_back(item);
	}
	
	else if(isConnector(item) == true) {
		if(cmds.empty() == false) {
			tokens.push(new Cmd(cmds));
			cmds.clear();
		}
		if(connectors.empty() == false) {
			while(leftParen(connectors.top()) == false) {
				tokens.push(connector(connectors.top()));
				connectors.pop();
			}
		}

		connectors.push(item);
	
	}
	else if(leftParen(item)) {
		connectors.push(item);
	}
	else if(rightParen(item)) {
		if(cmds.size() != 0) {
			tokens.push(new Cmd(cmds));
			cmds.clear();
		}
		
		while(leftParen(connectors.top()) == false) {
			tokens.push(connector(connectors.top()));
			connectors.pop();
		}
		connectors.pop();
	}
++i;
}

if(rightParen(userInput.at(userInput.size()-1)) == false) {
	tokens.push(new Cmd(cmds));
	cmds.clear();
}

while(connectors.empty() == false) {
	tokens.push(connector(connectors.top()));
	connectors.pop();
}

//cannot convert string to Token*
/*int i = 0;
while( i < userInput.size()) {
	string item = userInput.at(i);
	if(!leftParen(item) && !rightParen(item) && !isConnector(item)) { tokens.push(item); }
	if(isConnector(item)) { connector.push(item);	}
	if(leftParen(item)) { connector.push(item); }	
	if(rightParen(item)) { 
		while(!leftParen(item)) {
			tokens.push(item);
			connector.pop();
		}
		if(leftParen(connector.front())) { connector.pop(); }
	}		
}

while(!connector.empty()) {
	tokens.push(connector.front());
	connector.pop();
}
*/
//queue is flipped
/* stack<Token*> flipper;
while(!connectors.empty()) {
	flipper.push(tokens.front());
	tokens.pop();
}
while(!flipper.empty()) {
	tokens.push(flipper.top());
	flipper.pop();
} */

//build tree
/*queue<Token*> tree;
Token* leftChild = 0;
Token* rightChild = 0; 

Token* root = tokens.front(); //set root
tokens.pop();
tree.push(root);

while(tokens.empty() == false) {
	if(connector(tokens.front()->item())) {
		leftChild = tree.front();
		tree.pop();
		rightChild = tree.front();
		tree.pop();
		tokens.front()->setLeft(leftChild);
		tokens.front()->setRight(rightChild);
		tree.push(tokens.front());
	}
	else {
		tree.push(tokens.front());
	}
	tokens.pop();

}*/ 


stack<Token*> tree;
Token* leftChild = 0;
Token* rightChild = 0;
while(!tokens.empty()) {
	if(isConnector(tokens.front()->item())) {
		rightChild = tree.top();
		tree.pop();
		leftChild = tree.top();
		tree.pop();
		tokens.front()->setLeft(leftChild);
		tokens.front()->setRight(rightChild);
		tree.push(tokens.front());
	}
	else {
		tree.push(tokens.front());
	}
	tokens.pop();
}

Token* root = tree.top();
//execute
if(root->evaluate()) {}

delete[] c;
}

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

void outputPostorder (Token* t) { 
	if(t == nullptr) return;
	(t->getLeft());
	outputPostorder(t->getRight());
	cout << t->item() << " ";
}
