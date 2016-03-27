
#include <iostream>

using namespace std;

template<int size=10>
ostream& operator<<(ostream& o, int *p)
{
    for(int i=0; i<size; ++i)
        o << p[i] << ",";
    return o;
}


void siftDown(int Array[], int root, int size)
{
  int left_child    = root * 2 + 1;
  int right_child   = root * 2 + 2;

  int child_with_max;

  if(left_child < size)
  {
      child_with_max = left_child;
  }
  else
  {
      return; //left_child does not exist
  }

  if(right_child < size)
  {
      child_with_max = (Array[right_child] > Array[left_child]) ? right_child : left_child;
  }

  // If we have the correct ordering, we are done.
  if(Array[root] >= Array[child_with_max])
      return;

  // Swap
  int temp = Array[root];
  Array[root] = Array[child_with_max];
  Array[child_with_max] = temp;

  // Tail queue recursion. Will be compiled as a loop with correct compiler switches.
  siftDown(Array, child_with_max, size);
}


void heapSort(int Array[], int array_size)
{
  int i, temp;

  for (i = (array_size-2) / 2; i >= 0; i--)
  {
    //cout << "root considered is "<< i <<"th :" << Array[i] <<endl;
    siftDown(Array, i, array_size - 1);
    cout << Array << endl;
  }

  for (i = array_size-1; i >= 1; i--)
  {
    // Swap
    temp = Array[0];
    Array[0] = Array[i];
    Array[i] = temp;

    siftDown(Array, 0, i-1);
  }
}


int main(int argc, char ** argv)
{
    int array[]={13,6,2,9,1,5,0};

    heapSort(array, sizeof(array)/sizeof(int));
    cout << array << endl;
    return 0;
}
