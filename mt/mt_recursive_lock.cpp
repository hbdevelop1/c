#include <iostream>
#include <thread>
#include <atomic>         
#include <mutex>         
using namespace std;

std::atomic<int> global_counter (0);

void increase_global (int n) { for (int i=0; i<n; ++i) ++global_counter; }

mutex mtx;

void f(int & i)
{
	mtx.lock();
	cout << std::this_thread::get_id();
	if(i <= 0)
	{
		cout << "zero or below reached" << endl;
	}
	else if(i>0)
	{
		cout << "calling f" << endl;
		f(--i);
	}
	mtx.unlock();
} 
    int main()
    {
		

		int r=4;
		int r1=r;
		thread th (f, std::ref(r)); //does it start immediately		
//f(r);

		th.join();

		//std::thread t1(increase_global,1000);

		cout << "we were at " << r1 << ". and we've reached " << r << endl;
      return 0;
    }
