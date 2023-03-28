#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "class.hpp"
using namespace std;

int main()
{
	srand(time(NULL));
	Point point1,point2,position;

	int px, py, pz;

	/*
	point1.point_set(2, 3,-1);

	point1.get_point(&px, &py, &pz);
	cout << "x je:" << px << " y je:" << py << " z je:" << pz << endl;

	point1.random_point_set( -5,  5);

	point1.get_point( &px,  &py,  &pz);
	cout << "x je:" << px << " y je:" << py << " z je:" << pz <<endl ;

	cout<<"udaljenost u 2d: " << point1.calculate_distance_2d(1 , 5)<<endl;

	cout<<"udaljenost u 3d: " << point1.calculate_distance_3d(1, 5, -3) << endl;

	*/

	int num_of_targets;
	cout << "Unesite broj meta: " << endl;
	cin >> num_of_targets;
	Target* array_of_targets = new Target[num_of_targets];

	for (int i = 0; i < num_of_targets; i++)
	{
		point1.random_point_set();
		point2.random_point_set();
		cout << "Za " << i + 1 << ". metu dva vrha imaju kordinate: " << endl;
		point1.get_point(&px, &py, &pz);
		cout << "Point1 => x je:" << px << ", y je:" << py << ", z je:" << pz << endl;
		point2.get_point(&px, &py, &pz);
		cout << "Point2 => x je:" << px << ", y je:" << py << ", z je:" << pz << endl<<endl;

		if (point1.z > point2.z)
			array_of_targets[i].target_position(point2, point1);
		else
			array_of_targets[i].target_position(point1, point2);
	}

	Weapon weapon;

	weapon.position.random_point_set();
	weapon.position.get_point(&px, &py, &pz);
	cout << "Pozicija oruzja: x je:" << weapon.position.x << ", y je:" << weapon.position.y << ", z je:" << weapon.position.z << endl<<endl;

	int num_of_hit_targets = 0;

	for (int i = 0; i < num_of_targets; i++)
	{
		
		if (weapon.magazine_state == 0)
			break;
		weapon.weapon_shoot();
		if (array_of_targets[i].hit(weapon, array_of_targets[i].left_bottom, array_of_targets[i].right_top)==true)
		{
			num_of_hit_targets++;
			cout << "Meta broj " << i + 1 << ". pogodena" << endl;
		}
		else {
			cout << "Meta broj " << i + 1 << ". promasena" << endl;
		}

	}
	
	cout << endl<<"Ukupan broj pogodenih meta je: " << num_of_hit_targets << endl;
	
}