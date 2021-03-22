using namespace std;
#include <iostream>
#include <map>
#include <condition_variable>
#include <mutex>

template <typename TK, typename TV>
class thread_safe_hashmap
{
	public:
	
	void push(const TK& key, const TV& value)
	{
		lock_guard <mutex> unique_lock_(mutex_);
		map_.insert(pair<string,string>(key,value));
	}

	TK pop(const TK& key)
	{
		lock_guard <mutex> unique_lock_(mutex_);
		return map_[key];
	}
	
	private:
	map <string,string> map_;
	mutex mutex_;
	
};

int main() 
{
	thread_safe_hashmap <string, string> tsh;
	tsh.push("usa", "United states of america");
	tsh.push("ca", "Canada");
	cout << tsh.pop("ca") << endl;
	cout << tsh.pop("usa") << endl;
	return 0;
}
