# CS 100 Programming Project
# Winter 2020
# Alex Chen (862086202)
# Taeho Yoo (862066993)

INTRODUCTION:
In this assignment, we will be creating our own CLI shell called rshell using C++. It will be able to print a command prompt, read in a line of commands and connectors from standard input, execute the appropriate commands using fork, execvp, and waitpid, and it will repeat these until an exit command is executed. Our design pattern will mostly likely be consisted of subclasses, inheritance, and polymorphism with one parent class composing of different token classes as its children. The inputs will be ingested by the base class and sent to one of its subclasses to be taken care of.  

