#ifndef __AND_H__
#define __AND_H__
#include "Connector.h"
using namespace std;

class And: public Connector{
	public:
	And() {};
	bool execute();
};

#endif
