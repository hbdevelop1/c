
#include <iostream>
#include <memory>
#include <cstring>
#include<iterator>
#include<algorithm>

using namespace std;

namespace sorting
{
#define swap2(a,b) \
    if(a!=b)   \
{               \
    a=a^b;         \
    b=a^b;         \
    a=a^b;      \
}

#define swap23(a,b) \
{                  \
    decltype(a) t=a;         \
    a=b;         \
    b=t;      \
}

void swap(int &a, int &b)
{
   // decltype(a)
int            t=a;
    a=b;
    b=t;
}

void quick(int A[], int lowerbound, int upperbound)
{
    int size=upperbound-lowerbound+1;

    int pivot_index = lowerbound+size/2;

    int insertion_index = lowerbound;

    swap2(A[upperbound],A[pivot_index]);

    for(int i=lowerbound; i<upperbound; ++i)
    {
        if(A[i]<A[upperbound])
        {
            //if(insertion_index != i)
            {
                swap2(A[insertion_index],A[i]);
            }
            insertion_index++;
        }
    }

    //if(insertion_index != upperbound)
    {
        swap2(A[insertion_index],A[upperbound]);
    }

    if(lowerbound<insertion_index-1)
        quick(A,lowerbound,insertion_index-1);

    if(insertion_index+1<upperbound)
        quick(A,insertion_index+1,upperbound);
}

}

int main()
{
    int A[]={9,5,2,8,4,0,7,6,3,1};

    //swap(A[1],A[1]);
    sorting::quick(A,0,9);

    copy(A,A+10,ostream_iterator<int>(cout,","));


    return 0;
}
