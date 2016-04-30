#include<iostream>
#include<algorithm>
#include<vector>
#include <iterator>
#include<fstream>
#include <iomanip>      // std::setw
#include <sstream>
#include <array>
#include <memory>
#include<list>
#include<set>
#include<functional>
using namespace std::placeholders;    // adds visibility of _1, _2, _3,...
using namespace std;



static const unsigned char BitsSetTable256[256] =
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

void output()
{

}

int main()
{
    unsigned int v=3; // count the number of bits set in v
    unsigned int c; // c accumulates the total bits set in v
    for (c = 0, cout<<"c=0\n"; v && cout<<"v="<<v<<"\n"; c++, cout<<"c++="<<c<<"\n")
    {
      v &= v - 1; // clear the least significant bit set
      cout<<"op:"<<v<<"\n";
    }
}


int main43()
{


    int r= 0x1471;
    int r1=r;
    int n=0;
    while(r1)
    {
        if(r1 & 1) ++n;
        r1 >>= 1;
    }
    printf("number of bits set in %d is: %d\n",r,n);

    return 0;
}

