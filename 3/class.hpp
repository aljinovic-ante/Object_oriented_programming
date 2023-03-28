#include <iostream>
#include <string>
using namespace std;
/*
3. Napisati klasu koja predstavlja metu. Meta je oblika kvadra i zadana je donjom
lijevom i gornjom desnom to?kom. Ima dva stanja: pogo?ena i nepogo?ena.

*/



class Point {
public:
	double x, y, z;

	void point_set(double x, double y, double z);
	void random_point_set();
	void get_point(int* px, int* py, int* pz);
	float calculate_distance_2d(int x, int y);
	float calculate_distance_3d(int x, int y,int z);
};

class Weapon {
public:
	Point position;
	int magazine_size=30;
	int magazine_state=30;
	void weapon_shoot();
	void weapon_reload();
};

class Target {
public:
	Point left_bottom;
	Point right_top;

	void target_position(Point&, Point&);

	bool hit(Weapon weapon, Point left_bottom, Point right_top);
};