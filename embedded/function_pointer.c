
#include <stdio.h>

void report(int i, int j)
{
    printf("%d,%d\n",i,j);
}

int main()
{

    void (*p)(int,int);
    p=report;


    p(1,2);

    (*p)(1,2);

    return 0;
}
