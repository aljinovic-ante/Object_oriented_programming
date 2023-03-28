#include <iostream>
using namespace std;
namespace oop
{ 
class Vec3d {
	float x, y, z;
	friend istream& operator>>(istream&, Vec3d&);
	friend ostream& operator<<(ostream&, Vec3d&);
public:
	Vec3d();
	Vec3d(float x, float y, float z);
	Vec3d& operator=(const Vec3d& other);
	friend Vec3d operator+(const Vec3d& v1,const Vec3d& v2);
	friend Vec3d operator-(const Vec3d& v1, const Vec3d& v2);
	friend Vec3d operator*(const Vec3d& v1, float broj);
	friend Vec3d operator/(const Vec3d& v1, float broj);
	friend float operator*(const Vec3d& v1, const Vec3d& v2);
	Vec3d& operator+=(const Vec3d other);
	Vec3d& operator-=(const Vec3d other);
	Vec3d& operator*=(const Vec3d other);
	Vec3d& operator/=(const Vec3d other);
	friend int operator==(const Vec3d& v1, const Vec3d& v2);
	friend int operator!=(const Vec3d& v1, const Vec3d& v2);
	void normalizacija();
	float& operator[](float);
	/*
	* normala => n/|n| 
	*/
	//~Vec3d();
};
}