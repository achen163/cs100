#ifndef __EXECUTIONER_H__
#define __EXECUTIONER_H__

#include <stdio.h>
#include <unistd.h>
#include <string>
#include <wait.h>

using namespace std;

class Executioner {
	public:
		int execute(const char* cmd, char* const* args);
		
};

#endif
