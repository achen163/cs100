#include "../header/cmdargToken.h"
#include "../header/connectorToken.h"
#include <boost/tokenizer.hpp>

void CmdArgToken::tokenizer(CmdArgToken* token){
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

	//parsing
	for (unsigned i =0; i < tokens.size();i++ ) {
        int numCmdArgs = 0;
        string connector = " ";
	vector<string> unconverted;
                while(tokens.at(i) != ";" &&
                      tokens.at(i) != "||" &&
                      tokens.at(i) != "&&") {
                        if(i != tokens.size()-1) {
                                numCmdArgs++;
				unconverted.push_back(tokens.at(i));
			}
                i++;
                }

                connector = tokens.at(i);

        char* array[numCmdArgs+1];
                int j = 0;
                while(numCmdArgs > 0){
			array[j] = stringify(unconverted.at(j), tokenPtr);
			j++;
			numCmdArgs--;
		}
		array[numCmdArgs] = NULL;
	if(connector == "&&") {
		if(!(token->evaluate(array, tokenPtr))) {
			break;
		}
	}
	 else if (connector == "||") {
                if (token->evaluate(array, tokenPtr)){
                        break;
                }
        }
        else if(connector == ";"){
                token->evaluate(array, tokenPtr);
        }
        else {
                token->evaluate(array, tokenPtr);
        }	
	}

}
char* CmdArgToken::stringify(string line, Tokenizer* ptr) {	
	return ptr->stringify(line);
}




