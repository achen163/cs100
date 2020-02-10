#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

using namespace std; 

class Tokenizer : public Executioner {
	public:
		Tokenizer() {}

		virtual const char* stringify(string) = 0; //convert to const char* (this is for the first parameter in the execute function)
		virtual void evaluate() = 0; //not sure about the return type 
	private:
		 char* const arg; //initialize this in the constructor as an array (this array holds arguments)
};

#endif
