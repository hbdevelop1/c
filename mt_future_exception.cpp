// promise example
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

using namespace std;

mutex cout_mtx;
#define output(a)    \
{                       \
cout_mtx.lock();        \
cout << a <<endl;  \
cout_mtx.unlock();  \
}







class A
{
public:
    void f(int i, char c)
    {
        output("this is the child thread. and it is "<<this_thread::get_id()<<","<<i<<","<<c);
    }
    int operator()(int r)
    {
        output("this is the child thread. and it is "<<this_thread::get_id()<<","<<r);
        return r;
    }
};
void fct(int r){}

int main24()
{
    output("this is the parent thread, and it is "<<this_thread::get_id());

    A ai;
    thread t1(ai, 6); //copy of ai in a different thread + ai is a functor.
    thread t2(ref(ai), 7); //reference of ai in a different thread + ai is a functor.
    thread t3(move(ai), 8); //ai is moved. as is no longer valid in this thread.
    thread t4(A(), 9); //a temp A

    thread t5(&A::f, ai, 6, 'z'); //(copy of ai).f(6,'z');
    thread t6(&A::f, &ai, 6, 'z'); //ai.f(6,'z');

    thread t7([](int x){return x*x;}, 6); //a lamda
    thread t8(fct, 6);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();


    return 0;
}


void print_int (std::future<int>& value2print)
{
    output("print_int started ");

//    try
    {
        int x = value2print.get();
        output("value: " << x );
    }
    /*
    catch(std::future_error &e)
    {
        cout << "ixception code is :"<<e.code().message()<<endl;
    }
    catch(...)
    {
        cout << "an ixception happend"<<endl;
    }
    */
    //return 3;
}

int main23 ()
{
    int foo;
    std::reference_wrapper<int> wrap (foo);
    static_cast<int&>(wrap) = 10;
    wrap.get() += 10;
    int y = wrap;
    cout << y <<endl;
    return 0;

    std::promise<int> prom;                      // create promise

    std::future<int> value2print = prom.get_future();    // engagement with future

    //std::thread th1 (print_int, std::ref(fut));  // send future to new thread
    std::future<void> fu = std::async(launch::async, print_int, std::ref(value2print));

    output("before-sleeping for 3 seconds");

    this_thread::sleep_for(std::chrono::seconds(3));
prom.set_value(121);

    //th1.join();
    return 0;
}

int factorial(future<int> & f)
{
    int res = 1;
    int N = f.get();
    for(int i=N;i>1; i--)
        res *= i;
    output("child's result is "<<res);

    return res;
}

int main22()
{
    std::promise<int> p;                      // create promise
    std::future<int> f = p.get_future();    // engagement with future

    std::future<int> fu =std::async(std::launch::async, factorial, std::ref(f));

    output("before-sleeping for 3 seconds");

    this_thread::sleep_for(std::chrono::seconds(3));
    p.set_value(4);

    int res = fu.get();
    output("parent result is "<<res);
    //th1.join();
    return 0;
}
