#include <iostream>
#include <vector>
using namespace std;
 
class Point
{
public:
	friend ostream& operator<<(ostream& o, const Point &);
};
ostream& operator<<(ostream& o, const Point &)
{
	o<<"this is Point class"<<endl;
	return o;
}

    class Base {
    public:
		virtual void f(double x)
		{
			cout << "Base::f(double x)" << x << endl;
		}
	public:
		virtual ~Base(){}
    };
    class Derived : private Base {
    public:
		using Base::f;
		 void f1(double x)
		{
			cout << "Derived::f(double x)" << x << endl;
		}

    };

    int main()
    {
      Derived* d = new Derived;
		d->f(3);
      delete d;
      return 0;
    }
