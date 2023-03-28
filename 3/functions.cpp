#include "class.hpp"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void Point::point_set(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::random_point_set() {
	int start=-5, end=5;
	
	/*
	cout << "Unesite donju granicu: " << endl;
	cin >> start;
	cout << "Unesite gornju granicu: " << endl;
	cin >> end;
	*/

	this->x = rand() % (end - start + 1) + start;
	this->y = rand() % (end - start + 1) + start;
	this->z = rand() % (end - start + 1) + start;
}

void Point::get_point(int* px, int* py, int* pz) {
	*px = this->x;
	*py = this->y;
	*pz = this->z;
}

float Point::calculate_distance_2d(int x, int y) {
	return sqrt((pow(x - (this->x), 2)) + (pow(y - (this->y), 2)));
}

float Point::calculate_distance_3d(int x, int y, int z) {
	return sqrt((pow(x - (this->x), 2)) + (pow(y - (this->y), 2)) + (pow(z - (this->z), 2)));
}

void Weapon::weapon_shoot() {
	magazine_state = magazine_state - 1;
}
void Weapon::weapon_reload() {
	magazine_state = magazine_size;
}

bool Target::hit(Weapon weapon, Point left_bottom, Point right_top) {
	return ((weapon.position.z >= left_bottom.z) && (weapon.position.z <= right_top.z));
}

void Target::target_position(Point& left_bot, Point& right_top) {
	int x1, y1, z1, x2, y2, z2;

	left_bot.get_point(&x1, &y1, &z1); 
	this->left_bottom.point_set(x1, y1, z1);

	right_top.get_point(&x2, &y2, &z2);
	this->right_top.point_set(x2, y2, z2);

	//this->left_bottom.get_point(&x1, &y1, &z1);
	//cout << "Za point1 u funkciji: x je:" << x1 << " y je:" << y1 << " z je:" << z1 << endl;
	//this->right_top.get_point(&x2, &y2, &z2);
	//cout << "Za point2 u funkciji: x je:" << x2 << " y je:" << y2 << " z je:" << z2 << endl;

}