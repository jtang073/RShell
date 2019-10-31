#include "Output.h"
using namespace std;

Output::Output(Instruction* lhs, Instruction* rhs) {
	this->lhs = lhs;
	this->rhs = rhs;
}

bool Output::execute() {
	
