#include <iostream>
#include "header.hpp"
using namespace std;

int main()
{
	using namespace oop;
	Vec3d v1,v2,v3;
	cout << "unesite 3 broja:\n";
	cin >> v1;
	cout << v1;
	v2 = v1;
	cout << v2;
	v3 = v1 + v2;
	cout << v3;
	v3 = v1 - v2;
	cout << v3;
	v3 = v1 * 3;
	cout << v3;	
	v3 = v1 / 2;
	cout << v3;
	v3 += v1;
	cout << v3;
	v3 -= v1;
	cout << v3;
	v3 *= v1;
	cout << v3;
	v3 /= v1;
	cout << v3;
	int jednakost = v1 == v2;
	cout << "primjer za jednakost: " << jednakost << endl;
	jednakost = v1 == v3;
	cout << "primjer za nejednakost: " << jednakost << endl;
	int sklarni_produkt = v1 * v2;
	cout << "primjer za sklarni_produkt: " << sklarni_produkt << endl;
	cout << "primjer za normalizaciju: " <<endl;
	v1.normalizacija();
	cout << v1;
	cout << "primjer za operator[]: " << endl;
	v1[1] = 10;
	cout << v1;
}