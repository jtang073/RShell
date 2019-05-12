#include "Or.h"
using namespace std;

bool Or::execute() {
	if (!lhs->execute()) {
		if (!rhs->execute()) {
			return false;
		}
	}
	return true;
}
