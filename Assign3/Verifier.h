/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 3
   PROGRAMMER: Luis Aguinaga
   LOGON ID:   z1811673
   DUE DATE:   10/04/2016

   FUNCTION:   This program tests the functionality of the Verifier
               class.
*********************************************************************/  
#ifndef VERIFIER_H
#define VERIFIER_H

class Verifier
{
private:
	int sudokuGrid[9][9]= {};
public:
	Verifier(); //constructor
	void readGrid(const char*); //prototype for readGrid
	void printGrid(); //prototype for printGrid
	bool verifySolution(); //prototype for verifySolution
};


#endif
