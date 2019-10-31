#ifndef __OUTPUT_H__
#define __OUTPUT_H__
#include "Redirector.h"
using namespace std;

class Output : public Connector {
	public:
	Output(Instruction*, Instruction*);
	bool execute();
};

#endif
