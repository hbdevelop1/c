
//new operator overloaded for a class and its base class

#include <iostream>
using namespace std;

class Object
{
public:
    void *operator new(size_t s)
    {
        cout<<"operator new called for "<<s<<" bytes"<<endl;
        return ::operator new(s);
    }

    void operator delete(void *p)
    {
        cout<<"operator delete called for"<< p << endl;
        ::operator delete(p);
    }

    void * operator new[](size_t s)
    {
      void *p = ::operator new[](s);
      cout <<"my new[], size :"<<dec<<s<<" at "<<hex<< p <<endl;      
      return p;
    }
    void operator delete[](void *p)
    {
      cout <<"my delete[] :"<<hex<<p<<endl;
      ::operator delete[](p);
    }    
};

class Point : public Object
{
    int x;
    int y;
public:
    Point(int _x, int _y):x(_x),y(_y){}
    friend ostream& operator<<(ostream& os, const Point & point);
/*
    void *operator new(size_t s)
    {
        cout<<"operator new called for "<<s<<" bytes"<<endl;
        return ::operator new(s);
    }

    void operator delete(void *p)
    {
        cout<<"operator delete called for"<< p << endl;
        ::operator delete(p);
    }
    */
};

ostream& operator<<(ostream& os, const Point & point)
{
    os << "point(" <<point.x<< ","<<point.y<< ")";
    return os;
}

int main()
{
    Object *po = new Object;
    cout << "object at "<<po<< endl;

    Point *pi = new Point(2,6);
    cout << *pi<< " at "<<pi<< endl;
    delete pi;
    delete po;
}
