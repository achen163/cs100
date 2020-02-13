#include "../header/connectorToken.h"
#include <iostream>

bool ConnectorToken::evaluate(char* arr[]) {
	Executioner e = Executioner();
	if(e.execute(char* arr[]) == 1)
		return false;
	return true;
}

void ConnectorToken::tokenizer(ConnectorToken* token){
        string userString = token->getStr();
        int qIndex = 0;
        int pIndex = 0;
        for (int i=0; i < userString.size(); i++) {
                if(userString.at(i) == '\"') {
                        qIndex = i;
                        break;
                }
        }
        for (int j =0; j < userString.size(); j++){
                if (userString.at(j) == '#');
                        pIndex = j;
        }
                if (pIndex < qIndex) {

                        userString.resize(pIndex);
                }

        vector<string> tokenvec;
	 typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
        boost::char_separator<char> sep(" ");
        tokenizer tok(userString, sep);
        for (const auto& tk : tokens){
                tokenvec.push_back(tk);

        }
}
