#include "Connector.h"
using namespace std;

Connector::Connector(Instruction* lhs, Instruction* rhs) {
	this->rhs = rhs;
	this->lhs = lhs;
}

//Connector::Connector() {};

bool Connector::execute() {};

