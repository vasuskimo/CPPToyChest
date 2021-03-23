using namespace std;
#include <iostream>
#include <string>
#include <atomic>

class AtomicCounter
{
    atomic <int> value;
    
    public: 
    
    AtomicCounter(int val)
    {
        value.store(val);
    }
    void increment()
    {
        value.exchange(++value);
    }
    
    void decrement()
    {
        value.exchange(--value);
    }
    
    int get()
    {
        return value.load();
    }
    
};

int main()
{
    AtomicCounter ctr(30);
    ctr.increment();
    cout << ctr.get() << endl;
    ctr.decrement();
    cout << ctr.get() << endl;
}
