/*
create a template class
create a friend class for it
create a friend function for it
make sure the friends are friends to all the instantiation classes 
overload the friend function for a specific type. FAILED
*/


#include <assert.h>
#include <iostream>
#include <iterator>
using namespace std;

template <class T, int n> class stack1;
template <class T, int n> ostream & operator<<(ostream & os, const stack1<T,n> & s);

template <class T, int n=10>
class stack1
{
	int size;
	T arr[n];
public:
	stack1(){size=0;}
	bool push(T e);
//	void push(T && e);
	T pop();
	friend ostream & operator<< <>(ostream & os, const stack1<T,n> & s);
	//friend ostream & operator<< <float, int n>(ostream & os, const stack1<float,n> & s);
    
    void print() {cout << "print()"<<endl;}
    void print() {cout << "print()"<<endl;}
};

template<class T, int n> 
ostream & operator<<(ostream & os, const stack1<T,n> & s)
{
		copy(s.arr, s.arr+s.size, ostream_iterator<T>(os));
		return os;
}
/*
template<> 
ostream & operator<< <float, int n>(ostream & os, const stack1<float,n> & s)
{
		//copy(s.arr, s.arr+s.size, ostream_iterator<T>(os));
		cout <<std::showpoint;
		for(float e:s.arr)
			cout <<e<<',';
		return os;
}
 */
template<class T, int n> bool stack1<T, n>::push(T e)
{
	if(size>=n)
	{
		return false;
	}
	
	arr[size]=e;
	++size;
	
	return true;
}

template<class T, int n> T stack1<T, n>::pop()
{
	if(size<=0)
	{
		assert(0);
	}
	
	--size;
	T e = arr[size];
	
	return e;
}

int main()
{
	{
	stack1<int> si;
	si.push(19);
	si.push(10);
	si.push(9);

	//cout << si.pop() << "1, "<<si.pop() << "2, "<<si.pop()<<endl;
	cout << si << endl;
	}
	{
	stack1<float> si;
	si.push(19.1f);
	si.push(10.000034);
	si.push(9.8);

	//cout << si.pop() << "1, "<<si.pop() << "2, "<<si.pop()<<endl;
	cout << si << endl;
	float t=10.000034f;
	cout <<std::showpoint<<t<<endl;
	}
	return 0;
}