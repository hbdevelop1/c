/*

you were given a number N as Input 
then N numbers followed (where 3<=N<=2500). 
These N numbers were part of an Arithmetic Progression (of size N+1) from which one number was removed. 
So the task was to find that Missing number. For instance

5
1 3 5 9 11  

The output is 7

*/


#include <iostream>
#include <assert.h>
using namespace std;


bool IsMissing(int array[], int d, int lb, int ub)
{
//to do: negative elements, decreasing serie, 
 
	int nbrofelements_inarray = ub - lb + 1;
	int nbrofelements_intheory = (array[ub]-array[lb])/d + 1;

	cout << "array's size be " << nbrofelements_intheory << ", and it is " << nbrofelements_inarray << endl;

	if (nbrofelements_inarray == nbrofelements_intheory)
		return false;
	else if(nbrofelements_inarray < nbrofelements_intheory)
		return true;

	cout << "sth is wrong: " << nbrofelements_inarray << ", " << nbrofelements_intheory-1 << endl;
	assert(0);
	return false;
}

int f(int array[], int d , int lowerbound , int upperbound)
{
	int middle = lowerbound + (upperbound - lowerbound)/2;

	if(IsMissing(array, d, lowerbound, middle))
	{
		if(lowerbound+1 == middle)
		{
			return array[lowerbound]+d;
		}
		return f(array, d, lowerbound, middle);
	}
	else if(IsMissing(array, d, middle,upperbound))
	{
		if(middle+1 == upperbound)
		{
			return array[middle]+d;
		}
		return f(array, d, middle,upperbound);
	}
	else
	{
		cout << "nothing is missing !!!" << endl;
		return -1;
	}
}

/*
int GetMissing(array, 2, 0, 5)
{
	
	while(IsMissing())
	{
		
	}
}
*/
int main()
{
//	int array[]={1,3,5,7,9,11};
	int array[]={11,9,7,5,3,1
						//,-1000000
						};
/*
	char tt= 1000;
	int rr = 0x7fffffff;
	int rrr = -1.e6;
	cout << tt << hex << rr <<", "<< dec << rr << ", 0x"<< hex << rrr <<", "<< dec << rrr << endl; 
*/
	int len = sizeof(array)/sizeof(int);
	if(len < 3 || len >2500 )
	{
		return -1;
	}

	int ub = array[len-1];
	int lb = array[0];
	if(ub< -1.e6 || ub> 1.e6 || lb< -1.e6 || lb> 1.e6 )
	{
		return -1;
	}

	int step = (array[len-1] - array[0]) / (len-1);

	int missing = f(array, step, 0, len-1);
	if(missing>-1)
		cout << "missing number is :" << missing << endl;

	return 0;
}