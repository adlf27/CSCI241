#
# PROGRAM:	Assign4
# PROGRAMMER:	Luis Aguinaga
# LOGON ID:	z1811673
# DATE DUE:	10-18-2016
#

#Complier Variables
CCFLAGS = -Wall -std=c++11
CC=g++ 

# Rule to link object code files to create executable file
assign4: assign4.o Vector3.o
	$(CC) $(CCFLAGS) -o assign4 assign4.o Vector3.o

# Rules to compile source code files to object code 
assign4.o: assign4.cpp Vector3.cpp
	$(CC) $(CCFLAGS) -c assign4.cpp
Vector3.o: Vector3.cpp Vector3.h
	$(CC) $(CCFLAGS) -c Vector3.cpp
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4
