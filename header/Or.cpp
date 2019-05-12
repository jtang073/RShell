#include "Or.h"
using namespace std;

bool Or::execute() {
	if (!lhs->execute()) {
		return false;
	}
	return true;
}

