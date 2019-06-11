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
//#include "Pipe.h"
using namespace std;

void RShell::run() {

vector<char*> argVector;
vector<char*> connectorVector;
vector<Command*> commandVector;
string word;

cout << "$ ";

while(getline(cin, word)) {
int index = 0;

for (int k = 0; k < word.length() - 1; ++k) {
	if (word.at(k) == '\"') {
		for (int i = k; i < word.length(); ++i) {
			if (word.at(i) != '\"') {
				++k;
			}
		}
	}
        else if (word.at(k) == ';' && word.at(k+1) == ' ') {
                word.insert(k, 1, ' ');
                ++k;
        }
}
////////////////////////////
for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '(') {
		word.insert(k+1, 1, ' ');
		++k;
	}
	if (word.at(k) == ')') {
		word.insert(k, 1, ' ');
		++k;
	}
}
////////////////////////////
for (int k = 0; k < word.length() - 1; ++k) {
	if (word.at(0) == '#') {
		word = ' ';
		break;
	}
        else if (word.at(k) == '#' && word.at(k-1) == ' ') {
                word.erase(word.begin()+k, word.end()+0);
        }
}
int par1 = 0;
int par2 = 0;
for (int k = 0; k < word.length(); ++k) { 
	if (word.at(k) == '(') {
		++par1;
	}
	if (word.at(k) == ')') {
		++par2;
	}
}
for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '(' || word.at(k) == ')') {
		word.erase(k, 1);
		
	}
}

for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '|') {
		word.erase(k, 1);
	}
}
///////////////////////////
string Ifile = "";
string Ofile = "";
bool Ifole = false;
bool Ofole = false;
string itemp;
string otemp;
for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '<') {
		Ifole = true;
		itemp = "<";
		k = k + 2;
		while (k + 1 <= word.length()) {
			if (word.at(k) != ' ') {
				Ifile = Ifile + word.at(k);
				word.erase(k, 1);
			}
			else {
				k = 69;
			}
		}
	}
}
for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '>') {
		Ofole = true;
		if (word.at(k + 1) == '>') {
			otemp = ">>";
			k = k + 3;
			while (k + 1 <= word.length()) {
				if (word.at(k) != ' ') {
					Ofile = Ofile + word.at(k);
					word.erase(k, 1);
				}
				else {
					k = 69;
				}
			}
		}
		else {
			otemp = ">";
			k = k + 2;
			while (k + 1 <= word.length()) {
				if (word.at(k) != ' ') {
					Ofile = Ofile + word.at(k);
					word.erase(k, 1);
				}
				else {
					k = 69;
				}
			}
		}
	}
}
for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '>') {
		word.erase(k, 1);
		if (word.at(k) == '>') {
			word.erase(k, 1);
		}
	}
}

for (int k = 0; k < word.length(); ++k) {
	if (word.at(k) == '<') {
		word.erase(k,1);
	}
}

char myword[word.length() + 1];
strcpy(myword, word.c_str());

if (word != " " && par1 == par2) {

char* charptr;
charptr = strtok(myword, " ");

string connector1 = "&&";
string connector2 = "||";
string connector3 = ";";
///////////////////////////////
string connector4 = "<";
string connector5 = ">";
///////////////////////////////
while (charptr != NULL) {
        if(charptr == connector1 || charptr == connector2 || charptr == connector3/* || charptr == connector4 || charptr == connector5*/) { //// 4 and 5
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
        while(*charptr2) {
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
//
if (Ifole == true) {
	command1->setInputFile(Ifile);
	command1->i = itemp;
//	cout << "Command ifile: " << command1->input << endl;
}

if (Ofole == true) {
        command1->setOutputFile(Ofile);
	command1->o = otemp;
//        cout << "Command ofile: " << command1->getOutputFile() << endl;
}

//
if(connectorVector.size() > 0) {
        vector<Connector*> connectorClassVector;
        //int index = 0;
        int commandIndex = index + 2;

	command1->run(connectorClassVector, index, commandIndex, connectorVector, commandVector);
	connectorClassVector.clear();
}

else{
        commandVector.at(0)->execute();
}
charptr = NULL;

} //

if (par1 != par2) {
	cout << "error: Incorrect amount of parentheses" << endl;
}
commandVector.clear();
connectorVector.clear();
argVector.clear();
word.clear();
myword[0];
cout << "$ ";

}

}




