#include "../header/parser.h"

using namespace std;	

void Parser::execute() {
	string input;
	vector<string> userInput;
	stack<string> connectors;
	queue<Token*> tokens;
	
	cout << "$ ";
	getline(cin, input);
	int connectorcounter = 0;
	int quotecounter = 0;
	int firstquotecounter = 0;	
	int firstpoundcounter = 0;
	int secondquotecounter = 0;
	int thirdquotecounter = 0;	
	int secondpoundcounter = 0;	
	unsigned i =  0;
	for(i; i < input.size(); ++i) {
		if(input.at(i) == '"') {
			quotecounter++;	
		}
		
	}
/*	
	for (i =0; i < input.size(); ++i) {
		if ((input.at(i) == '&' && input.at(i+1) == '&') || (input.at(i) == ';') || (input.at(i) == '|' && input.at(i+1) == '|')){
			int connectorcounter = i+1;
			cout << "Connector counter's index" << connectorcounter <<  endl;
		}
	}
*/
	for(i = 0; i < input.size(); ++i) {
		if(input.at(i) == '"'){
			firstquotecounter = i;
			cout << "This is firstquote index: " << firstquotecounter << endl;
			break;
		}	
	}		

	if (firstquotecounter != 0 ) {
		for (i = firstquotecounter + 1; i < input.size(); ++i) {		
			if (input.at(i) == '"') {
				secondquotecounter = i;
				cout << "This is secondquote index: " << secondquotecounter << endl;
				break;	
			}
		}
	}
/*	if (secondquotecounter != 0 ) {	
		for (i = secondquotecounter + 1; i < input.size(); ++i) {
		
			if (input.at(i) == '"') {
				thirdquotecounter = i;
				cout << "This is thirdquote index: " << thirdquotecounter << endl;	
				break;
			}	
			else {	
				thirdquotecounter == 0;
				}
			}
					
	}
				
		
		
*/	
	
int poundcounter = 0;
	for (i = 0; i < input.size(); ++i) {
		if(input.at(i) == '#') {
			firstpoundcounter = i;
			poundcounter++;	
			cout << "first pound counter index: " << firstpoundcounter << endl;
			break;
		}
	}
/*	if (firstpoundcounter !=0) {
		for (i = firstpoundcounter + 1; i < input.size(); i ++){
				if (input.at(i)  == '#') {
					secondpoundcounter = i;
					cout << "second pound counter index: " << secondpoundcounter << endl;
					break;
				}
				else{} 
			} 
	}
*/	
	
	if (quotecounter == 0 && firstpoundcounter > 0 ) {
		input.resize(firstpoundcounter);
	}	
	else if (poundcounter == 0 ) {

	}	
	else if(firstpoundcounter < firstquotecounter) {
		input.resize(firstpoundcounter);
		//cout << thirdquotecounter << endl;
	}
	
	
	/*else if (connectorcounter > 0 && (secondpoundcounter > 0 && thirdquotecounter ==0)) {
		input.resize(secondpoundcounter);
	
	}
	else if (connectorcounter != 0 && (secondpoundcounter < thirdquotecounter)) {
		input.resize(secondpoundcounter);
	}*/
	//else if (firstquotecounter != 0 && firstpoundcounter != 0 &&  firstquotecounter >  firstpoundcounter) {
	//	input.resize(firstpoundcounter);
//	}
	//else if (firstquotecounter!=0 && firstpoundcounter ==0 ) {

	//}
	
	else {

	}
	
	
	if(input.size() == 0) { return; }
	

        typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
        boost::char_separator<char> sep(" ");
        tokenizer tok(input, sep);

        for(tokenizer::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter){
        	userInput.push_back(static_cast<string>(*tok_iter));
        }


	/*char * c = new char[input.size() + 1];
	strcpy(c, input.c_str());
	char * t = strtok(c, " ");
	while(t != NULL) {
		userInput.push_back(t);
		t = strtok(NULL, " ");
	}*/
	
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

 i = 0;
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

//delete[] c;
}

bool Parser::hasMatch(vector<string> v) {
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

bool Parser::isConnector(string i) {
	if(i == ";" || i == "||" || i == "&&") return true;
	return false; 
}

bool Parser::leftParen(string i) {
	if(i == "(") return true;
	return false;
}

bool Parser::rightParen(string i ) {
	if(i == ")") return true;
	return false;
}

Token* Parser::connector(string c) {
	if(c == ";") return new semiConnector();
	else if(c == "||") return new orConnector();
	else if(c == "&&") return new andConnector();
}

void Parser::outputVector(vector<string> v) {
	for(unsigned i = 0; i < v.size(); ++i) {
		cout << v.at(i) << endl;
	}
}

void Parser::outputQueue(queue<Token*> q) {
	while(q.empty() == false) {
		cout << q.front()->item() << endl;
		q.pop();
	}
}

void Parser::outputPreorder(Token* t) {
	if(t == nullptr) return;
	cout << t->item() << " ";
	outputPreorder(t->getLeft());
	outputPreorder(t->getRight());
}

void Parser::outputInorder(Token* t) {
	if(t == nullptr) return;
	outputInorder(t->getLeft());
	cout << t->item() << " ";
	outputInorder(t->getRight());
}

void Parser::outputPostorder (Token* t) { 
	if(t == nullptr) return;
	(t->getLeft());
	outputPostorder(t->getRight());
	cout << t->item() << " ";
}
