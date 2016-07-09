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
		int b;
    protected:
		int r;
    private:
		int v;
    };

    class Derived_v : private Base 
	{
	public:
		void f()
		{
			b=1;
			r=1;
			//v=1;
		}
    };

    class Derived_vprivate : private Derived_v 
	{
	public:
		void f()
		{
			//b=1;
			//r=1;
			//v=1;
		}
    };

    class Derived_vprotected : protected Derived_v 
	{
	public:
		void f()
		{
			//b=1;
			//r=1;
			//v=1;
		}
    };

    class Derived_vpublic : public Derived_v 
	{
	public:
		void f()
		{
			//b=1;
			//r=1;
			//v=1;
		}
    };

    class Derived_r : protected Base 
	{
	public:
		void f()
		{
			b=1;
			r=1;
			//v=1;
		}
    };

    class Derived_rb : public Derived_r 
	{
	public:
		void f()
		{
			b=1;
			r=1;
			//v=1;
		}
    };

    class Derived_b : public Base 
	{
	public:
		void f()
		{
			b=1;
			r=1;
			//v=1; NO
		}
    };

    int main()
    {
		Derived_b b;
		Derived_r r;
		Derived_v v;
		Derived_rb rb;


      return 0;
    }
