
#include "../header/connectorToken.h"
#include "../header/cmdargToken.h"

string CmdArgToken::stringify(string token) {	
	for (unsigned i =0; i < token->tokens.size();i++ ) {
	int numArgs = 0;
	string connector = " ";	

		while(tokens.at(i) != ";" && 
		      tokens.at(i) != "||" &&
		      tokens.at(i) != "&&") {
			if(i != token->tokens.size()-1) 
				numArgs++;
		i++;
		}
		
		connector = tokens.at(i);

	char* array[numArgs+1];
		int j = 0;
		int index = numArgs+1;
		while(numArgs > 1) {
			element = tokens.at(j);
			array[j] == tokenPtr->stringify(token);
			j++;
			numArgs--;
		}
		array[index] = NULL;
		
	if (connector == "&&" ){
		if (!(evalate(array))){	
		break;	
		}

	}
	else if (connector == "||") {
		if (evaluate(array)){
			break;
		}	
	}
	else if(connector == ";"){
		evaluate(array);	
	}
	else {
		evaluate(array);
	}
	return "$ ";	
}
	

