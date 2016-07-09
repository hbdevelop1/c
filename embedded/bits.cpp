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

int main31()
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


int main()
{
    uint8_t a=8;
    uint8_t b=7;
    uint8_t c=12;
    uint8_t d=14;

    uint8_t e=13;
    uint8_t f=3;
    uint8_t g=5;
    uint8_t h=10;

    unsigned char r=0;
    r^=a;
    r^=b;
    r^=c;
    r^=d;
    r^=e;
    r^=f;
    r^=g;
    r^=h;

    printf("r=0x%01X\n",r);

    r=0;
    r^=d;
    r^=a;
    r^=f;
    r^=b;
    r^=c;
    r^=g;
    r^=e;
    r^=h;

    printf("r=0x%01X\n",r);

    uint8_t arr[]={8,7,12,14,13,3,5,10};
    uint32_t *p1= (uint32_t *)arr;
    uint32_t r1=0;
    //r1=

    return 0;
}
