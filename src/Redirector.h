#ifndef __REDIRECTOR_H__
#define __REDIRECTOR_H__
#include "Instruction.hpp"
using namespace std;

class Redirector : public Instruction {
	public:
	Instruction* lhs;
	string filename;
	Redirector(Instruction*, Instruction*) {};
	bool execute() {};
};

#endif
