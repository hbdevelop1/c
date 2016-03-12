/*
when coping an object in a function that receives only a ref to its base class
does slicing happen ?
<- it is forbidden. compiler does not insert cc code or shuts up. it complains. 
the reason is the ref to the base class could be of any derived class
*/
#include <iostream>
using namespace std;
 
class Object
{
public:
	Object() 
	{
		//cout <<"Object default\n";
	}
	Object(const Object& o) 
	{
		//cout <<"Object CC\n";
	}
	virtual void print() const {cout <<"this is Object\n";}
};

class Point: public Object
{
public:
	Point() 
	{
		//cout <<"Point default\n";
	}
	Point(const Point& o) 
	{
		//cout <<"Point CC\n";
	}
	void print() const {cout <<"this is Point\n";}

};

class Shape: public Object
{
public:
	Shape() 
	{
		//cout <<"Shape default\n";
	}
	Shape(const Shape& o) 
	{
		//cout <<"Shape CC\n";
	}
	void print() const {cout <<"this is Shape\n";}

};

void cc(const Object & o)
{
//o.print();
	Point o1=o; 	
	o1.print();

	//Object o2=o; 	 	o2.print();
}

int main()
{
	Point p;
	cc(p);
return 0;
	//Object &o=p; 	Point o1
	//=o
	;
	//o1.print();

}
