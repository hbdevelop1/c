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
#include<cstring>


using namespace std::placeholders;    // adds visibility of _1, _2, _3,...
using namespace std;


struct hvector
{
    int x,y,z;
};

int main()
{
    hvector v{2,2,2};

    hvector *pv=&v;
    cout << sizeof(pv)<< "," << sizeof(*pv)<<endl;
    memset(pv, 0,
           //sizeof(int)
           sizeof(pv)
           );

    memset(pv, '#',8);

    return 0;

    int q=8;
    int * const p=&q;
    *p=7;
    cout<<q<<endl;

    int r=-4;
    cout << hex<<-1u <<"," <<endl;

    printf("% 5d\n", q);





    return 0;
}

