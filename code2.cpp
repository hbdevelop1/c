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
		virtual ~Base(){}
    };
    class Derived : public Base {
    public:
		 void f(double x)
		{
			cout << "Derived::f(double x)" << x << endl;
		}

    };

void f(Derived *& ppb, int size)
{
	for(int i=0; i<size; ++i)
	{
		ppb[i].f(4.);
	}
}

void f(std::vector<Base*> & ppb)
{
	for(unsigned int i=0; i<ppb.size(); ++i)
	{
		ppb[i]->f(4.);
	}
}


    int main()
    {
      Derived* d = new Derived[3];
	  f(d,3);

      	std::vector<Base*> v;
		v.push_back(&d[0]);
		v.push_back(&d[1]);

	  f(v);

      delete [] d;
      return 0;
    }
