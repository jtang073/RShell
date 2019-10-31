#ifndef __PIPE_H__
#define __PIPE_H__
#include "Connector.h"

using namespace std;

class Pipe : public Connector {
	public:
	Pipe(Instruction*, Instruction*);
	bool execute();
	//bool execute2(int, int);
};

#endif
