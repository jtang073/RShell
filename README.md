# CS 100 Programming Project
RShell
Spring 2019
Jason Tang (862046859), Nathan Tran (862116704)

## Introduction
RShell is a basic command shell in C++ that should prompt and accept input though command lines. Command lines will be executed via fork, execvp, and waitpid. The composite pattern will be used to represent commands, meaning logical operators, commands, and operands will all have their own designated base classes that they will inherit from. Command lines will be parsed and executed based on the classes each of the components represent. RShell also compensates for comment strings, exit commands, and incorrect/fatal command lines. 

## Diagram
![Diagram](/images/UML.png)

## Classes
* **Class Group: Shell**
Outputs the initial prompt in which instructions are entered. Accepts the instructions as a string input and parses. Determines what is being processed. Is able to wait indefinitely for input.
* **Class Group: Instruction**
The input that is being parsed and what the below classes inherit from. The parser will analyze this class and determine the subclass that the parsed strings belong to (Comment, Connector, or Command).
* **Class Group: Logical Operators (Connectors)**
Since the shell is required to accept and number of commands at once, connectors are essential to aggregate said instructions. Strictly includes “;”, “||”, and “&&”. The semicolon operation functions differently from the others as it only compounds executables. The “or” and “and” operations examine their left-hand side and right-hand side in order to return a Boolean.
* **Class Group: Commands** 
Determines how data will be processed. Accepts the appropriate arguments and flags and will act accordingly. Functions may or may not return a variable type. (the commands might need to be divided up into executable, argument, cmd)
The exit command is also a part of this class, which will simply terminate processes and end the shell. 
* **Class Group: Comments**
Different from the rest of the command line, comments are observed when a pound sign (#) is used. Anything after the pound sign is immediately ignored.

## Research

(need to actually test fork, execvp, and waitpid on a normal shell)

* **Testing Connectors on a Linux Shell**
![Picture](/images/code.PNG)
The linux shell is able to accept any number and combination of commands and connectors. The semicolon (;) operation simply compounds the commands and does not analyze the validity of the commands. The AND (&&) operation analyzes the validity of the left-hand side of the expression and will discontinue executing commands if the left-hand side fails. The OR (||) operation performs the opposite function of AND, continuing the execution of the right-hand side if the left-hand side fails. 

## Development and Testing Roadmap
1)	Create and test the base Shell class (should only print out a prompt at this point)
2)	Create the Instruction class
3)	Create and test the base Command class (see if Command jives with its interface)
4)	Test the Shell class with the Command classes 
5)	Create and test the Logical Operator classes 
6)	Test the classes together (compound connectors with commands mostly)
7)	Create and test the Comment class
8)	Test all classes together (same as 6 but with comments)




