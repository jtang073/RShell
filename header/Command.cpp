#include "Instruction.hpp"
#include "Command.h"
#include <vector>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

Command::Command(vector<char*> argu) {
        vector<char*> arguments = argu;
}

bool Command::execute() {
        char* args[arguments.size() + 1];
        for(int i = 0; i < arguments.size(); i++) {
                args[i] = arguments.at(i);
        }
        args[arguments.size() + 1] = NULL;
        if(execvp(args[0], args) == -1) {
                perror("error: could not execute command");
                return false;
        }
        return true;
}
