#include <iostream>
#include <fstream>
#include "Verifier.h"

using std::ifstream;
using std::cout;
using std::endl;

/***************************************************************
Verifier
Use: default constructor. Sets all the elements in the array
to zero.
Parameters: None
Returns: nothing
***************************************************************/

Verifier::Verifier()
{

}

/***************************************************************
readGrid

Use: This method reads the content of the input file into the elements
of the grid array.
Parameters: 1. ar: a pointer to a constant character that will
represnt the name of the file
Returns: nothing
***************************************************************/

void Verifier::readGrid(const char* filename)
{

	ifstream infile;
	infile.open(filename);
	//checks if the file was open succesfully.
	if (filename)
	{
		//A for loop to  read the file into the sudoku grid. 
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				infile >> sudokuGrid[i][j];
			}
		}
		infile.close(); //closes the file

	}
	//prints an error msg if the file was not open succesfully.
	else
		cout << "Error Opening File." << endl;
}

/***************************************************************
printGrid

Use: This method prints out the sudoku grid array to the screen
as a 9 row by 9 column.
Parameters: None.
Returns: nothing
**************************************************************/

void Verifier::printGrid()
{
	cout << "-------------------------" << endl;
	//for loop to print out the array in as 9 by 9 table.
	for (int i = 0; i < 9; i++)
	{
		cout << "| ";
		for (int j = 0; j < 9; j++)
		{
			cout << sudokuGrid[i][j] << " ";
			if(((j +1) % 3) == 0)
				cout << "| ";
		}
		cout << endl;
		if(((i + 1) % 3) == 0)
			cout << "-------------------------" << endl;
	}


}

/***************************************************************
verifySolution

Use: This method checks if the sudoku if a correct solution or if
it is not.
Parameters: None
Returns: A boolean value wheater it is true if the sudoku grid is
correct or it returns  false if the sudoku grid is incorrec.
***************************************************************/

bool Verifier::verifySolution()
{

	int num = 0;
	//for loop to get each number from the rows and columns
	for(int row = 0; row < 9; row++)
	{
		for(int col = 0; col < 9; col++)
		{
			num = sudokuGrid[row][col];
			int vsquare = row/3;
			int hsquare = col/3;
               //this for loop checks duplicate numbers in the rows.
			for(int j = col + 1; j < 9; j++)
			{
				if(num == sudokuGrid[row][j])
					return false;
			}
             //this for loop check any duplicate numbers in the columns.
			for(int j = row + 1; j < 9; j++)
			{
				if(num == sudokuGrid[j][col])
					return false;
			}
		//for loop to check if there is any duplicates in the 3 by 3 squares.
			for(int ver = vsquare * 3; ver < (vsquare*3 + 3); ver++)
			{
				for(int hoz = hsquare * 3; hoz < (hsquare*3 + 3); hoz++)
				{
					if(!(ver == row && hoz == col))
					{
						if(num == sudokuGrid[ver][hoz])
							return false;
					}
				}
			}

		}
	}

	return true;

}

