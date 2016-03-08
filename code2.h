#include <iostream>
using namespace std;
 
class Point
{
public:
	friend ostream& operator<<(ostream& o, const Point &);
};


    class Base {
    public:
		virtual void f(double x)
		{
			cout << "Base::f(double x)" << x << endl;
		}
		virtual ~Base(){}
    };
    class Derived : public Base {
    public:
      void f(Point p)
		{
			cout << "Derived::f(Point p):" << p << endl;
		}

    };
