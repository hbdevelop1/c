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

void print_int (std::future<int>& fut)
{
    output("print_int started ");

    int x = fut.get();

    output("value: " << x );
}

int main ()
{
    std::promise<int> prom;                      // create promise

    std::future<int> fut = prom.get_future();    // engagement with future

    std::thread th1 (print_int, std::ref(fut));  // send future to new thread

    output("before-sleeping for 3 seconds");

    this_thread::sleep_for(std::chrono::seconds(3));
    prom.set_value (10);                         // fulfill promise
                                       // (synchronizes with getting the future)

    output("after-sleeping for 3 seconds");


    this_thread::sleep_for(std::chrono::seconds(3));
    th1.join();
    return 0;
}
