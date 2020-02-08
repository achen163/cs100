#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

using namespace std; 

class Tokenizer : public Executioner {
	public:
		Tokenizer() {}

		virtual const char* stringify() = 0; //return const char* after c_string 
		virtual int evaluate() = 0; //return execute value
	private:
		const char* arg; //initialize this in constructor
};

#endif
