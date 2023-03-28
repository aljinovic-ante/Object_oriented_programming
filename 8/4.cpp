#include <iostream>
using namespace std;

template <typename T>
class Point
{
	T x, y;
public:
	Point(T a,T b): x(a),y(b) {}

	friend float operator-(const Point& a, const Point& b) {

		float distance= sqrt(pow(a.x - b.x,2) + pow(a.y - b.y, 2));
		return distance;

	}

	friend ostream& operator<<(ostream& out, const Point& p) {
		return out << "(" << p.x << ", " << p.y << ")";
	}


};

int main()
{
	Point <int> p1(2, 3), p2(3, 4);
	cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << (p1 - p2) << endl;
}
