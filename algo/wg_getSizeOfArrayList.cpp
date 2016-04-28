//get size of an in-array list terminated by -1

#include <iostream>           // std::cout

using namespace std;

int getsize(int A[], int N)
{
    int i=0;
    int size=0;
    do
    {
        if(i>=N)
        {
            cout << "error in a value"<<endl;
            return 0;
        }

        i=A[i];
        ++size;
    }while(i != -1);

    return size;
}

int main ()
{
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    int A[]= { 4, 9, 8, 2, 5, 1, 5, 5,-1, 3};

    cout << "size of list is "<<getsize(A,10)<<endl;

    return 0;
}
