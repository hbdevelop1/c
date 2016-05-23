//a class that can ONLY be a instanciated through a friend or a static function

#include <iostream>

using namespace std;
 
class Point final
{
private:
	int x, y;
private:
	Point(int xx=0, int yy=0):x(xx), y(yy){}

public:
	static Point* create(int xx=0, int yy=0) { return new Point(xx,yy);}
	friend Point* create(int xx=0, int yy=0);
	friend ostream& operator<<(ostream& o, const Point &);
};
ostream& operator<<(ostream& o, const Point &p)
{
	o<<"this is Point class: ("<<p.x<<","<<p.y<<")"<<endl;
	return o;
}

Point* create(int xx, int yy) 
{ 
	return new Point(xx,yy);
}

class Pointcol:public Point
{
};
    int main()
    {
		Point* p=Point::create(3,14);
		cout << *p;
		delete p;
		p=create(13,4);
		cout << *p;
		delete p;

		Pointcol pc;

      return 0;
    }
