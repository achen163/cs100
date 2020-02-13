#include "../header/cmdargToken.h"
#include "../header/connectorToken.h"
char* CmdArgToken::stringify(string token) {	
	for (unsigned i =0; i < tokens.size();i++ ) {
	int numCmdArgs = 0;
	string connector = " ";	

		while(tokens.at(i) != ";" && 
		      tokens.at(i) != "||" &&
		      tokens.at(i) != "&&") {
			if(i != tokens.size()-1) 
				numCmdArgs++;
		i++;
		}
		
		connector = tokens.at(i);

	char* array[numCmdArgs+1];
		int j = 0;
		while(numCmdArgs > 0){
			array[j] = tokenPtr->stringify(token);
			j++;
			numCmdArgs--;
		}
		array[numCmdArgs] = NULL;
		
	if (connector == "&&" ){
		if (!(evaluate(array))){	
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
	return (char*)"$ ";	
}	
}
	

