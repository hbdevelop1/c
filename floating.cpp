#include<iostream>

using namespace std;

//get the max float value
int main ()
{
    int max_rep = 0x7FFFFFFF;    
    float a = *reinterpret_cast<float*>(&max_rep);
    cout << "a="<<a<< endl;
    return 0;
}

int main6 ()
{
    float a =0.5f; //=0x3F000000
    float b =0.25f; //expected=0x3E000000 got=0x3E800000
    cout << "a="<<a<< endl;
    return 0;
}

int main26 ()
{
    float r =0.f;  //=0x00000000
    float a =0.1f; //=0x3dcccccd
    float b =1.0f; //expected=0x3F800000
    float c =2.0f; //expected: 1.mantissa x 2^1=1.0 x 2^(128-127) = 0x40000000
    int nan_rep = 0x7fc00000;
    float nan=*reinterpret_cast<float*>(&nan_rep);
    float nan1=sqrt(-1);
    cout << "nan="<<nan << endl;
    cout << "nan1="<<nan1 << endl;
    return 0;
}
