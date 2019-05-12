#include "Add.h"
using namespace std;

bool And::execute() {
	if (lhs->execute()) {
		rhs->execute();
		return true;
	}
	return false;
}
