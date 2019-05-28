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
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"


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
		//cout << "goteem" << endl;
		if (strcmp(arguments.at(1), "-e") == 0) {
			struct stat temp;
			//cout << "testing -e" << endl;
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
			//cout << "testing -f" << endl;
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
			//cout << "testing -d" << endl;
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
                        //cout << "testing -e" << endl;
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
        int testing = 0;
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
        	pid_t waiter = waitpid(pid, &testing, 0);
		if(waiter == -1) {
			perror("error: waiting failed");
			return false;
		}
		if (WEXITSTATUS(testing) == 0) {
			return true;
		}
        }
        return false;	
	
}


bool Command::run(vector<Connector*> connectorClassVecto, int inde, int comInde, vector<char*> connectorVecto, vector<Command*> commandVecto) {
	vector<Connector*> connectorClassVector = connectorClassVecto;
	vector<char*> connectorVector= connectorVecto;
	vector<Command*> commandVector = commandVecto;
	bool flag = true;
	int index = inde;
        int commandIndex = comInde;
	string connector1 = "&&";
	string connector2 = "||";
	string connector3 = ";";
	string connector4 = "(";
	string connector5 = ")";
        for(int i = index; i < connectorVector.size(); i++) {
                if(i == index) {
                        if(connectorVector[index] == connector1) {
                                And* temp = new And(commandVector[index], commandVector[index+1]);
                                connectorClassVector.push_back(temp);
                        }
                        else if(connectorVector[index] == connector2) {
                                Or* temp = new Or(commandVector[index], commandVector[index+1]);
                                connectorClassVector.push_back(temp);
                        }
                        else if(connectorVector[index] == connector3) {
                                Semicolon* temp = new Semicolon(commandVector.at(index), commandVector.at(index+1));
                                connectorClassVector.push_back(temp);
                        }
                        if(i == connectorVector.size() - 1) {
                                connectorClassVector.at(index)->execute();
                        }
                }
                else {
/////////////////////////////////////
//			if (connectorVector[i] == connector4) {
//				++i;
//				new func while i != ) create add(or, command1)
//					while loop keep track of indexes if %1 then return add l/r
//					if command == false return false
/////////////////////////////////////
                         if(connectorVector[i] == connector1) {
                                And* temp = new And(connectorClassVector[index], commandVector[commandIndex]);
                                if(i == connectorVector.size() - 1) {
                                        flag = temp->execute();
                                        break;
                                }
                                connectorClassVector.push_back(temp);
                                commandIndex++;
                                index++;
                        }
                        else if(connectorVector[i] == connector2) {
                                Or* temp = new Or(connectorClassVector[index], commandVector[commandIndex]);
                                if(i == connectorVector.size() - 1) {
                                        temp->execute();
                                        break;
                                }
                                connectorClassVector.push_back(temp);
                                commandIndex++;
                                index++;
                        }

                        else if(connectorVector[i] == connector3) {
                                Semicolon* temp = new Semicolon(connectorClassVector[index], commandVector[commandIndex]);
                                if(i == connectorVector.size() - 1) {
                                        temp->execute();
                                        break;
                                }
                                connectorClassVector.push_back(temp);
                                commandIndex++;
                                index++;
                        }
                }
        }
        connectorClassVector.clear();
	return flag;
}
