#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;
	int *m;
public:
	Point(int _x, int _y):x(_x), y(_y){}
	friend ostream& operator<<(ostream&, const Point&);	
};

ostream& operator<<(ostream& o, const Point& p)
{
	o<<"point (" << p.x<<","<<p.y<<")"<<endl;
	return o;
}

int main()
{
	Point point(1,2);
	cout << point;
	int Point::*px = &Point::x; //Point::x is public
	cout << point.*px;
}