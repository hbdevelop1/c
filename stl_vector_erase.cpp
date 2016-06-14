// erase elements in a vector inside a loop

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <cstdio>
#include <sstream>

using namespace std;

int main ()
{
    
    do
    {
        int val;
        char buf[200];
        vector<int> vi{1,2,3,4,5,6,7,8,9,10};

        copy(vi.begin(), vi.end(), ostream_iterator<int>(cout));
        cout<<endl;
/*
        cin.clear();
        cin.ignore(256,'\n');// Ignore rest of line
        cin>> val;
   */
        cout<<"enter the value to remove, or 12 to quit :";
/*        cin >> val;
        cin.ignore(10,'\n');
        cin.clear();
         */
         
        string str;         
        std::getline (std::cin, str);
        val=atoi(str.c_str());

        //scanf("%d", &val);
        //gets(buf);
        
        //std::getline (std::cin, str);
        //str>>val;
        //stringstream oss;
        //cin >> str;
        //oss>>val;    
        
        
        if(val==12)
            break;
         
        auto it=vi.begin();
        while(1)
        {
                if(*it == val || *it == val+2)
                {
                    it=vi.erase(it);                
                }
                if(it==vi.end())
                    break;
                else
                    ++it;
        }
        
        copy(vi.begin(), vi.end(), ostream_iterator<int>(cout));
        cout<<endl;
        
    }while(1);
        
  return 0;
}
