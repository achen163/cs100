#include "../header/connectorToken.h"
#include <boost/tokenizer.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>

string ConnectorToken::returnv1String () {
	string v1string = "";
	for (int i = 0; i < v1.size(); i++) {
		v1string += v1.at(i); 
	}
	
return v1string;	
}

string ConnectorToken::returnv2String() { 
	string v2string = "";
	for(int i = 0; i < v2.size(); i++) {
		v2string += v2.at(i);
	}
return v2string;
}


bool ConnectorToken::evaluate() {
	Executioner exe;
	char* array [v3.size() + 1];
	for(unsigned i = 0; i < v3.size(); ++i) {
		array[i] = v3.at(i);
	}

	array[v3.size()] = NULL;
	
	int executeResult = exe.execute(array);
	//std::cout << "executeResult: " << executeResult << std::endl;
	return (bool) executeResult;
}

void ConnectorToken::stringify() {
	for(unsigned i = 0; i < v2.size(); i++) 
		v3.push_back((char*)v2.at(i).c_str());
}


void ConnectorToken::parser() {
	int qIndex = 0;
	int pIndex = 0;
	string unquoted;
	for(unsigned i = 0; i < userinput.size(); i++) {
		if(userinput.at(i) != '\"') 
			unquoted += userinput.at(i);
	}
		
	for(unsigned i = 0; i < userinput.size(); i++) {
		if(userinput.at(i) == '\"') {
			qIndex = i;
			break;		
		}	
	}
	//cout << "This is my qIndex: " << qIndex << endl;
	
	for(unsigned j = 0; j < userinput.size(); j++) {
		if(userinput.at(j) == '#') 
			pIndex = j;
	}
	//cout << "This is my pIndex: " << pIndex << endl;
	
	if(pIndex > 0 && qIndex > 0  ) { 
		if (pIndex < qIndex) 
		userinput.resize(pIndex);
		else {
			userinput = unquoted;
		}
	 }	
	else if (pIndex > 0 && qIndex == 0) {
		userinput.resize(pIndex);
	}
	 
	else {
		userinput = unquoted;
	}	
		
	
	//boost
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep(" ");
	tokenizer tok(userinput, sep);

	for(tokenizer::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter){
	v1.push_back(static_cast<std::string>(*tok_iter));
	}

	//for(int j = 0; j < v1.size(); j++){
	//	std::cout << v1.at(j) << std::endl;
	//}
	//std::cout << "test done" << std::endl;
	
	/*for(const auto& tk : userinput){
		v1.push_back((char*)tk);
	}*/

	
	//parsing

	int i = 0;
	while(i < v1.size()) {
		int numCmdArgs = 0;
		string connector = "";
		while(v1.at(i) != ";" && v1.at(i) != "||" && v1.at(i) != "&&") {
			v2.push_back(v1.at(i));
			numCmdArgs++;
			if(i == v1.size() - 1) 
				break; //if last element of the string.		
			i++;
		}
	//	cout << i << endl;		
                
	    // 	connector = v1.at(i);
	//	cout << "This is the connector: " << connector << endl;;
			
		stringify();
		if(v2.at(0) == "exit") exit(1);
		if(connector == "&&") {
			if((evaluate())){
				//cout << "evaluate failed, should return none"; 
				
				break;
			}
			//else{cout << "evaluate ran.should run two cmds";}
		}
		else if(connector == "||") {
			if(!evaluate()){
                         //       cout << "evaluate succeeded, should return one";
                                break;
                        }
                        //else{cout << "evaluate failed.should run other/none";}

		}
		else if(connector == ";")
			evaluate();
		else 
			evaluate();
	
	//clear vectors 
	v2.clear();
	v3.clear();		
	i++;		
	}
}
