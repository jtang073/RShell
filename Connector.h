#include "Instruction.h"
#include <vector>
#include <string>
#ifndef __COMMAND_H__
#define __COMMAND_H__

using namespace std;

class Command : public Instruction {
	public:
		Command(string);
		Instuction* ptr;
		vector<string> arguments;
		bool execute();
};

#endif //__COMMAND_H__
