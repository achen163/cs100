#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

using namespace std; 

class Tokenizer : public Executioner {
	public:
		Tokenizer() {}

		virtual char* stringify() = 0; //convert to char*
		virtual int evaluate() = 0; //return execute value
	private:
		char* arg; //initialize this in the constructor as an array 
};

#endif
