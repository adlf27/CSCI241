#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
 private:
  int radius;
 public:
  Circle(string, int);
  virtual void print()const;
  virtual double get_area()const;

};
#endif
