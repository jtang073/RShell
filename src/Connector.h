#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "Instruction.hpp"

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
