#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__
#include "Connector.h"
using namespace std;

class Semicolon : public Connector {
	public:
	Semicolon() {};
	bool execute();
};

#endif