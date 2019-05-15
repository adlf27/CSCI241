#include "Circle.h"
#include <iostream>
using std::cout;
using std::endl;

/************************************************
Circle()
Use:constructor for circle class. sets up the radius
Arguments:string color, and int radius
Returns:none
 ************************************************/
Circle::Circle(string color, int radius) : Shape(color)
{
  this -> radius = radius;
}

/************************************************
print()
Use:prints the cricles radius and area
Arguments:none
Returns:none
 ************************************************/
void Circle::print()const
{
  Shape::print();  //calls the shapes version of print
  cout << "Circle" << ", radius " << radius << ", area " << get_area()<<endl;;
}

/************************************************
get_area()
Use:calcuates the area of the circle occurding 
to the formula pi*r^2
Arguments:none
Returns:double
 ************************************************/
double Circle::get_area() const
{
  return(3.14159 * (radius * radius));
}
