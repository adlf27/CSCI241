#ifndef VECTORN_H
#define VECTORN_H
#include <iostream>
using std::ostream;

class VectorN
{
  friend ostream &operator<<(ostream&, VectorN);
  friend VectorN operator+(const VectorN&, const VectorN&);
  friend VectorN operator-(const VectorN&, const VectorN&);
  friend double operator*(const VectorN&, const VectorN&);
  friend VectorN operator*(const double &, const VectorN&); //multiply double * vectorN
  friend bool operator==( const VectorN&, const VectorN&);
  
 private:
  double *vecArray;
  size_t vecCap;
  
 public:
  VectorN();//default constructor
  VectorN(const double [], size_t);//constructor
  VectorN(const VectorN &);//copy construcotr
  ~VectorN();//destuctor
  void clear();
  size_t size() const;
  int operator[](int)const; //overload for reading
  double &operator[](int); //overload for writing
  VectorN &operator=(const VectorN&);
  VectorN operator*(const double&) const; //multiply vector * double
  double at(unsigned int sub)const;
  double& at(unsigned int sub);

};

#endif 
