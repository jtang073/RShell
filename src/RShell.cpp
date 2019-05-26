#include "RShell.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <iterator>
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Command.h"

using namespace std;

void RShell::run() {

vector<char*> argVector;
vector<char*> connectorVector;
vector<Command*> commandVector;
string word;

cout << "$ ";

while(getline(cin, word)) {

for (int k = 0; k < word.length() - 1; ++k) {
        if (word.at(k) == ';' && word.at(k+1) == ' ') {
                word.insert(k, 1, ' ');
                ++k;
        }
}

for (int k = 0; k < word.length() - 1; ++k) {
        if (word.at(k) == '#' && word.at(k-1) == ' ') {
                word.erase(word.begin()+k, word.end()+0);
        }
}


char myword[word.length() + 1];
strcpy(myword, word.c_str());

char* charptr;
charptr = strtok(myword, " ");

string connector1 = "&&";
string connector2 = "||";
string connector3 = ";";

while (charptr != NULL) {
        if(charptr == connector1 || charptr == connector2 || charptr == connector3) {
                Command* command1 = new Command(argVector);
                commandVector.push_back(command1);
                connectorVector.push_back(charptr);
                argVector.clear();
        }
        else {
        argVector.push_back(charptr);
        }
        int count = 0;
        char* charptr2 = charptr;
        while(*charptr2 != NULL) {
                charptr2 = (charptr2 + 1);
                count++;
        }
        if(*(charptr + count + 1) == '\"') {
                charptr = strtok(NULL, "\"");
        }
        else {
                charptr = strtok(NULL, " ");
        }
}

Command* command1 = new Command(argVector);
commandVector.push_back(command1);

if(connectorVector.size() > 0) {
        vector<Connector*> connectorClassVector;
        int index = 0;
        int commandIndex = 2;
        for(int i = 0; i < connectorVector.size(); i++) {
                if(i == 0) {
                        if(connectorVector[i] == connector1) {
                                And* temp = new And(commandVector[0], commandVector[1]);
                                connectorClassVector.push_back(temp);
                        }
                        else if(connectorVector[i] == connector2) {
                                Or* temp = new Or(commandVector[0], commandVector[1]);
                                connectorClassVector.push_back(temp);
                        }
                        else if(connectorVector[i] == connector3) {
                                Semicolon* temp = new Semicolon(commandVector.at(0), commandVector.at(1));
                                connectorClassVector.push_back(temp);
                        }
                        if(i == connectorVector.size() - 1) {
                                connectorClassVector.at(i)->execute();
                        }
                }
                else {
                        if(connectorVector[i] == connector1) {
                                And* temp = new And(connectorClassVector[index], commandVector[commandIndex]);
                                if(i == connectorVector.size() - 1) {
                                        temp->execute();
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
}

else{
        commandVector.at(0)->execute();
}
commandVector.clear();
connectorVector.clear();
argVector.clear();
word.clear();
cout << "$ ";

}

}

