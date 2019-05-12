#include "Semicolon.h"
using namespace std;

bool Semicolon::execute() {
	lhs->execute();
	if (rhs->execute()) {
		return true;
	}
	return false;
}
