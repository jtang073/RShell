#include <iostream>
#include "Instruction.hpp"
#include "Command.h"
#include <vector>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

Command::Command(vector<char*> argu) {
        for(int i = 0; i < argu.size(); i++) {
		arguments.push_back(argu.at(i));
	}	
}

bool Command::execute() {
	
        pid_t pid = fork();
	cout << "the fork has occurred" << endl;
        if(pid == 0) {
        cout << "post-construction argument size: " << arguments.size() << endl;
        char* args[arguments.size() + 1];
        for(int i = 0; i < arguments.size(); i++) {
                args[i] = arguments.at(i);
        }
        args[arguments.size()] = NULL;
	cout << "flag immediately before execute attempt!" << endl;
	if(execvp(args[0], args) < 0) {
		perror("error running");
		return false;
	}
	cout << "safe execution flag!" << endl;
	//return true;

		cout << "this is the child" << endl;
                if(execvp(args[0], args) < 0) {
                        perror("error: could not execute command");
                        return false;
                }
        }
        else {
        pid_t waiter = waitpid(pid, 0, 0);
		cout << "this is the parent" << endl;
		if(waiter == -1) {
			perror("waiting failed");
   return false;
		}
		cout << "the parent is done waiting" << endl;
		cout << "lmao did it even execute?" << endl;
        }
        return true;
	
}
