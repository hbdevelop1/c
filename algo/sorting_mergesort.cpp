
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




void merge(int array1[], int array1_size, int array2[], int array2_size)
{
    if(array1_size<=0 && array2_size<=0)
    {
        return;
    }
#ifdef _debug_
    cout << "merging :{";
    for(int i=0; i<array1_size; ++i)
    {
        cout << array1[i] << ",";
    }
    cout << "} and {";
    for(int i=0; i<array2_size; ++i)
    {
        cout << array2[i] << ",";
    }
    cout << "}" << endl;
#endif _debug_

    if(array1_size<=0)
    {
        g_ordered[g_ordered_k++]=array2[0];
        merge(array1, array1_size, array2+1, array2_size-1);
    }
    else if(array2_size<=0)
    {
        g_ordered[g_ordered_k++]=array1[0];
        merge(array1+1, array1_size-1, array2, array2_size);
    }
    else if(array1[0]<array2[0])
    {
        g_ordered[g_ordered_k++]=array1[0];
        merge(array1+1, array1_size-1, array2, array2_size);
    }
    else
    {
        g_ordered[g_ordered_k++]=array2[0];
        merge(array1, array1_size, array2+1, array2_size-1);
    }
}

void mergeSort(int Array[], int array_size)
{
    if(array_size == 1)
        return;

    int mid = array_size/2;

    int *array1 = Array;
    int *array2 = Array+mid;

    mergeSort(array1, mid);
    mergeSort(array2, array_size-mid);

    g_ordered_k=0;
    for(int i=0; i<array_size; ++i)        memset(g_ordered.get(), 0, 10*sizeof(int));

    merge(array1, mid, array2, array_size-mid);

    for(int i=0; i<array_size; ++i)
    {
        array1[i]=g_ordered[i];
    }

#ifdef _debug_
    cout << "temp result:"<< g_ordered << endl;
#endif _debug_
}


int main(int argc, char ** argv)
{
    int g_array[]={13,6,2,9,1,5,0};

    int array_size = sizeof(g_array)/sizeof(int);

    g_ordered = std::unique_ptr<int[]>(new int[array_size]);

    mergeSort(g_array, array_size);


    cout << g_array<< endl;

    return 0;
}

void testing()
{
    {
        g_ordered_k=0;

        int array1[]={20,15,39,115};
        int array1_size=0;
        int array2[]={3,4,7,25,35};
        int array2_size=5;

        merge(array1, array1_size, array2, array2_size);
        cout << g_ordered << endl;
    }
    {
        g_ordered_k=0;

        int array1[]={2,5,9,15};
        int array1_size=4;
        int array2[]={3,4,7,25,35};
        int array2_size=5;

        merge(array1, array1_size, array2, array2_size);
        cout << g_ordered << endl;
    }
    {
        g_ordered_k=0;

        int array1[]={20,15,39,115};
        int array1_size=4;
        int array2[]={3,4,7,25,35};
        int array2_size=5;

        merge(array1, array1_size, array2, array2_size);
        cout << g_ordered << endl;
    }

}
