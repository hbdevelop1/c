#include <iostream>
using namespace std;

 auto mean(const Sequence & s)
 {
 	auto m=0.0;

 	if (!s.size())
 		return m;

 	for(auto e:s)
 	{
 		m+=e;
 	}
 	return n/s.size();
 } 

int main()
{
	auto array[]={2,3,4};
	cout << "the mean is " << mean(array) << endl;
}

