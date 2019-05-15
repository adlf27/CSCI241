#include "Triangle.h"
#include <iostream>
using std::cout;
using std::endl;

/************************************************
Triangle()
Use:costructor for the triangle class
Arguments:String and two integers
Returns:none
 ************************************************/
Triangle::Triangle(string color, int base, int height) : Shape(color)
{
  this -> base = base;
  this -> height = height;
}

/************************************************
print()
Use:prints the circles height, base and are, color
Arguments:none
Returns:none
 ************************************************/
void Triangle::print()const
{
  Shape::print();
  cout << "triangle" << ", height " << height << ", base "<< base << ", area " << get_area()<<endl;
}

/************************************************
get_area()
Use:calculates the area of the triangle with the 
formula 0.5X(base X height)
Arguments:none
Returns:double
 ************************************************/
double Triangle::get_area()const
{
  return(0.5*(base * height));
}
