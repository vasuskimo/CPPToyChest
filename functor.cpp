using namespace std;
#include <iostream>
#include <string>

class Mult
{
    int val_;
    public:
    
    Mult(int val): val_{val}{}
    
    int operator()(int val)
    {
        return val_ * val;
    }
};


int main()
{
    Mult m(10);
    cout << m(2) << endl;
    return 0;
}
