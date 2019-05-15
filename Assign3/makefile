#
#PROGRAM:	Assign3
#PROGRAMMER:	Luis Aguinaga
#LOGON ID:	z1811673
#DATE DUE:	10/04/2016
#

# complier variables
CCFLAGS = -Wall -std=c++11
CC = g++

# rule to link object code files to create executable file
assing3: assign3.o Verifier.o
	$(CC) $(CCFLAGS) -o assign3 assign3.o Verifier.o

# rules to compile source code files to object code
assign3.o: assign3.cpp Verifier.h
	$(CC) $(CCFLAGS) -c assign3.cpp

Verifier.o: Verifier.cpp Verifier.h
	$(CC) $(CCFLAGS) -c Verifier.cpp


clean:	
	-rm *.o assign3

