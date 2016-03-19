#include <iostream>
using namespace std;

int search(int array[], int n, int lowerbound, int upperbound)
{
	if (lowerbound > upperbound)
		return -1;

	int middle = lowerbound + (upperbound - lowerbound) / 2;

	if(n == array[middle])
	{
		return middle;
	}
	else if(n < array[middle])
	{
		return search(array, n, lowerbound, middle-1);
	}
	else //if(n > array[middle])
	{
		return search(array, n, middle+1, upperbound);
	}

}


int main()
{
	int array[]={1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,100};

	int r = search(array, 100, 0, 19);
	cout << "index is :"<< r << endl;

	return 0;
}