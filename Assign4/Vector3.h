#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>
using std::ostream;
class Vector3
{
		friend ostream &operator<<(ostream&, const Vector3);
		friend Vector3 operator*(float, const Vector3&);


	private:
  //data values representing the x, y, and z components of the vector.
		double x, y, z;
	public:

	//prototype of construcotr takeing 3 parameters.
		Vector3(double=0, double=0, double=0);

	//prototype for overloadinthe + operator
		Vector3 operator+(const Vector3&) const;

	//prototype for overloadinthe - operator
		Vector3 operator-(const Vector3&) const;

	//prototype for overloadinthe * operator
		float operator*(const Vector3&) const;
		Vector3 operator*(double) const;

	//prototype for overloadinthe [] operator
		double operator[](double) const;
		Vector3 operator[](double);

	//prototype for overloadinthe ==  operator
		bool operator==(const Vector3&)const;

};
#endif
