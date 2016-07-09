#include "template15.h"
#include <iostream>
using namespace std;

class bigfloat
{
    int y;
public:
    bigfloat()    {        y=0;    }

    template<class T>
    bigfloat(T y)    {        y=0;    }

    template<unsigned N> double round( );
    template<unsigned N> static double round(double);
};

template<unsigned N> double bigfloat::round( )
{
    cout << "round( ), N ="<< N << endl;
    return 1.0;
}
template<unsigned N> double bigfloat::round(double d)
{
    cout << "round(d), N ="<< N << endl;
    return d+1.0;
}

int main()
{
    bigfloat f;
    std::cout << f.template round<2>( ) << '\n';
    std::cout << bigfloat::template round<8>(3.14) << '\n';
    bigfloat fw(4);
}
