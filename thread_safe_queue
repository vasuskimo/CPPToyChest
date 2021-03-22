using namespace std;
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <string>

template <typename T>
class thread_safe_queue
{
	public:
  
		T pop()
		{
			unique_lock <mutex> unique_lock_(mutex_);
			// while(queue_.empty()) without predicate
			// condition_variable_.wait(unique_lock_);
			condition_variable_.wait(unique_lock_,[this]{return !queue_.empty();});
			auto item = queue_.front();
			queue_.pop();
			return item;
		}
		
		void push(const T& item)
		{
			unique_lock <mutex> unique_lock_(mutex_);
			queue_.push(item);
			condition_variable_.notify_one();
		}
    
	private:
		queue <T> queue_;
		mutex mutex_;
		condition_variable condition_variable_;
	
};


int main()
{
	thread_safe_queue <string> tsq;
	tsq.push("hello");
	tsq.push("world");
	cout << tsq.pop() << endl;
	cout << tsq.pop() << endl;
}
