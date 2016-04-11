#include<iostream>
#include<algorithm>
#include<vector>
#include <iterator>
#include<fstream>
#include <iomanip>      // std::setw
#include <sstream>
#include <array>
#include <memory>
using namespace std;

int main()
{
    int n=6;

    shared_ptr<char> arr(new char[n+1]);

    for(int i=1; i<=n; ++i)
    {
        std::cout << std::setw(n);
        int j=0;
        for(; j<i; ++j)
            arr.get()[j]= '#';
        arr.get()[j]= 0;

        cout << arr << '\n';
    }
}


int main6()
{
    int n=6;
    ostringstream oss2(ios_base::out | ios_base::ate | ios_base::app|ios_base::binary) ;
    std::ostream_iterator<char> out_it (oss2);
    for(int i=1; i<=n; ++i)
    {
        //std::cout << std::setw(n-i);
        for(int j=0; j<n-i; ++j)
            *out_it = ' ';
        for(int j=0; j<i; ++j)
            *out_it = '#';
        //fout<<endl;
        *out_it = '\n';
    }
    cout << oss2.str();
}

int main5()
{
    int n=6;
    ofstream fout("output.txt");
    std::ostream_iterator<char> out_it (fout);

    for(int i=1; i<=n; ++i)
    {
        //std::cout << std::setw(n-i);
        for(int j=0; j<n-i; ++j)
            *out_it = ' ';
        for(int j=0; j<i; ++j)
            *out_it = '#';
        //fout<<endl;
        *out_it = 13;
    }
    fout.close();
}

int main4()
{
    int n=6;
    std::ostream_iterator<char> out_it (std::cout);

    for(int i=1; i<n; ++i)
    {
        //std::cout << std::setw(n-i);
        for(int j=0; j<n-i; ++j)
            *out_it = ' ';
        for(int j=0; j<i; ++j)
            *out_it = '#';
        cout<<endl;
    }
}

int main3()
{
    int n=6;

    vector<char> line;
    line.resize(n);

    ofstream fout("output.txt");
    for(int i=1; i<6; ++i)
    {
        fill_n(line.begin()    , n-i,' ');
        fill_n(line.begin()+n-i, i  , '#');
        auto it = copy(line.begin(), line.end(), std::ostream_iterator<char>(fout,"hoho" ));
        //*it = endl;
        fout<<endl;

    }
    fout.close();

}

int main1()
{
    int n=6;

    vector<char> line;
    line.resize(n);
    for(int i=1; i<6; ++i)
    {
        fill_n(line.begin()    , n-i,' ');
        fill_n(line.begin()+n-i, i  , '#');
        copy(line.begin(), line.end(), std::ostream_iterator<char>(std::cout));
        cout << endl;
    }

}


int main2()
{
    vector<int> arr={4,3,2,1};
    int sum=0;
    for_each(arr.begin(), arr.end(), [&sum](int i){ sum+=i;});
    cout << "the sum is:" << sum <<endl;
}
