#include "Semicolon.h"
#include <iostream>
#include <string>
using namespace std;

Semicolon::Semicolon(Instruction* left, Instruction* right) {
	this->lhs = left;
	this->rhs = right;
}

bool Semicolon::execute() {
        lhs->execute();
        if (rhs->execute()) {
                return true;
        }
        return false;
}

