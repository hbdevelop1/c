#include "vec3.h"

bool vec3::operator==(const vec3 & v)
{
    return fabs(this->x - v.x)<=Zero  && fabs(this->y - v.y)<=Zero && fabs(this->z - v.z)<=Zero;
}

vec3 operator-(const vec3 & v1, const vec3 & v2)
{
    return vec3(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}

vec3 operator+(const vec3 & v1, const vec3 & v2)
{
    return vec3(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
}

vec3 cross(const vec3 & v1, const vec3 & v2)
{
    return vec3(
                v1.y*v2.z-v1.z*v2.y,
               -v1.x*v2.z+v1.z*v2.x,
                v1.x*v2.y-v1.y*v2.x
                );
}

double dot(const vec3 & v1, const vec3 & v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

double vec3::lengthSquared()
{
    return x*x + y*y + z*z;
}

double vec3::length()
{
    double mag = lengthSquared();
    double res = mag<=Zero ? 0:sqrt(mag);
    return res;
}

void vec3::normalize()
{
    double l=length();
    double denominator;
    if(l<Zero)
    {
        denominator=0.;
    }
    else
    {
        denominator=1/l;
    }

    *this *= denominator;
}

const vec3& vec3::operator*=(const double f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

vec3 operator*(const vec3 & v, double f)
{
    vec3 r;
    r.x=f*v.x;
    r.y=f*v.y;
    r.z=f*v.z;
    return r;
}

vec3 operator*(double f, const vec3 & v)
{
    vec3 r;
    r.x=f*v.x;
    r.y=f*v.y;
    r.z=f*v.z;
    return r;
}

ostream& operator<<(ostream& os, const vec3 & v)
{
    os << "("<<v.x<<","<<v.y<<","<<v.z<<")";
    return os;
}

