
//get the nearest point on a line to a point in space
//make sure that the line's vector director doesn't need to be unit, for the dot product if it is not unit in the ray given that
// vec3 nearestpointtothecenter = l.point + dot(w,l.director) * l.director;
//answer is : l.director should be normal for both operations, the dot and in the ray (see the use of the variable dir)
//otherwise we get the wrong nearest point to the center


#include "vec3.h"

struct Line
{
    vec3 point;
    vec3 director;
};

struct Sphere
{
    vec3 center;
    float radius;
};

int main()
{
    Line l{vec3{0,2,0}, vec3{0,0,-3}};

    Sphere s{vec3{0,1,3}, 3};

    vec3 w = s.center - l.point;

    vec3 dir = l.director;
    dir.normalize();
    float d = dot(w,dir);

    cout << d<<endl;
    if(d<0)
    {
        //cout<<"to deal with"<<endl;

        //d=-d;
        //inversing the dot product is not the correct way
        //but inversing the director of the line
    }

    vec3 nearestpointtothecenter = l.point + d * dir;
    cout <<"nearestpointtothecenter ="<< nearestpointtothecenter  <<endl;


    return 0;
}
