#
# PROGRAM:    assign8
# PROGRAMMER: Luis Aguinaga
# LOGON ID:   z1811673
# DATE DUE:   11/22/16
#

# Compiler variables
CCFLAGS = -Wall -std=c++11
CC = g++

# Rule to link object code files to create executable file
assign8: assign8.o 
	$(CC) $(CCFLAGS) -o assign8 assign8.o 

# Rules to compile source code files to object code
assign8.o: assign8.cpp 
	$(CC) $(CCFLAGS) -c assign8.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
