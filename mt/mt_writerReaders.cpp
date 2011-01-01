
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
#include<fstream>

using namespace std;


void writing(mutex &);
void reading(mutex &);

const int g_chunck = 200;
char shared_buffer[g_chunck];


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

int main()
{
    mutex mtx_output;

    const int number_of_readers = 5;
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

    while(size_still_to_write>0)
    {
        int chunck = std::min(g_chunck, size_still_to_write);

        f.read(shared_buffer, chunck);

        if(size_still_to_write == chunck)
        { //the last small chunck should be null terminated, otherwise we see the left over from the previous content
            shared_buffer[size_still_to_write]=0;
        }

        size_still_to_write -= chunck;


        //cout<<"writer thread "<<std::this_thread::get_id()<<endl;
        unique_lock<mutex> u(mtx);
        //output("writer thread ",std::this_thread::get_id(),"\n");
        //output(shared_buffer);
        cout << shared_buffer;
        u.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void reading(mutex &mtx)
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
