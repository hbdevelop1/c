#include <assert.h>
#include <iostream>
using namespace std;


#include "plane.cpp"

int main()
{

    {
        vec3 n=vec3(1,1,1);
        n.normalize();
        vec3 p(0,1,0);
        double d;

        Plane pl(n,p);

        vec3 p1(0,0,1);
        d = pl.DistanceFromPoint(p1);
        cout << p1<<" is "<<d<<" from the plane"<<endl;

        vec3 p2(0,3,-2);
        d = pl.DistanceFromPoint(p2);
        cout << p2<<" is "<<d<<" from the plane"<<endl;
    }
    {
        vec3 n=vec3(1,1,1);
        n.normalize();
        vec3 p(0,1,0);

        Plane pl(n,p);
        double d = pl.DistanceFromPoint(vec3(0,0,0));
        cout << "(0,0,0) is "<<d<<" from the plane"<<endl;
    }
    {
        vec3 n=vec3(1,1,1);
        n.normalize();
        vec3 p(0,1,0);

        Plane pl(n,p);
    }
    {
        vec3 n(1,0,0);
        vec3 p(0,1,0);

        Plane pl(n,p);
    }

    cout << "test plane - success "<<endl;

    return 0;
}
