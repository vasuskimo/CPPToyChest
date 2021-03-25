using namespace std;
#include <iostream>
#include <memory>

//unique_ptr can be moved and not copied
//shared_ptr can be copied and uses a ref. count.
// weak_ptr simply has an association relationship.
class Entity
{
	public: 
	Entity()
	{
		cout << "Constructor called\n";
	}
	~Entity()
	{
		cout << "Destructor called\n";
	}
};

int main() 
{
	{
		unique_ptr <Entity> up = make_unique<Entity>();
		unique_ptr <Entity> up2 = move(up);
	}
	cout << "hello world\n";
	return 0;
}
