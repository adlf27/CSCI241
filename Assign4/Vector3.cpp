#include "Vector3.h"

/**************************************************
Vector3()
constructor that takes three arguments which should
set the x, y, and z vector components
Takes in 3 parameter of type double.
returns nothing
**************************************************/
Vector3::Vector3(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

/**************************************************
overload operator +
allows for adding of the vectors
Takes in a parameter of type Vector3.
Returns Vector3 obj.
**************************************************/
Vector3 Vector3::operator+(const Vector3& vec) const
{
	//adds two vectors with each of its same data value 
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

/**************************************************
overload operator -
allows for subtracting vectors
Takes in a  parameter of type Vector3.
Returns Vector3 obj.
**************************************************/
Vector3 Vector3::operator-(const Vector3& vec) const
{
	//subtracts the vectors
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

/************************************************
overload operator *
scalar product multiplication
takes in a parameter of vector3 type 
returns a float 
************************************************/
float Vector3::operator*(const Vector3& vec)const
{
	//multipies the vectors and adds the result
	//store the result in the variable sum
	float sum;
	sum = (x*vec.x) + (y*vec.y) + (z*vec.z);
	return sum;
}

/*************************************************
overload operator *
this function multiplies the vector with a constant
return vector3 type
*************************************************/
Vector3 operator*(float k, const Vector3& vec)
{
	return Vector3(vec.x * k, vec.y * k, vec.z * k);
}

/**************************************************
overload operator *
third overload of the * operator
this method multiplys the vector with a constant
return vector3 obj
**************************************************/
Vector3 Vector3::operator*(double k) const
{
	Vector3 vec=*this;
	return Vector3(vec.x * k, vec.y * k, vec.z * k);

}

/*****************************************************
overload operator <<
this allows the vector to be printed out with a cout
takes in a ostream object and a vector3 obj.
retruns the ostream obj
*****************************************************/
ostream &operator<<(ostream& out, const Vector3 vec)
{
	out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return out;
}

/***********************************************************
overload operator []
this method allows the use of subscritps. this method
gets the x, y, and z to the correct index
takes in one parameter of double type. represents the index
returns a doouble
**********************************************************/
double Vector3::operator[](double sub) const
{
	//if statement to get the correct index
	if(sub == 0)
		return x;
	else if(sub == 1)
		return y;
	else
		return z;
	return(-1);
}

/*********************************************************
overload operator []
second time the [] operator is overload. this one sets the 
correct index associat with the vector.
take in one parameter of type double.
return Vector3 type
*********************************************************/
Vector3 Vector3:: operator[](double sub)
{
	Vector3 vec;
	double k=0;
	//condition statement to sets each vector
	if( sub == 0)
		vec.x = k;
	else if (sub == 1)
		vec.y = k;
	else
		vec.z = k;
	return vec;

}

/*******************************************************
overload operator ==
this method allows to test if two vectors are equal or not
takes in th a vector3 obj
return true of false
*******************************************************/
bool Vector3::operator==(const Vector3& vec)const
{
	//condition statement to test if x,y,z are equal
	if(x==vec.x && y==vec.y && z==vec.z)
		return true;
	else
		return false;
	return(-1);
}
