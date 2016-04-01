
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

template<int size=7>
ostream& operator<<(ostream& o, int *p)
{
    for(int i=0; i<size; ++i)
        o << p[i] << ",";
    return o;
}

template<int size=7>
ostream& operator<<(ostream& o, std::unique_ptr<int[]> & p)
{
    for(int i=0; i<size; ++i)
        o << p[i] << ",";
    return o;
}

#define _debug_

std::unique_ptr<int[]> g_ordered;
int g_ordered_k;


#define swap(a,b) {int t=a; a=b; b=t;}
namespace quick
{

    void sort(int array[], int lower_boundry, int higher_boundry)
    {
        int pivot_index=lower_boundry + (higher_boundry-lower_boundry)/2;
        //int temp = array[pivot_index]; array[pivot_index]=array[higher_boundry]; array[higher_boundry]=temp;

//        int pivot = higher_boundry;
        int insertion_position = lower_boundry;
        for(int i=lower_boundry; i<higher_boundry; ++i)
        {
            if(array[i]<array[pivot_index])
            {
                swap(array[insertion_position],array[i]);
                //int t = array[insertion_position]; array[insertion_position]=array[i] ; array[i]=t;
                ++insertion_position;
            }
        }
        swap(array[insertion_position],array[pivot_index]);
        cout << array << endl;
    }

}


int main(int argc, char ** argv)
{
    int g_array[]={13,0,9,5,1,2,6};

    int array_size = sizeof(g_array)/sizeof(int);

    quick::sort(g_array, 0, 6);
    g_ordered = std::unique_ptr<int[]>(new int[array_size]);

    //mergeSort(g_array, array_size);


    cout << g_array<< endl;

    return 0;
}
