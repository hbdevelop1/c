#include <iostream>
using namespace std;

void tail_factorial(int N, int &r)
{
	if(N<2)
		return;
	r*=N;
	tail_factorial(N-1, r);
}

int factorial(int N)
{
	int r = 1;
	tail_factorial(N, r);
	return r;
}

int main()
{
	cout << "factorial(4)="<<factorial(4)<<endl;
	
	return 0;
}