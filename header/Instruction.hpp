#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__
#include "RShell.h"
//#include "Connector.h"
using namespace std;

class Instruction {
	public:
		Instruction() {};
		//Instuction* ptr;
		virtual bool execute() = 0;
};

#endif //__INSTRUCTION_H__

