#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H_

using namspace std;

class Instruction {
	public:
		Instuction() {};
		Instuction* ptr;
		virtual bool execute() = 0;
};

#endif //__INSTRUCTION_H__

