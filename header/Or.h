#ifndef __OR_H__
#define __OR_H__
#include "Connector.h"
using namespace std;

class Or : public Connector {
	public:
	Or() {};
	bool execute();
};

#endif
