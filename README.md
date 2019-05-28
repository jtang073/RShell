# CS 100 Programming Project
RShell  
Spring 2019  
Jason Tang (862046859), Nathan Tran (862116704)  

# Introduction
RShell is a basic command shell in C++ that should prompt and accept input though command lines. Command lines will be executed via fork, execvp, and waitpid. The composite pattern will be used to represent commands, meaning logical operators, commands, and operands will all have their own designated base classes that they will inherit from. Command lines will be parsed and executed based on the classes each of the components represent. RShell also compensates for comment strings, exit commands, and incorrect/fatal command lines. RShell now utilizes the test operation to further increase it's arsenal of commands. Precedence through parenthesis is also accounted for in the newly updated RShell.

# Diagram
![Diagram](/images/UMLL.png)

# Classes
* **Class Group: Shell**  
Outputs the initial prompt in which instructions are entered. Accepts the instructions as a string input and parses. The parsed string is processed as a vector of character pointers. Is able to wait indefinitely for input.
* **Class Group: Instruction**  
The base class of both Command and Connector. It highlights one pure virtual function that all subclasses inherit: execute(). 
* **Class Group: Connector**  
This class accepts two instructions as its parameters. It is only concerned about executing its left-hand side instruction and determining whether it should then execute its right-hand instruction. It returns a boolean based on the results of the left-hand instruction and the right-hand instruction. Subclasses strictly include ";", "&&", and "||".
* **Class Group: Command**  
Determines how data will be processed. Accepts a vector of character pointers and converts the vector into a null-terminated array. Then, execvp is executed with the array as the parameter. The exit command is assessed here and a child is forked in order to execute execvp. Returns a boolean based on the success of executing the arguments given. 

# Research

* **Testing fork()**  
```c++
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

void forktest() {
        if(fork() == 0) {
                cout << "This is the child" << endl;
        }
        else {
                cout << "This is the parent" << endl;
        }
}

int main() {
        forktest();
        return 0;
}
```

Output:  
```c++
This is the parent
This is the child
```

Even though the fork is successful, the parent process is executed at the same time as child process. This creates zombie processes and eats away memory. 

* **Testing fork() with waitpid**
```c++
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

void test() {
        pid_t pid = fork();
        if(pid == 0) {
                cout << "This is the child" << endl;
        }
        if(pid != 0) {
                if(wait(0) == -1) {
                        perror("parent didn't wait");
                }
                cout << "This is the parent" << endl;
        }
}

int main() {
        test();
        return 0;
}
```

Output:  
```c++
This is the child
This is the parent
```

With the wait() function, the parent process runs after the child process (which is intended).

* **Testing fork() with waitpid and execvp**

```c++
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

void test() {
        char* args[3];
        string mkdir = "mkdir";
        char* mkdirchar = (char*)(mkdir.c_str());
        args[0] = mkdirchar;
        string dir = "directory";
        char* dirchar = (char*)(dir.c_str());
        args[1] = dirchar;
        args[2] = NULL;
        pid_t pid = fork();

        if(pid == 0) {
                cout << "This is the child" << endl;
        }
        else {
                if(wait(0) == -1) {
                        perror("parent didn't wait");
                }
                if(execvp(args[0], args) == -1) {
                        perror("directory not made");
                }
        }
}

int main() {
        test();
        return 0;
}

```
Output:  
![Picture](/images/output.PNG)

These processes must be incorporated in order to effectively perform multiple executables in a single instruction. It is also essential to use waitpid in order to maintain left-to-right execution order when parsing the instruction. 

* **Testing Connectors on a Linux Shell**  
![Picture](/images/code.PNG)
The linux shell is able to accept any number and combination of commands and connectors. The semicolon (;) operation simply compounds the commands and does not analyze the validity of the commands. The AND (&&) operation analyzes the validity of the left-hand side of the expression and will discontinue executing commands if the left-hand side fails. The OR (||) operation performs the opposite function of AND, continuing the execution of the right-hand side if the left-hand side fails. 

# Development and Testing Roadmap
1)	Create and test the base Shell class (should only print out a prompt at this point)
2)	Create the Instruction class
3)	Create and test the base Command class (see if Command jives with its interface)
4)	Test the Shell class with the Command classes 
5)	Create and test the Logical Operator classes 
6)	Test the classes together (compound connectors with commands mostly)
7)	Create and test the Comment class
8)	Test all classes together (same as 6 but with comments)

# Reflection
The creation of RShell was more difficult than anticipated. Since we did not want to depend on outside sources for the coding of a shell, some functions were either overcomplicated or oversimplified. The oversimplified functions typically did not work as expected, while the complicated code was difficult to test. Despite attempting to develop using agile principles, it helped little accentuate or coding skill. Therefore, it was our lack of effectiveness in coding which dragged our progress and delayed the final submission of the product. We spent approximately 40 hours on the creation of this assignment. We had to redo our parser for the main RShell since the old one did not support the precedence functionality. Although we ran into some hiccups, the newly improved RShell also addresses the other issues we had last.


