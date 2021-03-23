using namespace std;
#include <iostream>
class SmartPtr 
{ 
	int* ptr;
	
	public: 

	explicit SmartPtr(int* p = NULL) 
	{ 
		ptr = p; 
	} 

	~SmartPtr() 
	{ 
		cout << "Destructor called" << endl;
		delete (ptr); 
	} 

	// Overloading dereferencing operator 
	int& operator*() 
	{ 
		return *ptr; 
	} 
}; 

int main() 
{ 
	SmartPtr p(new int()); 
	*p = 20; 
	cout << *p << endl; 
	return 0; 
}
