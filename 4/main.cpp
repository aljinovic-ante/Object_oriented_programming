#include <iostream>
#include "header.hpp"
using namespace std;

int main()
{
	
	/*Point p1(5, 5);
	Point p2(10, 10);
	Board b1(20,20);
	

	b1.draw_char(p1, '1');
	b1.draw_up_line(p1, '1');
	b1.draw_line(p1, p2, '1');
	b1.draw_board();

	cout << endl << endl;

	Board b2 = b1;

	b2.draw_char(p1, '2');
	b2.draw_up_line(p1, '2');
	b2.draw_line(p1, p2, '2');
	b2.draw_board();

	cout << endl << endl;

	Board b3 = move(b1);

	b3.draw_char(p1, '3');
	b3.draw_up_line(p1, '3');
	b3.draw_line(p1, p2, '3');
	b3.draw_board();*/
	

	
	Point p1(2, 2), p2(8, 8), p3(2, 8),
		p4(16, 8);
	Board b(20, 10);
	b.draw_line(p1, p2, 'x');
	b.draw_line(p3, p4, 'x');
	b.draw_board();
	

}