#include <iostream>
using namespace std;
 
class Object
{
public:
	virtual void print(){}
};

class Point: public Object
{
private:
	void print(int u){}
};


int main()
{
	Point p;

	int y = 5;
	cout << "hoh" << y << endl;
}
