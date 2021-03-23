#include <iostream>
#include <thread>
using namespace std;

thread_local int i=1000;

void threadfunc(int val)
{
    i = val;
    cout << i << endl;
}

int main()
{
    std::thread t1(threadfunc,25);
    std::thread t2(threadfunc,35);
    std::thread t3(threadfunc,45);

    t1.join();
    t2.join();
    t3.join();
    cout<<i<<std::endl;
}
