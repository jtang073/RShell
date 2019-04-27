# CS 100 Programming Project
RShell
Spring 2019
Jason Tang (862046859), Nathan Tran (ID)

## Introduction
RShell is a basic command shell in C++ that should prompt and accept input though command lines. Command lines will be executed via fork, execvp, and waitpid. The composite pattern will be used to represent commands, meaning logical operators, commands, and operands will all have their own designated base classes that they will inherit from. Command lines will be parsed and executed based on the classes each of the components represent. RShell also compensates for comment strings, exit commands, and incorrect/fatal command lines. 

## Diagram
![Diagram](/images/UML.png)

## Classes
* Class Group: Shell
Outputs the initial prompt in which instructions are entered. Accepts the instructions as a string input and parses. Determines what is being processed. Is able to wait indefinitely for input.
* Class Group: Logical Operators (Connectors)
Since the shell is required to accept and number of commands at once, connectors are essential to aggregate said instructions. Strictly includes “;”, “||”, and “&&”. The semicolon operation functions differently from the others as it only compounds executables. The “or” and “and” operations examine their left-hand side and right-hand side in order to return a Boolean.
* Class Group: Commands 
Determines how data will be processed. Accepts the appropriate arguments and flags and will act accordingly. Functions may or may not return a variable type. (the commands might need to be divided up into executable, argument, cmd)
The exit command is also a part of this class, which will simply terminate processes and end the shell. 
* Class Group: Comments
Different from the rest of the command line, comments are observed when a pound sign (#) is used. Anything after the pound sign is immediately ignored. (this might be checked for in a different class, deeming it unnecessary)

## Research

(need to actually test fork, execvp, and waitpid on a normal shell)

## Development and Testing Roadmap
1.	Create and test the base Shell class
2.	Create and test the base Command class
3.	Test the Shell class with the Command classes
4.	Create and test the Logical Operator classes
5.	Test the classes together
6.	Create and test the Comment class
7.	Test all classes together
8.	???



