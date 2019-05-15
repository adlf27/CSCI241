#ifndef SORTS_H
#define SORTS_H
#include <fstream>
#include <vector>
#include <iomanip>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::ios;
using std::setw;

/***********************Function Prototype***************************/
template <class T>  
void buildList(vector<T>&, const char*);

template <class T>  
void printLists(const vector<T>&, int, int);

template <class T>
bool lessThan(const T&, const T&);

template <class T>
bool greaterThan(const T&, const T&);

/*******************method declarations******************************/

/********************************************************************
buildList()
Use:read a data file and sets up the vector
Parameters:reference to vector obj and a C-style string 
Returns:nothing
**********************************************************************/
template <class T>
void buildList(vector<T>& set, const char* filename)
{
  T item;
  ifstream infile;
  infile.open(filename, ios::in);//opens file for input
  infile >> item;
  //checks if the file open succesfully
  if(infile)
    {
      //read until end of file
      while(!infile.eof())
	{
	  set.push_back(item);
	  infile >> item;
	  
	}
      infile.close(); //closes file
    }
  else
    cout << "Error opening File.\n";
}

/********************************************************************
printList()
Use:prints the vector accorfing to the arguments
Parameters:reference to a const vector object, an integer to the itemwidth,
an integer to a number to print out max items per line
Returns:nothing
**********************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
  //for loop to go thru the vector and prints out the vector
  for(int i = 0, j =1; i < (int)set.size();j++, i++)
    {
      cout << setw(itemWidth) << set[i] << " ";
      if(j==numPerLine)
	{
	  j=0;
	  cout << endl;;
	}
    }
  
}

/********************************************************************
lessThan()
Use:checks if item1 is less than item2
Parameters:refernce to a const item1 and item2
Returns:boolean value
**********************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
  if(item1 < item2)
    return true;
  else
    return false;
  
}

/********************************************************************
greaterThan()
Use:checks if item1 is greater than item2
Parameters:reference to a const item1 and item2
Returns:boolean value
**********************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
  if(item1 > item2)
    return true;
  else
    return false;
}
#endif
