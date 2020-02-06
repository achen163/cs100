#ifndef __EXECUTIONER_H__
#define __EXECUTIONER_H__

#include "tokenizer.h"

using namespace std;

class Executioner : Tokenizer {
	public:
		void manager(char*); //don't really know yet
	private:
		pid_t pid;

};

#endif
