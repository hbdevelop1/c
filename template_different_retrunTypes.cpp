
//a normal class with a template member function that returns a different return type.
//the function returns the type ofthe argument.
//but for an int it must return a float


#include <iostream>       // std::cout
#include <functional>     // std::ref
using namespace std;


template <class T>
struct  returnType
{
    typedef T type;
};

template <>
struct  returnType <int>
{
    typedef float type;
};

class ReturnTypeSpecialization
{
public:
    template<class T>typename returnType<T>::type Item();
};


// Normally just return the template type
// When a float is specified, return an int
template<class T> typename returnType<T>::type ReturnTypeSpecialization::Item()
{ 
    typename returnType<T>::type v=35;
    return v;
}

//template<typename T> typename returnType<T>::type ReturnTypeSpecialization::Item() 

int main()
{
    ReturnTypeSpecialization r;
    cout << "r.Item<int>() =="<< std::showpoint<< r.Item<int>()<<endl;
    
    ReturnTypeSpecialization r1;
    cout << "r1.Item<float>() =="<< std::showpoint<<r1.Item<float>()<<endl;

    ReturnTypeSpecialization r2;
    cout << "r2.Item<chart>() =="<<r2.Item<char>()<<endl;
    
    return 0;
}