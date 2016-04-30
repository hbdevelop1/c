#include<iostream>
#include<algorithm>
#include<vector>
#include <iterator>
#include<fstream>
#include <iomanip>      // std::setw
#include <sstream>
#include <array>
#include <memory>
#include<list>
#include<set>
#include<functional>
using namespace std::placeholders;    // adds visibility of _1, _2, _3,...
using namespace std;


//1-remove elements from a container which died function returns true;
//2-using search_n, get the first element that is lesser than a val.
//3-use std::basic_string to have kind of a list of objects. define object's traits. and allocator.
//   what is the difference between basic_string of objects and list of objects ?
//   <- the difference is that basic_string is geared toward string of char, wchar, ... like it has a c_str function that return chatT*


#if 0
#define hmin(a,b) ((a)<=(b)?(a):(b))
int main()
{
    int aa[]={20,30,40};
    int *p=aa;

    //int e = *p++;

    int b= 50;
    int ret = hmin(*++p,b);

    printf("*p == %d\n",*p);

    return 0;
}


float TurnIntoZeroPointFloat(int number)
{
    if(number==0)
        return 0.f;

    stringstream ss;
    if(number<0)
    {
        ss<<"-";
        number *= -1;
    }

    ss << "0.";
    ss << number;

    float value;
    ss>> value;

    return value;
}

int main26()
{
    float ret = TurnIntoZeroPointFloat(4962);
    cout << ret << endl;
return 0;

}


int main25()
{
    int v = 4;
    int sign = (v > 0) - (v < 0);//0-1

    cout << sign << endl;
}

int main24()
{
  // an array of functions:
  std::function<int(int,int)> fn[] = {
    std::plus<int>(),
    std::minus<int>(),
    std::multiplies<int>()
  };

  for (auto& x: fn) std::cout << x(10,5) << '\n';

  return 0;
}

// a function:
int half(int x) {return x/2;}

// a function object class:
struct third_t {
  int operator()(int x) {return x/3;}
};

// a class with data members:
struct MyValue {
  int value;
  int fifth() {return value/5;}
};

int main23()
{
  std::function<int(int)> fn1 = half;                    // function
  std::function<int(int)> fn2 = &half;                   // function pointer
  std::function<int(int)> fn3 = third_t();               // function object
  std::function<int(int)> fn4 = [](int x){return x/4;};  // lambda expression
  std::function<int(int)> fn5 = std::negate<int>();      // standard function object

  std::cout << "fn1(60): " << fn1(60) << '\n';
  std::cout << "fn2(60): " << fn2(60) << '\n';
  std::cout << "fn3(60): " << fn3(60) << '\n';
  std::cout << "fn4(60): " << fn4(60) << '\n';
  std::cout << "fn5(60): " << fn5(60) << '\n';

  // stuff with members:
  std::function<int(MyValue&)> value = &MyValue::value;  // pointer to data member
  std::function<int(MyValue&)> fifth = &MyValue::fifth;  // pointer to member function

  MyValue sixty {60};

  std::cout << "value(sixty): " << value(sixty) << '\n';
  std::cout << "fifth(sixty): " << fifth(sixty) << '\n';

  return 0;
}

int main22()
//int main()
{
    greater<int> fun_gt;
    cout << fun_gt(3,4)<<endl;

    auto b=std::bind(greater<int>(), _2, _1);
    cout << b(3,4)<<endl;

    int arr[]={1,2,3,4,5,6};
    vector<int> v(arr, arr+6);
    //copy(v.begin(),v.end(),ostream_iterator<int>(cout, ","));

    auto it_first=find_if(v.begin(),v.end(),std::bind(fun_gt, _1, 4));
    cout<<"the first number greater than 4 is:"<<*it_first<<endl;
}


// static_pointer_cast example

struct A {
  static const char* static_type;
  const char* dynamic_type;
  A() { dynamic_type = static_type; }
};
struct B: A {
  static const char* static_type;
  B() { dynamic_type = static_type; }
};

const char* A::static_type = "class A";
const char* B::static_type = "class B";

int main20 () {
  std::shared_ptr<A> foo;
  std::shared_ptr<B> bar;

  foo = std::make_shared<A>();

  // cast of potentially incomplete object, but ok as a static cast:
  //bar = std::static_pointer_cast<B>(foo);
  bar = std::static_pointer_cast<B>(foo);

  B* bar2=bar.get();

  std::cout << "foo's static  type: " << foo->static_type << '\n';
  std::cout << "foo's dynamic type: " << foo->dynamic_type << '\n';
  std::cout << "bar's static  type: " << bar->static_type << '\n';
  std::cout << "bar's dynamic type: " << bar->dynamic_type << '\n';
  std::cout << "bar2's static  type: " << bar2->static_type << '\n';

  return 0;
}
int main19()
{
    B b1;
    B *b1p=&b1;
    cout << b1.B::static_type<<endl;
    cout << b1p->static_type<<endl;
}

int main18()
{
  std::vector<bool> mask;

  mask.push_back(true);
  mask.push_back(false);
  mask.push_back(false);
  mask.push_back(true);

  mask.flip();

  std::cout << std::boolalpha;
  std::cout << "mask contains:";
  for (unsigned i=0; i<mask.size(); i++)
    std::cout << ' ' << mask.at(i);
  std::cout << '\n';
  for (unsigned i=0; i<mask.size(); i++)
    std::cout << ' ' << mask[i];
  std::cout << '\n';
  for (auto it=mask.begin(); it!=mask.end(); ++it)
    std::cout << ' ' << *it;

  return 0;
}

int main17()
{
    std::cout.setf (std::ios_base::dec , std::ios_base::basefield);
      std::cout.setf (std::ios_base::showbase);
      //std::cout.setf (std::ios_base::showpoint);
      std::cout.setf (std::ios_base::internal, std::ios_base::adjustfield);
      std::cout << std::setfill ('x')<<std::setw(10)<< 10.1 << '\n';
}

int main16()
{
    multiset<int> msi({10,10,20,30,30,30});

    auto bounds =msi.equal_range(20);
    if(*bounds.first == 20)
        cout<<"Yes. at pos"<<distance(msi.begin(),bounds.first)<<endl;
    else
        cout <<"No. next found:"<<*bounds.first<<" at pos "<<distance(msi.begin(),bounds.first)<<endl;
}

int main15()
{
    vector<int> vi({10,10,20,30,30,30});

    auto bounds =equal_range(vi.begin(),vi.end(),20);
    if(*bounds.first == 20)
        cout<<"Yes. found at "<<bounds.first-vi.begin()<<endl;
    else
        cout <<"No. next found:"<<*bounds.first<<" at "<< bounds.first-vi.begin()<<endl;
}

int main14()
{
    //set<int> si({10,10,20,30,30,30});
    int sizeofarray;
    cout<<"enter the size of array:";
    cin>>sizeofarray;
    if(sizeofarray<=0)
        return 1;

    vector<int> vi({10,10,20,30,30,30});
    //vi.resize(sizeofarray);
    auto it_insert=back_inserter(vi);
    int y;
    cout<<"enter the "<<sizeofarray<<" elements into the array:";
    for(int i=0; i<sizeofarray; ++i )
    {
        cin>>y;
        it_insert=y;
    }
}

int main13 ()
{
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 15); //          ^
  up= std::upper_bound (v.begin(), v.end(), 15); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}

//stringstream
int main12()
{
    stringstream oss2(ios_base::in |ios_base::out | ios_base::ate | ios_base::app|ios_base::binary) ;

    int i=6;
    char t='t';

    oss2<<222 <<","<<t<<","<< i;

    int y=99;
    char t1, t2,t3;
    int ii;

    oss2.seekg(0);
    oss2>>y;
    /*
    shared_ptr<char> buffer(new char [100]);

        // read data as a block:
        oss2.read (buffer.get(),30);
cout << buffer<<endl;
*/
    oss2>>t1;
    oss2>>t2;
    oss2>>t3;
    oss2>>ii;
    cout<<y<<"-"<<t1<<"-"<<t2<<"-"<<t3<<"-"<<ii<<endl;
return 0;

}

int main11()
{
    set<int> coll;

    //create insert iterator for coll
    insert_iterator<set<int> > iter(coll,coll.begin());

    //insert elements with the usual iterator interface
    *iter = 1;
    iter++;  //insert_iterator supports all other typical operations of output iterators
            //but have no effect. removing this incrementation has no effect
    *iter = 2;

    //inserter using inserter function
    inserter(coll,coll.end()) = 44;
    inserter(coll,prev(coll.end())) = 43;

    copy (coll.begin(), coll.end(), ostream_iterator<int>(cout,","));

}

int main10()
{
    list<int> li;
    auto it = front_inserter(li);
    it=1;
    it=4;
    it=7;
    it=2;
    copy(begin(li), end(li), ostream_iterator<int>(cout,","));
}

int main9()
{
    vector<int> vi;
    auto it = back_inserter(vi);
    it=1;
    it=4;
    it=7;
    it=2;
    auto it_out=copy(begin(vi), end(vi), ostream_iterator<int>(cout,","));
    cout<<endl;

    reverse_iterator<vector<int>::iterator> begin_r(vi.end());
    reverse_iterator<vector<int>::iterator> end_r(begin(vi));
    copy(begin_r, end_r, ostream_iterator<int>(cout,","));
}


template<typename A, typename B>
void aresameclasses(A* a, B* b)
{
    //a=b;      b=a;
}

int main8()
{
    vector<int>::iterator::iterator_category vic;
    list<int>::iterator::iterator_category lic;
    aresameclasses(&vic,&lic);

}

int main7()
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
        auto it = copy(line.begin(), line.end(), std::ostream_iterator<char>(std::cout));
        //cout << endl;
        *it='\n';
    }

}


int main2()
{
    vector<int> arr={4,3,2,1};
    int sum=0;
    for_each(arr.begin(), arr.end(), [&sum](int i){ sum+=i;});
    cout << "the sum is:" << sum <<endl;
}
#endif
