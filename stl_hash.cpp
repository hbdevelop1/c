
//C++:template:STL: specializing hash struct for Edge type.
//specializing an STL template, needs to be enclosed in std namespace. otherwise error.

#include <iostream>       // std::cout
#include <functional>     // std::ref
using namespace std;

typedef pair<ushort,ushort> Edge;


namespace std
{
template<> struct hash<Edge>:public std::hash< unsigned int>
{
    size_t operator()(Edge val) const noexcept
    {
        unsigned int t = (val.first<<16) | val.second;
        return std::hash< unsigned int>::operator()(t);
    }
};
}

int main()
{
    Edge v;
    v.first=0xc1;
    v.second=0x10;

    hash<Edge> h;
    uint r = h(v);
    cout << hex<<r << endl;
}
