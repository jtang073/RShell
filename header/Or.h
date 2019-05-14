#ifndef __OR_H__
#define __OR_H__
#include "Connector.h"
using namespace std;

class Or : public Connector {
	public:
	Or(Instruction*, Instruction*);
	bool execute();
};

#endif
