#include "Instruction.hpp"
#include <vector>
#include <string>
#include "Connector.h"
#ifndef __COMMAND_H__
#define __COMMAND_H__

using namespace std;

class Command : public Instruction {
	public:
		Command(vector<char*>);
		Instruction* ptr;
		vector<char*> arguments;
		bool execute();
		bool run(vector<Connector*> connectorClassVecto, int inde, int comInde, vector<char*> connectorVecto, vector<Command*> commandVecto);
};

#endif //__COMMAND_H__
