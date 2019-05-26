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
#include <sys/stat.h>

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
//////////////////////////////////////////////////
	if (strcmp(arguments.at(0), "test") == 0 || strcmp(arguments.at(0), "[") == 0) {
		cout << "goteem" << endl;
		if (strcmp(arguments.at(1), "-e") == 0) {
			struct stat temp;
			cout << "testing -e" << endl;
			if (stat(arguments.at(2), &temp) == 0) {
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		}
		else if (strcmp(arguments.at(1), "-f") == 0) {
			struct stat temp;
			cout << "testing -f" << endl;
			if (stat(arguments.at(2), &temp) != 0) {
//				if (temp.st_mode &S_IFREG) {
//					cout << "(True)" << endl;
//					return true;
//				}
				cout << "(False)" << endl;
				return false;
			}
			else if (temp.st_mode &S_IFREG) {
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		}
		else if (strcmp(arguments.at(1), "-d") == 0) {
			struct stat temp;
			cout << "testing -d" << endl;
			if (stat(arguments.at(2), &temp) != 0) {
//				if (temp.st_mode &S_IFDIR) {
//					cout << "(True)" << endl;
//					return true;
//				}
				cout << "(False)" << endl;
				return false;
			}
			else if (temp.st_mode &S_IFDIR) {
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		}
		else {
			struct stat temp;
                        cout << "testing -e" << endl;
                        if (stat(arguments.at(2), &temp) == 0) {
                                cout << "(True)" << endl;
                                return true;
                        }
                        else {
                                cout << "(False)" << endl;
                                return false;
                        }
		}
	}
//////////////////////////////////////////////////
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
