#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
 private:
  int height;
  int width;
 public:
  Rectangle(string, int, int);
  virtual void print()const;
  virtual double get_area()const;
};
#endif
