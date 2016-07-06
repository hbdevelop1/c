//hassan::vector supports for range

#include <iostream>
#include <memory>
#include <iterator>
//#include <vector>
using namespace std;
/*
class A
{

};
class B: public A
{

};

void f()
{
    try
    {
        throw B;
    }
    catch(B & b)
    {
        cout << "catch(B b)"<<endl;
    }
    catch(A & a)
    {
        cout << "catch(A a)"<<endl;
    }
}
*/

struct vec3
{

    float x,y,z;
public:


};

namespace hassan
{
template <class T>
class vector
{
    T a[10];
	int size;
public:
    struct it
    {

    };

public:
    vector(const std::initializer_list<T> & l)
    {
        size=0;
        for(auto v:l)
        {
            a[size]=v;
            ++size;
        }
    }
  //  typename T::it begin(){return a.begin();}
    //typename T::it end(){return a.end();}
	void push_back(T&& e)
	{
		a[size++]=e;
	}
	const T* begin(){return a;}
	const T* end(){return a+size;}
};

}

int main()
{

    hassan::vector<vec3> vv{{1,2,3},{4,5,6,},{7,8,9}};
    for(auto v:vv)
    {
        cout<<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
    }
	vv.push_back(vec3{0,9,8});
    for(auto v:vv)
    {
        cout<<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
    }
/*
    hassan::vector<int> vi{1,2,3,4,5,6,};
    for(auto v:vi)
    {
        cout<<v<<endl;
    }
*/
    return 0;
}
