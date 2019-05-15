/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Luis Aguinaga
   LOGON ID:   z1811673
   DUE DATE:   11/30/2016
 
   FUNCTION:   This short assignment covers inheritance and polymorphism
*********************************************************************/ 
#include <iostream>
#include <vector>

#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

using std::cout;
using std::endl;
using std::vector;

int  main()
{
  vector<Shape *> shape(6); //creates vector shapes

  //initilizes vector with the shapes
  shape[0] = new Circle("red", 9);
  shape[1] = new Circle("black", 30);
  shape[2] = new Triangle("purple", 9, 11);
  shape[3] = new Triangle("blue", 3, 4);
  shape[4] = new Rectangle("pink", 10, 15);
  shape[5] = new Rectangle("green", 7, 14);

  cout << "\nprinting all shapes.....\n"<< endl;
  
  //loop thru vector to print each object
  for(size_t i = 0; i < shape.size(); i++)
      shape[i]->print();
 
  cout << "\nprinting only triangles.....\n" << endl;

  //loop to print only triangles
  for(size_t i=0; i < shape.size(); i++)
    {
      Triangle* trianglePtr = dynamic_cast<Triangle *>(shape[i]);
      if(trianglePtr != nullptr)
	{
	  shape[i]->print();
	}
   
    }
  //loop thru vector to delete each object
  for(size_t i = 0; i < shape.size();i++)
    delete shape[i];
      
  return 0;
}
