
//specialize a struct by deriving it from a specialization
//specialize a struct A<Edge> by deriving it from a specialization struct A<char>
//

#include <iostream>       // std::cout
#include <functional>     // std::ref
using namespace std;

typedef pair<ushort,ushort> Edge;

template <class T> struct A
{
    void f(T a)
    {
        cout << a << endl;
    }
};

template <> struct A<char>
{
    void f(char a)
    {
        cout<<"template <> struct A<char>:"<<hex<<(int)a << endl;
    }
    size_t operator()(char val) const noexcept
    {
        char t = (val<<4) | ((val & 0xf0)>>4);

        return t;
    }
};

template <> struct A<Edge>:public A<char>
{
    void f(Edge a)
    {
        cout<<"template <> struct A<Edge>:"<<hex<<(int)a.first << endl;
    }
    size_t operator()(Edge a) const noexcept
    {
        return A<char>::operator()((char)a.first);
    }
};


int main()
{

    A<int> a;
    a.f(4);


    A<char> g;
    char v68 = g(0x34);
    //g.f(15);
    cout << hex<<(int)v68 << endl;

    A<Edge> ae;
    Edge e;
    e.first=0x32;
    e.second=17;
    //ae.f(e);
    char v81 = ae(e);
    cout << hex<<(int)v81 << endl;
}
