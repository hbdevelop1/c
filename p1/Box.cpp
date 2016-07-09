#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box
{
    int l=0;
    int b=0;
    int h=0;
public:
    Box(int _l=0, int _b=0, int _h=0):l(_l), b(_b), h(_h)
    {
        ++BoxesCreated;
    }
    Box(const Box& b):l(b.l), b(b.b), h(b.bh)
    {
        ++BoxesCreated;
    }
    ~Box()
    {
        ++BoxesDestructed;
    }

    friend ostream & operator<<(ostream & os, const Box & b);
};

ostream & operator<<(ostream & os, const Box & b)
{
    os << "box("<<b.l<<","<<b.b<<","<<b.h<<")";
    return os;
}











void check2()
{
    int n;
    //cin>>n;
    Box temp;
    cout << temp << endl;
}

/*
void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}
*/

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
