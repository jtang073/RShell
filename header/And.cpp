#include "And.h"
#include <iostream>
using namespace std;

And::And(Instruction* lhs, Instruction* rhs) {
	this->lhs = lhs;
	this->rhs = rhs;
}

bool And::execute() {
        if (lhs->execute()) {
                return rhs->execute();
        }
	cout << "The function has ended" << endl;
        return false;
}

