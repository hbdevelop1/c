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


int main27()
{
    unsigned int t= 1;
    char *c = (char *)&t;
    if(*c)
        cout << "little endian" << endl;
    else
        cout << "big endian" << endl;
return 0;
}

