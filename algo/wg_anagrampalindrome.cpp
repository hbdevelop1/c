//check if the string is an anagram of a palindrome

#include <iostream>           // std::cout
#include<memory.h>
using namespace std;

#define test(s)                 \
t=IsAnagramOfAPalidrome(s);    \
if(t)                           \
    cout << s << " is anagram of palindrome"<<endl;    \
else                                                    \
    cout << s << " is not anagram of palindrome"<<endl;



bool IsAnagramOfAPalidrome(const char *s)
{
    int A['z'-'a'+1];

    memset(A,0, sizeof(A));

    const char * p = s;

    while(*p)
    {
        A[*p-'a']++;
        p++;
    }

    bool odd_character_found=false;

    for(int i=0; i<'z'-'a'+1; ++i)
    {
        if(A[i] & 1)
        {
            if(odd_character_found)
                return false;
            odd_character_found=true;
        }
    }

    return true;
}

int main ()
{
    bool    t;

    test("ana");

    test("anag");
    test("anan");
    test("anta");
    test("ttanta");
    test("ttata");

    return 0;
}
