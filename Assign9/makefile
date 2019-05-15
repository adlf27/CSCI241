#
# PROGRAM:    Assignment 9
# PROGRAMMER: Luis Aguinaga
# LOGON ID:   z1811673
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o Shape.o Triangle.o Circle.o Rectangle.o 
	g++ $(CCFLAGS) -o assign9 assign9.o Shape.o Triangle.o Circle.o Rectangle.o 

# Rules to compile source code files to object code
assign9.o: assign9.cpp Shape.h Triangle.h Circle.h Rectangle.h
	g++ $(CCFLAGS) -c assign9.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ $(CCFLAGS) -c Triangle.cpp

Circle.o: Circle.cpp Circle.h
	g++ $(CCFLAGS) -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ $(CCFLAGS) -c Rectangle.cpp

Shape.o : Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp

Triangle.h: Shape.h
Circle.h: Shape.h
Rectangle.h: Shape.h


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9
