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


int main()
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

