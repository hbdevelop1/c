
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


int main47()
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
	
	return 0;
}


template <class T> struct B
{
    void f(T a)
    {
        cout << a << endl;
    }
    void f1(float a)
    {
        cout << "int version:"<<a << endl;
    }
};

int main83()
{
	B<int> b;
	//b.f(4);
	
	B<char> c;
	c.f('4');

	B<float> c2;
	c2.f(4.f);
	
	return 0;
}

template<typename _Tp, typename _Alloc >
class hvector
{
public:
    hvector()
    {
        cout << "template<typename _Tp, typename _Alloc >"<<endl;
        }
 };
template <class Allocinting> 
class hvector<bool, Allocinting> 
{
public:
    
    hvector()
    {
        cout << "class hvector<bool, Allocinting> "<<endl;
        }
 };

int main117()
{
    hvector<A<int>,B<int>> v1;
    hvector<bool,B<int>> v2;
    
    
    return 0;
}

class big
{
public:
    big() {cout << "big constructor"<<endl;}
    template<int N> void print() { cout << "print "<<N<<endl;}
    template<int N> static void print2() { cout << "static print "<<N<<endl;}
};

int main134()
{
    big b;
    b.print<7>();
    big::print2<7>();
    return 0;
}
