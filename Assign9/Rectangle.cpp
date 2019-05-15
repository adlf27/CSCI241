#include "Rectangle.h"
#include <iostream>
using std::cout;
using std::endl;

/************************************************
Rectangle()
Use:constructor- sets up width and height
Arguments:string color, int width , int height
Returns:none
 ************************************************/
Rectangle::Rectangle(string color, int width, int height) : Shape(color)
{
  this -> width = width;
  this -> height = height;
}

/************************************************
print()
Use:prints the rectangles height and widht, area
Arguments:none
Returns:none
 ************************************************/
void Rectangle::print()const
{
  Shape::print();
  cout << "rectangle" << ", height " << height << ", width " << width << ", area " << get_area() << endl;
}

/************************************************
get_area()
Use:calculats the area of the rectangle
Arguments:none
Returns:doubel-area of the rectangle
 ************************************************/
double Rectangle::get_area()const
{
  return(width * height);
}
