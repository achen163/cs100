#ifndef __EXECUTIONER_H__
#define __EXECUTIONER_H__

#include "tokenizer.h"
#include <stdio.h>
#include <unistd.h>

using namespace std;

class Executioner : public Tokenizer {
	public:
		void manager(char*); //don't really know yet
	private:
		pid_t pid;

};

#endif
