#include <iomanip>
#include <iostream>
#include <ostream>

using namespace std;

template<typename T> class Point;
template<typename T> Point<T> operator+ (const Point<T>& lhs, const Point<T>& rhs);
template<typename T> std::ostream& operator<< (std::ostream& o, const Point<T>& x);

template<typename T>
class Point
{
public:
  Point(const T u = T(),const T v = T()):x(u),y(v) {}

  friend Point<T> operator+ <>(const Point<T>& lhs, const Point<T>& rhs);
  friend std::ostream& operator<< <>(std::ostream& o, const Point<T>& x);

private:
  T x;
  T y;
};

template<typename T> Point<T>
operator+ (const Point<T>& l, const Point<T>& r)
{
    return Point<T>(l.x+r.x, l.y+r.y);
}

template<typename T> std::ostream&
operator<< (std::ostream& o, const Point<T>& p)
{
    o<<"Point("<<p.x<<","<<p.x<<")";
    return o;
}


int main( )
{
    Point<int> pi;
    cout << pi << endl;
}
