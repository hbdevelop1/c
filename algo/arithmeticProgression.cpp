#include <iostream>
#include <assert.h>
using namespace std;


bool IsMissing(int array[], int d, int i, int j)
{
//to do: negative elements, decreasing serie, 
 
	assert(array[i]< array[j]);

	int nbrofelements_inarray = j - i + 1;
	int nbrofelements_intheory = (array[j]-array[i])/d + 1;

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
	int array[]={1,3,5,7,9,11};

//	if(GetMissing(array, 2, 0, 5))
/*	if(IsMissing(array, 2, 0, sizeof(array)/sizeof(int) - 1))
		cout << "missing." << endl;
	else
		cout << "complete." << endl;
		*/

	int missing = f(array, 2, 0, sizeof(array)/sizeof(int) - 1);
	if(missing>-1)
		cout << "missing number is :" << missing << endl;

	return 0;
}