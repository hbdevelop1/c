#include <assert.h>
#include <iostream>
using namespace std;


#include "vec3.cpp"

int main()
{
    {
        vec3 v1(1,1,1);

        v1.normalize();

        assert(v1 == vec3(1/sqrt(3),1/sqrt(3),1/sqrt(3)));
    }
    {
        vec3 v1(1,1,1);

        v1 *= 2;

        assert(v1 == vec3(2,2,2));
    }
    {
        vec3 v1(1,0,0);
        vec3 v2(0,1,0);

        double res=dot(v1,v2);

        assert(res == 0.);
    }
    {
        vec3 v1(2,3,4);
        vec3 v2(1,1,1);

        double res=dot(v1,v2);

        assert(res == 9.);
    }
    {
        vec3 v1(0,0,0);
        vec3 v2(1,1,1);

        vec3 res=v1-v2;

        assert(res == vec3(-1,-1,-1));
    }
    {
        vec3 v1(1,1,1);
        vec3 v2(1,1,1);

        vec3 res=v1-v2;

        assert(res == vec3(0,0,0));
    }
    {
        vec3 v(1,1,1);

        double l = v.lengthSquared();

        assert(l == 3.);
    }
    {
        vec3 v(1,1,1);

        double l = v.length();

        assert(l == sqrt(3.));
    }
    {
        vec3 x(1,0,0);

        double l = x.length();

        assert(l == 1);
    }

    {
        vec3 x(1,0,0);
        vec3 z(0,0,1);

        vec3 res;

        res = cross(z,x);
        assert(res == vec3(0,1,0));
    }

    {
        vec3 y(0,1,0);
        vec3 z(0,0,1);

        vec3 res;

        res = cross(y,z);
        assert(res == vec3(1,0,0));
    }

    {
        vec3 x(1,0,0);
        vec3 y(0,1,0);

        vec3 res;

        res = cross(x,y);
        assert(res == vec3(0,0,1));
    }

    cout << "success "<<endl;

    return 0;
}
