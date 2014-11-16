# Makefile for parts database
# Author: Rio Schad
# Date: 11/1/2014
# Change Log: 11/1/2014- Created file

# <target file>: <list of dependencies>
# <tab>:command_to_build_target_file

# makes the.exe sentence
out: Part.o main.o list.o functions.o
	g++ -Wall -pedantic -g -o out Part.o main.o list.o functions.o

# makes the object file main.o
main.o: main.cpp list.cpp functions.cpp Part.cpp
	g++ -Wall -pedantic -g -c main.cpp

# makes the object file Part.o
Part.o: Part.cpp Part.h
	g++ -Wall -pedantic -g -c Part.cpp

# makes the object file list.o
list.o: list.cpp list.h
	g++ -Wall -pedantic -g -c list.cpp

# makes the object file functions.o
functions.o: functions.cpp functions.h
	g++ -Wall -pedantic -g -c functions.cpp

#Compiler Options:
#files first get compiled into object files, then later linked into the .exe

# -c: compile only into .o file type
# -g: put extra information that can be used by the debugger
# -Wall: show all warnings
# -pedantic: issue warning if program does not follow ISO C++/C standards






