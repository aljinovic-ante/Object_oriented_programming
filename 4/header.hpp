struct Point {

private:

	double x, y;

public:

	Point();
	Point(double x, double y);
	double get_x();
	double get_y();
};

class Board {

	int height,length;
	char** map;

public:

	Board();
	Board(int m, int n);
	~Board();
	Board(const Board& other);
	Board(Board&& other);

	void draw_board();
	void draw_char(Point p, char znak);
	void draw_up_line(Point p, char znak);
	void draw_line(Point p1, Point p2, char znak);
};

