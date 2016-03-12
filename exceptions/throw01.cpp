//throw; 
//in a catch bloc it will rethrow the same exception object to the upper level

//throw; 
//inside try or in the code calls function set for termination

#include <exception>
#include <iostream>
#include <memory>

using namespace std;
 
void terminator() {
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
  class Fruit {};
  void f()// throw()
  {
	someClass sc;
    cout << "Botch::f()" << endl;
    throw Fruit();
	sc.f();
  }
  ~Botch() {
//	  throw 'c'; 
  }
};
 
int main() 
{
	shared_ptr<char> p (new char[0xFFFF0000]);
	//throw;
	try
	{
	    Botch b;
	    throw;
		try 
		{
			b.f();
		} 
		catch(...) 
		{
			cout << "inside catch1(...)" << endl;
			throw;
		}
	}
	catch(Botch::Fruit & f) 
	{
		cout << "inside catch2(...)" << endl;
	}

  return 0;
} ///:~

