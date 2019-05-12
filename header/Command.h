#include "Instruction.hpp"
#include <vector>
#include <string>
#ifndef __COMMAND_H__
#define __COMMAND_H__

using namespace std;

class Command : public Instruction {
	public:
		Command(vector<char*>);
		Instruction* ptr;
		vector<char*> arguments;
		bool execute();
};

#endif //__COMMAND_H__
