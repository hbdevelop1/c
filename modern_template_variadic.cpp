#include <iostream>
#include <memory>
#include <iterator>
#include <vector>
using namespace std;


template<class T1>
void fun(T1 t1)
{
    cout << t1;
}

template<class T1, typename... Ts>
void fun(T1 t1, Ts... ts )
{
    cout << t1<<",";
    fun(ts...);
}


int main()
{
    fun(4);
    char t=66;
    fun(t);
    ostream o = endl(cout);
    //fun(t,o);

    char & rt=t;
    fun(t,rt,66,2);
}

