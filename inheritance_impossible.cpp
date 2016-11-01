#include <iostream>
#include <vector>
using namespace std;
 
template <typename T> 
class MakeSealed 
{
	friend T;
private:
	MakeSealed() {}
	~MakeSealed() {}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2> 
{
public:
	SealedClass2() {}
	~SealedClass2() {}
};
class Derived:public SealedClass2
{
	
};
int main()
{
	SealedClass2 sc;
	Derived d; 
	
  return 0;
}
