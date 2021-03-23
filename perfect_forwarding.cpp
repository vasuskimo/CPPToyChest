#include <iostream>
using namespace std;

// perfect forwarding is demonstrated
// if you are forwarding a value category of type rvalue reference
// std::forward() preserves the value category

class C{};

void f(C& c)
{
	cout << "f C& called\n";
}

void f(C&& c)
{
	cout << "f C&& called\n";
}

template <typename T>
void wrap(T& t)
{
	f(t);
}

template <typename T>
void wrap(T&& t)
{
	f(std::forward <T> (t));
}

int main() 
{
	C c;
	f(c);
	f(C());
	wrap(c);
	wrap(C());
	return 0;
}
