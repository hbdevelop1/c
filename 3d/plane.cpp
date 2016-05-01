
#include <math.h>
#include <assert.h>
#include <iostream>

using namespace std;

#include "vec3.cpp"

#define tolerance 1.e-3

struct Plane
{
    vec3 n;
    vec3 p;

public:
    Plane(vec3 _n, vec3 _v):n(_n), p(_v)
    {
        if(n.length() - 1 > tolerance)
        {
            cout<<"Plane unusable. It normal is not normalized !"<<endl;
            assert(0);
        }
    }

    double DistanceFromPoint(vec3 p);
};

double Plane::DistanceFromPoint(vec3 pt)
{
    vec3 v(pt-p);
    double res = dot(v,n);

    if(fabs(res)<=Zero)
    {
        return 0.;
    }
    return res; //signed distance
}
