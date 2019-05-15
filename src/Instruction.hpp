#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__
#include "RShell.h"
using namespace std;

class Instruction {
        public:
                Instruction() {};
                virtual bool execute() = 0;
};

#endif //__INSTRUCTION_H__

