#include <iostream>
using namespace std;

template<typename T>
class B
{
public:
  void f() { }  // Member of class B<T>
};
template<typename T>
class D : public B<T>
{
public:
    D()
    {
    }
    D(const D & r)
    {
        cout << "copy constructor"<<endl;
    }

  D g()
  {

    this->f();  // Bad (even though some compilers erroneously (temporarily?) accept it)
      return *this;
  }
};

class BigClass
{
    int x;
    int y;
    int z;
public:
    BigClass(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};

template<typename>
  struct remove_reference1;

template<typename _Tp>
  struct remove_reference1
  {
      typedef _Tp type;
      remove_reference1()
      {
          cout<<"remove_reference1 1"<<endl;
      }
  };

template<typename _Tp>
  struct remove_reference1<_Tp&>
  {
      typedef _Tp type;
      typedef float type2;
      remove_reference1()
      {
          cout<<"remove_reference1 2"<<endl;
      }
  };

template<typename _Tp>
  struct remove_reference1<_Tp&&>
  {
      typedef _Tp type;
      remove_reference1()
      {
          cout<<"remove_reference1 3";
      }
  };

void swap(BigClass& a, BigClass& b)	// "perfect swap" (almost)
{
    BigClass tmp = move(a);	// could invalidate a
    a = move(b);		// could invalidate b
    b = move(tmp);		// could invalidate tmp
}

int main()
{
    D<int> d;
    D<int> && d2=d.g();
    d=d2;
BigClass bc1(1,1,1);
BigClass bc2(5,5,5);
swap(bc1,bc2);
/*
remove_reference1<int> a1;
remove_reference1<int&> a2=a1;
//remove_reference1<int> && a3=a1;
*/
    //int && r =2;   cout << r;
}
