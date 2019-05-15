#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
 private:
  int base;
  int height;
 public:
  Triangle(string, int ,int);
  virtual void print()const;
  virtual double get_area()const;
};
#endif
