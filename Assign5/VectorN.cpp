#include "VectorN.h"
#include <stdexcept>
using std::out_of_range;
/***********************************
VectorN()
default constructor
sets the vectors capacity to zero and 
vecArray to nullptr

returns nothing
***********************************/
VectorN::VectorN()
{
  vecCap = 0;
  vecArray = nullptr;
}


/*************************************************
VectorN()
constructor, should initialize a new VectorN object
 to the values stored in the array values
takes in two parameters, a double and a size_t 
return vectorN obj
**************************************************/
VectorN::VectorN(const double values[], size_t n)
{
  vecCap = n;
  if( vecCap == 0)
    vecArray = nullptr;
  else
   vecArray = new double[vecCap];

  for(unsigned int i=0; i < vecCap; i++)
    vecArray[i] = values[i];
}

/********************************************************
VectorN()
copy constructor for the VectorN class should initialize 
a new VectorN object to the same capacity and array contents
 as the existing VectorN object other
return a vectorN obj
*************************************************************/
VectorN::VectorN(const VectorN& other)
{
  vecCap = other.vecCap;
  if(vecCap==0)
    vecArray = nullptr;
  else
    vecArray = new double[vecCap];
  for(unsigned int i=0; i<other.vecCap;i++)
    {
      if(other.vecCap == 0)
	break;
      vecArray[i] = other.vecArray[i];
    }
}

/******************************************************
~VectorN()
a destructor that calls the clear function.
takes no arguments and returns nothing*
 *****************************************************/
VectorN::~VectorN()
{
  clear();
}

/********************************************************
clear()
This method should set the instance back to a
 vector of zero elements. Delete the vector array, 
set the vector array pointer to nullptr, and set the vector
 capacity to 0.
**********************************************************/
void VectorN::clear()
{
  delete vecArray;
  vecArray = nullptr;
  vecCap = 0;
}

/************************************************
size()
this method gets the size of the vectors capacity
returns a size_t 
**************************************************/
size_t VectorN::size() const
{
  return vecCap;
}

/******************************************************
overload operator [] this one is to be able to read
this method provides accessor methods for the class.
takes in one argument an int.
returns a int
 ******************************************************/
int VectorN::operator[](int index)const 
{
  return vecArray[index];  
}

/******************************************************
overload operator [] this one is to be able to write
this method provides accessor methods for the class.
takes in one argument an int.
returns a double
 ******************************************************/
double &VectorN::operator[](int index)
{
  return vecArray[index];
}

/*****************************************************
overloads operator <<
this method allows for normal cout
takes in two parameters, a ostream object and a vectorN
object
return an ostream object
 ****************************************************/
ostream &operator<<(ostream &out, VectorN vecN)
{
  if(vecN.vecCap == 0)
    {
      out << "()";
      return out;
    }
  out << "(";
  //prints out elements in array
  for(unsigned int i=0; i < vecN.vecCap;i++)
    {
      if(i>0)
	out << ", ";
      out << vecN.vecArray[i];
    }
  out << ")";
  return out;
}

/******************************************************
overload assignment operator
This overloaded copy assignment operator assign one 
VectorN object to another
Parameters: a vectorN object
returns: vectorNobject
 
 ****************************************************/
VectorN &VectorN::operator=(const VectorN& other)
{
  VectorN obj = *this;
  if(&other != this)// checks for slef assignment
    {
      delete [] obj.vecArray;
      vecCap = other.vecCap;
      if(vecCap == 0)
	vecArray = nullptr;
      else
	vecArray = new double[vecCap];
      //copies the vectorarrays
      for(unsigned int i = 0; i < other.vecCap;i++)
	{
	  vecArray[i] = other.vecArray[i];
	}
    }
  return *this;   
}

/**********************************************************
overload operator +
adds two vectorN
takes in two parameters
returns a vectorN
***********************************************************/
VectorN operator+(const VectorN& vec,const VectorN& other)
{

  VectorN result=other;
  //loop to add arrays
  for(unsigned int i = 0;i < other.size();i++)
    {
      result.vecArray[i] = vec.vecArray[i] + other.vecArray[i];
    }
  return result;

}

/************************************************************
overload operator -
subtracts two vectors
takes in two arguments, two vectorN objects
returns a vectorN
 ************************************************************/
VectorN operator-(const VectorN& vec,const VectorN& other)
{

  VectorN result=other;
  //loop to substract arrays
  for(unsigned int i = 0;i < other.size();i++)
    {
      result.vecArray[i] = vec.vecArray[i] - other.vecArray[i];
    }
  return result;

}

/**********************************************************
overload multi. operator

member function. multiplies vector with vector and adds
up the result.
takes in two arguments. two vectorN objects
returns a double
 *********************************************************/
double operator*(const VectorN& vec, const VectorN& other)
{
  double sum;
  //loop for multiplication
  for(unsigned int i = 0; i < vec.size();i++)
    {
      sum =sum + vec.vecArray[i]*other.vecArray[i];
    }
  return sum;
}

/**********************************************************
overload multi. operator

overload as a function. multiplies a double with vectorN
takes in two parameters, a double and a vectorN object
return a vectorN obj.
 ********************************************************/

VectorN operator*(const double& num, const VectorN& vec)
{
  VectorN result=vec;
  for(unsigned int i = 0; i < vec.size();i++)
    {
      result.vecArray[i] = num * result.vecArray[i];
    }
  return result;
}

/**************************************************
overload mult. operator

overload as a member function. Multiplies a vectorN
obj with a double
takes in one parameter a const double
returns a vectorN object
 *************************************************/
VectorN VectorN::operator*(const double& num)const
{
  VectorN result = *this;
   for(unsigned int i = 0; i < result.size();i++)
    {
      result.vecArray[i] = num * result.vecArray[i];
    }
  return result;
}
/*****************************************************
overload equality operator
checks wheter the two arrays are equal or not
takes in two parameters
return a boolean value
******************************************************/
bool operator==(const VectorN& vec, const VectorN& vec2)
{
  // loop to get each value on the array
  for(unsigned int i = 0;i<vec.size();i++)
    {
      //checks if they are equal
      if(vec.vecArray[i] == vec2.vecArray[i])
	return true;
      else
	return false;
    }
  return(-1);
}

/**************************************
at() for reading
provides error checking
takes in one parameter an integer
returns a double
***************************************/
double VectorN::at(unsigned int sub)const
{
  //condtion that test sub is less than zero or
  //greater than vecs cap
  if(sub < 0|| sub >= vecCap)
    throw out_of_range("subscript out of range");
  else
    return vecArray[sub];
    
}

/**************************************
  at() for writing
provides some error checking.
takes in one parameter an integer.
returns a double
 *************************************/
double& VectorN::at(unsigned int sub) 
{
  //condition that test if sub is less than zero
  //or greater the vecs capacity
  if(sub < 0 || sub >= vecCap)
    throw out_of_range("subscript out of range");
  else
    return vecArray[sub];
}
