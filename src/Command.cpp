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
	if(strcmp(arguments.at(0), "exit") == 0) {
		exit(0);
	}
        pid_t pid = fork();
        if(pid == 0) {
	        char* args[arguments.size() + 1];
        	for(int i = 0; i < arguments.size(); i++) {
                	args[i] = arguments.at(i);
        	}
        	args[arguments.size()] = NULL;
		if(execvp(args[0], args) < 0) {
			perror("error running");
			return false;
		}
	}
        else {
        	pid_t waiter = waitpid(pid, 0, 0);
		if(waiter == -1) {
			perror("error: waiting failed");
			return false;
		}
        }
        return true;	
	
}
