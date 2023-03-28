#include <iostream>
#include <math.h>
#include "header.hpp"
using namespace std;
namespace oop
{
	Vec3d::Vec3d()
	{
		this->x = 2;
		this->y = 2;
		this->z = 2;
	}

	Vec3d::Vec3d(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	istream& operator>>(istream& is, Vec3d& v)
	{
		is >> v.x >> v.y >> v.z;
		return is;
	}

	ostream& operator<<(ostream& os, Vec3d& v)
	{
		os << '(' << v.x << ',' << v.y << ',' << v.z << ')' << endl;
		return os;
	}

	Vec3d& Vec3d::operator=(const Vec3d& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return *this;
	}

	Vec3d operator+(const Vec3d& v1, const Vec3d& v2)
	{
		return Vec3d(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

	Vec3d operator-(const Vec3d& v1, const Vec3d& v2)
	{
		return Vec3d(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}

	Vec3d operator*(const Vec3d& v1, float broj)
	{
		return Vec3d(v1.x * broj, v1.y * broj, v1.z * broj);
	}

	Vec3d operator/(const Vec3d& v1, float broj)
	{
		return Vec3d(v1.x / broj, v1.y / broj, v1.z / broj);
	}

	float operator*(const Vec3d& v1, const Vec3d& v2)
	{
		return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	}

	Vec3d& Vec3d::operator+=(const Vec3d v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return *this;
	}

	Vec3d& Vec3d::operator-=(const Vec3d v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		return *this;
	}

	Vec3d& Vec3d::operator*=(const Vec3d v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		return *this;
	}

	Vec3d& Vec3d::operator/=(const Vec3d v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		return *this;
	}

	int operator==(const Vec3d& v1, const Vec3d& v2)
	{
		if (v1.x != v2.x)
			return 0;
		if (v1.y != v2.y)
			return 0;
		if (v1.z != v2.z)
			return 0;
		return 1;
	}

	int operator!=(const Vec3d& v1, const Vec3d& v2)
	{
		if (v1.x != v2.x)
			return 1;
		if (v1.y != v2.y)
			return 1;
		if (v1.z != v2.z)
			return 1;
		return 0;
	}

	void Vec3d::normalizacija()
	{
		float d = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
		cout << "d je: " << d << endl;
		this->x = this->x / d;
		this->y = this->y / d;
		this->z = this->z / d;
	}

	float& Vec3d::operator[](float index) 
	{
		if (index == 1)
			return this->x;
		else if (index == 2)
			return this->y;
		else if (index == 3)
			return this->z;
		else
		{
			cout << "Greška, nema tog indeksa\n" << endl;
			exit(0);
		}
	}
}