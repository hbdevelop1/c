
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;


string hbcompress2(string s)
{
    stringstream ss;
    string r;
    size_t j=0;
    size_t k=0;
    size_t i=0;

    while(i<s.size())
    {
        while(s[i] && s[j]==s[i]) ++i;

        int c=i-j;
        if(c>1)
        {
            //k += sprintf(&r[k],"%d%c",c,s[j]);
            ss<<c<<s[j];
        }
        else
        {
            //k += sprintf(&r[k],"%c",s[j]);
            ss<<s[j];
        }
        //cout << r.data()<<endl;
        j=i;
    }

    return ss.str();
}

string hbcompress(string s)
{
    string r;
    size_t j=0;
    size_t k=0;
    size_t i=0;

    while(i<s.size())
    {
        while(s[i] && s[j]==s[i]) ++i;

        int c=i-j;
        if(c>1)
        {
            k += sprintf(&r[k],"%d%c",c,s[j]);
        }
        else
        {
            k += sprintf(&r[k],"%c",s[j]);
        }
        //cout << r.data()<<endl;
        j=i;
    }
    return r;
}

int main73()
{


    string s = hbcompress2("AABBBCCCCCAADDDD");
    cout<< s.data() <<endl;

    s = hbcompress2("DDDD");
    cout<< s.data()<<endl;

    s = hbcompress2("");
    cout<< s.data()<<endl;

    s = hbcompress2("abc");
    cout<< s.data()<<endl;

    return 0;
}
