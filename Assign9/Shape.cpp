#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

/************************************************
Shape()
use: constructor. use tp initilize shape's color
Arguments: reference to a string const
Returns: nothing
**************************************************/
Shape::Shape(const string& color)
{
  this->color=color;
}

/************************************************
~Shape()
Use:destructor for the abstract base class shape
Arguments:none
Returns:nothing
 ************************************************/
Shape::~Shape()
{
  
}

/************************************************
print()
Use:prints out the color of the shape
Arguments:none
Returns:none
 ************************************************/
void Shape::print()const
{
  cout << color << " ";
}
