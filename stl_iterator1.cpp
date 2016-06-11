//output instance of my A class into a string using << operator
//and failed attempt to output instance of my A class followed by a line return. like the manipulator endl for cout


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

class AA
{
	
};

class A:public AA
{
public:
		int y;
//private:	
		int z;
public:
		int Valy() const { return y;}
		int Valz() const { return z;}
};

ostream & operator<<(ostream & os, A  a)
{
	os << a.Valy()<<"."<<a.Valz();
	return os;
}

ostream & operator<<(ostream & os, AA  a)
{
	os << "AA";
	os << endl;
	return os;
}

/*
template<>
class ostream_iterator<A>//: public ostream_iterator<int>
{
	
};
*/

	
int main()
{
	{
		ostringstream s;
		ostream_iterator<AA> it(s);
		//A a{3,6};
		A a;
		a.y=3;
		a.z=6;
		s<<a;
		*it=a;
		cout << s.str().c_str()<<endl;
		
		return 0;
	

		AA a_endl;
		++it;
		*it=a_endl;
		//*it='\n';
		s<<a;
		cout << s.str().c_str()<<endl;
	}
	
	return 0;
}
