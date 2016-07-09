#include <iostream>
using namespace std;


struct B { };
struct A { };
struct D : B { };

template<class D, class B> struct Derived_from
{
        static void constraints(D* p)
        {
            B* pb = p;
        }
        Derived_from()
        {
            void(*p)(D*) = constraints;
        }
};


int main()
{
    Derived_from<D,A> f;

    return 0;
}
