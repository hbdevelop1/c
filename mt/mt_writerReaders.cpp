
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
 -writer waits for reader threads to get ready. but waht ifthe writer just dumps more than one chunck before readers know it
 there should be some variable to stop the writer from witing any further until all readers have read. solution:cv


 * */


#include<thread>
#include<mutex>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <sstream>
#include <atomic>

#include<condition_variable>

using namespace std;


void writing(mutex &);
void reading(mutex &);

const int g_chunck_max = 200;
char shared_buffer[g_chunck_max];
int g_chunck_current;

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
    lock_guard(mtx_output);
    o << arg;
    return o;
}
class A:public ostream
{
public:
    ostream & operator<<(ostream & o, )
    {
        lock_guard(mtx_output);
        o << arg;
        return o;
    }
}
*/

condition_variable g_cv;
condition_variable g_cv2;
mutex g_mtx;
int number_of_active_readers = 0;
bool writer_is_writing = true;
volatile atomic<bool> file_completed(false);
const int number_of_readers = 5;
int number_of_readers_to_init = number_of_readers;

int main()
{
    const int number_of_readers = 5;

    mutex mtx_output;

    //create writer thread;
    thread w(writing, ref(mtx_output));
    thread r[number_of_readers];

    for(int i=0; i<number_of_readers; ++i)
        r[i]=thread(reading, ref(mtx_output));




    for(int i=0; i<number_of_readers; ++i)
        r[i].join();
    w.join();

    return 0;
}

void writing(mutex &mtx)
{
    ifstream f("mt/mt_writerReaders_data", ifstream::binary);

    if(!f.good())
    {
        unique_lock<mutex> u(mtx);
        output("problem in file\n");
        u.unlock();
        return;
    }
    f.seekg(0, f.end);
    uint sizeoffile=f.tellg();
    f.seekg(0, f.beg);

    signed int size_still_to_write=sizeoffile;

    unique_lock<mutex> lck(g_mtx);
    while(number_of_readers_to_init) //wait for readers to be ready for reading data
    {
        g_cv2.wait(lck);
    }
    lck.unlock();

    output("writer is starting\n");

    while(size_still_to_write>0)
    {
        g_chunck_current = std::min(g_chunck_max, size_still_to_write);

        unique_lock<mutex> lck(g_mtx);
        while(number_of_active_readers>0)
        {
            output("writer is going to sleep\n");
            g_cv.wait(lck);
        }

        writer_is_writing=true;
        lck.unlock();


        f.read(shared_buffer, g_chunck_current);

        if(size_still_to_write == g_chunck_current)
        { //the last small chunck should be null terminated, otherwise we see the left over from the previous content
            shared_buffer[size_still_to_write]=0;
        }

        lck.lock();
        writer_is_writing=false;
        output("writer is notifying everybody\n");
        g_cv.notify_all();
        lck.unlock();


        size_still_to_write -= g_chunck_current;

/*
        //cout<<"writer thread "<<std::this_thread::get_id()<<endl;
        unique_lock<mutex> u(mtx);
        //output("writer thread ",std::this_thread::get_id(),"\n");
        //output(shared_buffer);
        //cout << shared_buffer;
        u.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(5));
        */
    }

    file_completed=true;
}

void reading(mutex &mtx)
{
    stringstream sfilename;//in out by default
    sfilename
            <<"mt/temp/mt_writerReaders_data_"
           <<std::this_thread::get_id();

    //char filename[100]; sfilename>>filename; //can;t output to a string object
    string filename=sfilename.str(); //doesn't suppor >>string

    unique_lock<mutex> u(mtx);
    cout<<filename<<endl;
    u.unlock();

    ofstream f(filename, ofstream::binary|ofstream::trunc);

/*
    char buffer[]="this is a text";
    f.write(buffer,strlen(buffer));
    f.close();
*/

    unique_lock<mutex> lck(g_mtx);
    --number_of_readers_to_init;
    g_cv2.notify_one();//wake up teh writer to check if number_of_readers_to_init reached 0
    lck.unlock();

    while(file_completed==false)
    {
        unique_lock<mutex> lck(g_mtx);
        while(writer_is_writing)
        {
            output("reader ", std::this_thread::get_id()," is going to sleep\n");
            g_cv2.wait(lck);
        }

        ++number_of_active_readers;
        lck.unlock();


        f.write(shared_buffer,g_chunck_current);


        lck.lock();
        --number_of_active_readers;
        if(number_of_active_readers==0)
        {
            output("reader ", std::this_thread::get_id()," is notifying writer\n");
            g_cv.notify_one();
        }
        lck.unlock();
/*
        //cout<<"reader thread "<<std::this_thread::get_id()<<endl;
        unique_lock<mutex> u(mtx);
        //output("reader thread ",std::this_thread::get_id(),"\n");
        u.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(5));
        */
    }
}
