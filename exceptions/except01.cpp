

#include <exception>
#include <iostream>
using namespace std;
 
void terminator() {
  cout << "I'll be back!" << endl;
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
	char *p = new char[0xFFFF0000];
    Botch b;
	try 
	{
		b.f();
	} 
	catch(...) 
	{
		cout << "inside catch(...)" << endl;
	}

  return 0;
} ///:~
