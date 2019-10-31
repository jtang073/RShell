#include "Pipe.h"
#include <unistd.h>
using namespace std;

Pipe::Pipe(Instruction* lhs, Instruction* rhs) {
	this->lhs = lhs;
	this->rhs = rhs;
}

//bool Pipe::execute() {
//	return this->evaluate2(0, 1);
//}

bool Pipe::execute() { /*2(int inputt, int outputt) {*/
	int fds[2];
	pipe(fds);
	lhs->execute();
	close(fds[1]);
	rhs->execute();
	close(fds[0]);
	return true;
}
