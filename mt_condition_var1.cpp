// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

using namespace std;

std::mutex mtx;
std::condition_variable cv;


#define TCOUNT 10	
#define WATCH_COUNT 12	
int count = 0;

void watch_count(int idp)	
{	
	std::unique_lock<std::mutex> lck(mtx);
	while (count <= WATCH_COUNT) 
	{	
		cout << "watch_count(): Thread " << idp << " might block and Count is " << count << endl;	
		cv.wait(lck);	
		cout << "watch_count(): Thread " << idp << " awoke and Count is " << count << endl;	
	}	
	cout << "watch_count(): Thread " << idp << " ended"<<endl;
}

void inc_count(int idp)	
{	
	for (int i =0; i < TCOUNT; i++) 
	{	
		//mtx.lock();
		std::unique_lock<std::mutex> lck(mtx);	
		count++;	
		cout << "inc_count(): Thread "<< idp << ", old count " << count - 1<< ", new count "<< count << endl;	
		if (count == WATCH_COUNT)
		   cv.notify_all();	
		//mtx.unlock();	
	}	
	cout << "inc_count(): Thread "<< idp << " ended" << endl;	
}

int main ()
{
	enum
	{
		incrementer_1,
		incrementer_2,
		watcher,
		max
	};

	std::thread threads[max];

	threads[incrementer_1] 	= std::thread(inc_count,incrementer_1);
	threads[incrementer_2] 	= std::thread(inc_count,incrementer_2);

	threads[watcher] 		= std::thread(watch_count,watcher);

	for (auto& th : threads) th.join();

	return 0;
}
