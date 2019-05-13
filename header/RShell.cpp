#include "RShell.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

#include "Connector.h"
//#include "And.h"
//#include "Or.h"
//#include "Semicolon.h"
#include "Command.h"

using namespace std;

void RShell::run() {
vector<char*> argVector;
vector<char*> connectorVector;
vector<Command*> commandVector;
string word;

cout << "$ ";

while(getline(cin, word)) {
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
		cout << "Command: ";
		for(int i = 0; i < argVector.size(); i++) {
			cout << argVector[i] << " ";
		}
		cout << endl;
		argVector.clear();
	}
	else {
	argVector.push_back(charptr);
	}
	charptr = strtok(NULL, " ");
}
cout << "Command: ";
for(int i = 0; i < argVector.size(); i++) {
	cout << argVector[i] << " ";
}
cout << endl;
cout << "Connectors: ";
for(int i = 0; i < connectorVector.size(); i++) {
	cout << connectorVector[i] << " ";
}
cout << endl;

if(!connectorVector.empty()) {
	vector<Connector*> connectorClassVector;
	int index = 0;
	int commandIndex = 2;
	for(int i = 0; i < connectorVector.size(); i++) {
		if(i == 0) {
			if(connectorVector[i] == connector1) {
				Connector* connector = new And(commandVector[0], commandVector[1]);
			}
			else if(connectorVector[i] == connector2) {
				Connector* connector = new Or(commandVector[0], commandVector[1]);
			}
			else if(connectorVector[i] == connector3) {
				Connector* connector = new Semicolon(commandVector[0], commandVector[1]);
			}
			connectorClassVector.push_back(connector);
		}
		else {
			if(connectorVector[i] == connector1) {
				Connector* connector = new And(connectorClassVector[index], commandVector[commandIndex]);
			}
			else if(connectorVector[i] == connector2) {
				Connector* connector = new Or(connectorClassVector[index], commandVector[commandIndex]);
			}
			else if(connectorVector[i] == connector3) {
				Connector* connector = new Semicolon(connectorClassVector[index], commandVector[commandIndex]);
			}
			if(i == connectorVector.size() - 1) {
				connector.execute();
				break;
			}
			connectorClassVector.push_back(connector);
			commandIndex++;
			index++;
			}
		}
	}
}
else{
	commandVector[0].execute();
}

cout << "$ ";

}

int main() {
	RShell test;
	test.run();
return 0;
}
