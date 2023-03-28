#include <iostream>
#include "header.hpp"
using namespace std;


/*
Funkcije za klasu Board
*/

Board::Board()
{
	height = 20, length = 10;
	map = new char* [height];

	for (int i = 0; i < height; i++)
	{
		map[i] = new char[length];
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == 0 || j == 0 || i == (height - 1) || j == (length - 1))
				map[i][j] = 'O';
			else
				map[i][j] = ' ';
		}
	}
}

Board::Board(int m, int n)
{
	this->length = m;
	this->height = n;
	map = new char * [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[length];
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == 0 || j == 0 || i == (height - 1) || j == (length - 1))
				map[i][j] = 'O';
			else
				map[i][j] = ' ';
		}
	}
}

Board::~Board() {
	height = 0, length = 0;

	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[]map;
	map = NULL;
}

Board::Board(const Board& other) {

	height = other.height;
	length = other.length;

	map = new char* [height];

	for (int i = 0; i < height; i++)
	{
		map[i] = new char[height];
	}

	memcpy(map, other.map, height * length);
}

Board::Board(Board&& other)
{
	height = other.height, length = other.length;
	map = other.map;

	other.height = 0;
	other.length = 0;
	other.map = nullptr;
}

void Board::draw_board() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
				cout << map[i][j];
		}
		cout << endl;
	}
}

void Board::draw_char(Point p, char znak) {
	int i = (int)round(p.get_x());
	int j = (int)round(p.get_y());

	map[i][j] = znak;
}

void Board::draw_up_line(Point p, char znak) {
	int x = (int)round(p.get_x());
	int y = (int)round(p.get_y());

	for (int i=1;i<y;++i)
		map[i][x] = znak;
}

void Board::draw_line(Point p1, Point p2, char znak)
{
	int x1 = (int)round(p1.get_x());
	int x2 = (int)round(p2.get_x());
	int y1 = (int)round(p1.get_y());
	int y2 = (int)round(p2.get_y());

	int tmp;

	if (x1 > x2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if (x1 == x2 && y1 == y1)
		map[x1][y2] = znak;

	while ((x1 != x2) || (y1 != y2))
	{
		int j = abs(x2 - abs(x2 - x1));
		int i = abs(y2 - abs(y2 - y1));

		map[i][j] = znak;

		if (x1 == x2 && y1 != y2)
			y1++;
		else if (x1 != x2 && y1 == y2)
			x1++;
		else if (x1 != x2 && y1 != y2)
		{
			x1++;
			y1++;
		}
	}
}

/*
Funkcije za strukturu Point
*/

double Point::get_x()
{
	return x;
}

double Point::get_y()
{
	return y;

}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{
	this->x = 10;
	this->y = 10;
}