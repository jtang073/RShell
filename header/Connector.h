#include "Instruction.hpp"
#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

using namespace std;

class Connector : public Instruction {
	public:
		Connector(Instruction*, Instruction*);
		Instruction* rhs;
		Instruction* lhs;
		bool execute();
		Connector();
};

#endif //__CONNECTOR_H__
