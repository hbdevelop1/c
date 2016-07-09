#include <iomanip>
#include <iostream>
#include <ostream>
#include "sqr.h"

using namespace std;




//template int sqr<int>(int); // Explicit instantiation

// Explicit instantiation of circle<double> and implicit instantiation of
// sqr<double>
//template class circle<double>;

//circle<double> RR(2.3);
/*
// Error: after instantiation of sqr<double>, illegal to specialize it
template<> double sqr(double x)
{
    cout<<"sqr specialized ";
    return x * x;
}
*/
int main( )
{
    double g = sqr(4.4);
    using namespace std;
    // No circle<> instance is needed yet, even to resolve overloaded print
    // function.
    //print(42);

    //double g = sqr(4.4);
    /*
    for (int i = 0; i < 10; ++i)
    // Implicit instantiation of sqr<int>
        cout << setw(2) << i << setw(4) << sqr(i) << '\n';
        */
    // Instantiation of circle<float> and therefore sqr<float>
    circle<double> unit(1.0f);
    cout << "area =" << unit.area() << endl;
    //cout << "area =" << RR.area() << endl;
    // Implicit instantiation of print<circle<float> >
    //print(RR);
}
