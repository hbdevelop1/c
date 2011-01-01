
/*
create writer thread;
create reader threads;
readers get access to a shared read resource;
writer locks the resource;
readers lock the resource;
*/

/*
 todo
 -get a function to accept std::endl as an argument. use output below or modern_template_variadic.cpp



 * */


#include<thread>
#include<mutex>
#include<iostream>
using namespace std;

void writing();
void reading();
mutex mtx;

template <class type_of_arg1>
void output(type_of_arg1 a1)
{
    cout << a1;
}

template <class type_of_arg1, typename... type_of_remaining_args>
void output(type_of_arg1 a1, type_of_remaining_args... args)
{
    cout << a1;
    output(args...);
}
/*
ostream & operator<<(ostream & o, )
{
    lock_guard(mtx);
    o << arg;
    return o;
}
class A:public ostream
{
public:
    ostream & operator<<(ostream & o, )
    {
        lock_guard(mtx);
        o << arg;
        return o;
    }
}
*/
int main()
{
    const int number_of_readers = 5;
    //create writer thread;
    thread w(writing);
    thread r[number_of_readers];

    for(int i=0; i<number_of_readers; ++i)
        r[i]=thread(reading);




    for(int i=0; i<number_of_readers; ++i)
        r[i].join();
    w.join();

    return 0;
}

void writing()
{
    int i=10;
    while(--i)
    {
        //cout<<"writer thread "<<std::this_thread::get_id()<<endl;
        unique_lock<mutex> u(mtx);
        output("writer thread ",std::this_thread::get_id(),"\n");
        u.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void reading()
{
    int i=10;
    while(--i)
    {
        //cout<<"reader thread "<<std::this_thread::get_id()<<endl;
        unique_lock<mutex> u(mtx);
        output("reader thread ",std::this_thread::get_id(),"\n");
        u.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}
