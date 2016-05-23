
#include <stdio.h>


int main()
{
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

    printf("%#X %#X %#X\n",a, a+1, &a+1);

    return 0;
}
/*
0XFFFFDF10 0XFFFFDF20 0XFFFFDF40

0x7fffffffdf10:	1	2	3	4
0x7fffffffdf20:	5	6	7	8
0x7fffffffdf30:	9	10	11	12
0x7fffffffdf40:	-8144	32767	1847902208	2114801809
*/
