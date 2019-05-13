#include "Or.h"
using namespace std;
/*
Or::Or(Instruction* left, Instruction* right) {
	this->lhs = left;
	this->rhs = right;
}
*/
bool Or::execute() {
	if (!lhs->execute()) {
		return false;
	}
	return true;
}

