//get the area of the intersection of two rectangles

#include <iostream>           // std::cout

using namespace std;

#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)

int calarea(int K, int L, int M, int N, int P, int Q, int R, int S)
{
    int rect1_height = N-L;
    int rect1_width = M-K;

    int rect2_height = S-Q;
    int rect2_width = R-P;

    //assert if area overflows
    int area1 = rect1_height * rect1_width;
    int area2 = rect2_height * rect2_width;

    if(R<K || P>M)
    {
        cout << "no intersection";
        return area1 + area2;
    }
    else if(S<L || Q>N)
    {
        cout << "no intersection";
        return area1 + area2; //exess
    }
    else
    {
        int intersection_area = (MIN(M,R) - MAX(K,P)) * (MIN(N,S) - MAX(L,Q));
        return area1 + area2 - intersection_area;
    }
}

int main ()
{
    int K= -4;
    int L =1;
    int M=2;
    int N =6;
    int P=0, Q=-1, R=4, S=3;

    calarea(K,L,M,N, P,Q,R,S);

    return 0;
}
