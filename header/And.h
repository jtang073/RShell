#ifndef AND_H
#define AND_H
#include "Connector.h"
using namespace std;

class And : public Connector {
	public:
		And(Instruction* lhs, Instruction* rhs) {};
		bool execute();
};

#endif
