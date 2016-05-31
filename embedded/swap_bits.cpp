
#include <iostream>
#include <memory>
#include <cstring>
#include<iterator>
#include<algorithm>

using namespace std;


#define swap_bits(a,b) \
    if((a)!=(b))   \
{               \
    (a)=(a)^(b);         \
    (b)=(a)^(b);         \
    (a)=(a)^(b);      \
}

int main()
{
    int A[]={9,5,2,8,4,0,7,6,3,1};

    int s = sizeof(A)/sizeof(A[0]);
    for(int i=0; i< s; ++i)
    {
        for(int j=i+1; j<s; ++j)
        {
            auto a=A[i];
            auto b=A[j];

            cout<<"swaping "<<"("<<a<<","<<b<<")";

            swap_bits(a,b);

            cout<<"->"<<a<<","<<b<<endl;
        }
    }
    return 0;
}

