//3-throw;
//in a catch bloc it will rethrow the same exception object to the upper level

//6-throw obj;
//in a catch bloc it will throw ref/pointer to obj to the upper level.
//But, the catch bloc receiving the original type will not be called.
//throw (Fruit&)obj; //catch(Orange &f) will not be called

//4-throw;
//inside try or in the code calls terminate function (which calls the termination handler), even if there is a catch(...) block
//no usable catch block is found

//5-terminate();
//will call the termination handler. it could be the default or the user one

//7-unexpected is called when the execption is not listed in its dynamic-exception-specifier (i.e., in its throw specifier).
//int main()  throw(Botch::Fruit, Botch::Orange) and exception is an int

#include <exception>
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;
 
void terminator()
{
  cout << "terminator!" << endl;
  exit(0);
}
 
void (*old_terminate)() = set_terminate(terminator);

class someClass 
{	
public:
    ~someClass()
    {
        cout << "someClass::~someClass" << endl;
    }
    void f()
    {
        cout << "someClass::f" << endl;
    }
};


class Botch
{
public:
    class Fruit
    {
    public: int x=4;
    };
    class Apple:public Fruit
    {

    };
    class Orange:public Fruit
    {

    };

    void f() throw()
    {
        someClass sc;
        cout << "Botch::f()" << endl;
        throw Orange();
        sc.f();
    }
    ~Botch() {
//	  throw 'c'; 
  }
};
 
void hb_unexpected()
{
    cout <<"hb_unexpected()"<<endl;
} 
int main()  throw(Botch::Fruit, Botch::Orange)
{
    set_unexpected(hb_unexpected);
    //5-
    //terminate();

    //7-
    //throw 7; //unexpected and terminate are called if int is not in execption list
    //throw 7; //terminate is called otherwise
    

    try
    {
        Botch b;

        //4-
        //throw;

        try
        {
            //7-
            throw 7; //unexpected is called
            b.f();
            
        }
        catch(Botch::Fruit & f)
        {
            cout << "inside catch1(...)" << endl;
            f.x=5;
            //6-
            //throw f;
            throw;
        }
    }
    catch(Botch::Orange & f)
    {
        cout << "inside catch2(orange)" <<f.x<< endl;
    }
    catch(Botch::Apple & f)
    {
        cout << "inside catch2(Apple)" << endl;
    }
    catch(Botch::Fruit & f)
    {
        cout << "inside catch2(Fruit)" <<f.x<< endl;
    }
    
    catch(...)
    {
        cout << "inside catch2(...)" << endl;
    }

  return 0;
} ///:~

