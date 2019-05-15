#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using std::string;

class Shape
{
 private:
  string color;
 public:
  Shape(const string&);
  virtual ~Shape();
  virtual void print()const; //virtual
  virtual double get_area()const = 0; //pure virtual
};
#endif
