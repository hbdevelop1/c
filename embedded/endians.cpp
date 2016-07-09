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

int main16()
{
    unsigned int t= 1;
    char *c = (char *)&t;
    if(*c)
        cout << "little endian" << endl;
    else
        cout << "big endian" << endl;
return 0;
}

uint16_t swap(uint16_t v)
{
    return ((v & 0x00FF) << 8) | ((v & 0xFF00) >> 8 );
}


uint32_t swap(uint32_t v)
{
    return (    
                       ((v & 0x000000FF) << 24) | 
                       ((v & 0x0000FF00) << 8)   |
                       ((v & 0x00FF0000) >> 8)   |
                       ((v & 0xFF000000) >> 24) 
                );
}

int main()
{
    unsigned int a= 0x11bb99aa;
    unsigned short b= 0x1199;
    
    uint32_t  q=swap(a);
    uint16_t w=swap(b);

    cout <<  hex;
    cout << a << " ---> "<< q << endl;
    cout << b << " ---> "<<w<< endl;
    
return 0;
}

