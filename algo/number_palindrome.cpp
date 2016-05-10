
#include <iostream>
using namespace std;

bool isPalindrome(int N)
{
    int i=0;
    int A = 0;
    int n = N;

    while(N)
    {
        int r = N%10;
        N = N/10;
        A = A*10 + r;
        i++;
        //printf("i=%d,N=%d,r=%d,A=%d\n",i,N,r,A);
    }

    return A == n;

}

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        cout <<"wrong number of args\n";
        return -1;
    }
    int N = atoi(argv[1]);

    bool t = isPalindrome(N);

    cout << N << " is ";

    t ? cout << "a palindrome\n" : cout << "not a palindrome\n" ;

    return 0;
}
