#include<math.h>
#include <iostream>
using namespace std;

#define Zero 1.e-5

struct vec3
{
    double x,y,z;

    vec3(double _x=0, double _y=0, double _z=0):x(_x), y(_y), z(_z){}
    friend vec3 cross(const vec3 & v1, const vec3 & v2);
    friend double dot(const vec3 & v1, const vec3 & v2);
    bool operator==(const vec3 & v);
    friend vec3 operator-(const vec3 & v1, const vec3 & v2);
    friend vec3 operator+(const vec3 & v1, const vec3 & v2);
    friend ostream& operator<<(ostream& os, const vec3 & v);
    const vec3& operator*=(const double f);
    friend vec3 operator*(const vec3 &, double f);
    friend vec3 operator*( double f,const vec3 &);
    double lengthSquared();
    double length();
    void normalize();
};

